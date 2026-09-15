/**
@Author: MrKeanu
@Date: 2026-07-12
@Description: Refactored solution registry framework with lazy loading.
             - BaseSolution: abstract base with pure virtual test()
             - FntApp: singleton CLI manager, stores factory functions keyed by name
             - FNT_REGISTER(cls_name): registers a factory lambda that creates cls_name on demand
@History: 2025-09-08 - Initial implementation registration framework.
*/
#pragma once

#include <map>
#include <string>
#include <stdexcept>
#include <functional>
#include <iostream>
using namespace std;

namespace fnt {

// ============================================================
// BaseSolution — 所有题解必须继承此类
// ============================================================
class BaseSolution {
public:
    virtual ~BaseSolution() = default;
    virtual void test() = 0;
};

// ============================================================
// FntApp — 单例 CLI 应用管理器（Meyer's Singleton）
//         注册表存储工厂函数，Run 时按需懒加载创建实例
// ============================================================
class FntApp {
public:
    using Factory = function<BaseSolution*()>;

    static FntApp& Instance() {
        static FntApp app;
        return app;
    }

    // 注册工厂函数，若 key 重复则抛出 runtime_error
    void Register(const string& key, Factory factory) {
        if (registry_.find(key) != registry_.end()) {
            throw runtime_error("FntApp: duplicate solution key \"" + key + "\"");
        }
        registry_[key] = factory;
    }

    void Unregister(const string& name) {
        if (registry_.empty() || registry_.find(name) == registry_.end()) {
            cout << "------------- Info: Solution " << name << ".cpp not found! -------------" << endl;
            return;
        }
        registry_.erase(name);
        cout << "------------- Info: Solution " << name << ".cpp unregistered! -------------" << endl;
    }

    // 懒加载：根据 name 调用工厂创建实例 → test() → 销毁
    void Execute(const string& name) {
        auto it = registry_.find(name);
        if (it == registry_.end()) {
            cout << "------------- Error: Solution " << name << ".cpp not found! -------------" << endl;
            return;
        }
        cout << "------------- Info: Running solution: " << name << ".cpp -------------" << endl;
        BaseSolution* sln = it->second();   // 工厂创建
        sln->test();
        delete sln;                          // 用完销毁
        cout << "------------- Info: Solution " << name << ".cpp finished! -------------" << endl;
    }

    void RunAll() {
        for (auto& pair : registry_) {
            cout << "------------- Info: Running solution: " << pair.first << ".cpp -------------" << endl;
            BaseSolution* sln = pair.second();
            sln->test();
            delete sln;
            cout << "------------- Info: Solution " << pair.first << ".cpp finished! -------------" << endl;
        }
    }

    void Print() const {
        cout << "------------- Info: Available Solutions: -------------" << endl;
        for (auto& pair : registry_) {
            cout << pair.first << ".cpp" << endl;
        }
    }

    void Clear() {
        registry_.clear();
        cout << "------------- Info: Solutions cleared! -------------" << endl;
    }

    void Run();

private:
    FntApp() = default;
    FntApp(const FntApp&) = delete;
    FntApp& operator=(const FntApp&) = delete;

    map<string, Factory> registry_;
};

} // namespace fnt

// ============================================================
// FNT_SOLUTION_KEY(sln) / FNT_REGISTER(cls_name) — 题解注册
// 用法：
//   class Solution19 : public BaseSolution {
//   public:
//       FNT_SOLUTION_KEY("19")                      // 类内声明 key（public 区域）
//
//       void test() override { ... }                // 题解实现与测试
//   };
//
//   FNT_REGISTER(Solution19);                       // 类外注册工厂（文件/命名空间作用域）
//
// 注册表只存工厂函数（lambda），实例在 FntApp::Execute / RunAll 时按需 new，
// 用完立即 delete，实现「懒加载」。
// ============================================================

// 每个派生类需在 public 区域声明此宏，提供静态 key 字符串
#define FNT_SOLUTION_KEY(sln) \
    static const string& Key() { static string k = sln; return k; }

// FNT_REGISTER(cls_name) — 在类外注册工厂函数
#define FNT_REGISTER(cls_name)                                                     \
    namespace {                                                                    \
        struct FntRegistrar_##cls_name {                                           \
            FntRegistrar_##cls_name() {                                            \
                fnt::FntApp::Instance().Register(cls_name::Key(),                   \
                    []() -> fnt::BaseSolution* { return new cls_name(); });         \
            }                                                                      \
        };                                                                         \
        const FntRegistrar_##cls_name fntRegistrar_##cls_name{};                    \
    }
