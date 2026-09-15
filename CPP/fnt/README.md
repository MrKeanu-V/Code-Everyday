# fnt — Foundation Tool Library

## 概述

`fnt` 目录包含 C++ 算法刷题项目的基础工具库，提供数据结构定义、工具函数及题解注册/执行框架。

### 文件说明

| 文件 | 说明 |
|------|------|
| `fnt_solution.h` / `fnt_solution.cpp` | 题解注册与交互式执行框架。核心类：<br>• `BaseSolution` — 抽象基类，提供 `virtual void test() = 0`<br>• `FntApp` — 单例管理器，维护工厂注册表，按需懒加载创建题解实例<br>• `FNT_REGISTER(cls_name)` — 工厂注册宏，在 `main()` 前自动完成 |
| `fnt_utils.h` / `fnt_utils.cpp` | 常用数据结构和工具函数：<br>• `ListNode` — 单向链表节点及其创建(`createList`)、打印(`printList`)、释放(`freeList`)<br>• `TreeNode` — 二叉树节点及其层序构建(`createTree`)、打印(`printTree`)、前中后序遍历<br>• `printVector1D / printVector2D` — 一维/二维数组打印<br>• `GreaterCmp` — 自定义比较器（大顶堆用）<br>• `Bool2Str`、`count_one`、`longestCommonPrefix` 等辅助函数 |

---

## 架构设计

```
FNT_REGISTER(Solution19)
    │
    ▼  静态全局对象构造 → FntApp::Instance().Register("19", factory)
    │                     registry_["19"] = []{ return new Solution19(); }
    │
main() → FntApp::Instance().Run()
    │
    ├── print  → 遍历 registry_，打印所有 key
    ├── run    → 输入 "19" → factory() → new Solution19 → test() → delete
    ├── runall → 遍历全部，逐个 factory() → test() → delete
    └── exit
```

**懒加载优势：** 注册表仅存储工厂函数（轻量 lambda），实际 `Solution` 实例在运行时按需创建、用完立即销毁，无静态全局实例，避免静态初始化顺序问题，内存占用极小。

---

## 使用方式

### 1. 编写题解

在 `algorithm/src/` 下编写题解 `.cpp` 文件，继承 `BaseSolution` 并使用 `FNT_SOLUTION_KEY` / `FNT_REGISTER` 宏：

```cpp
// algorithm/src/1.cpp — Two Sum
#include "fnt/fnt_utils.h"
#include "fnt/fnt_solution.h"
#include <vector>
using namespace std;
using namespace fnt;

class Solution1 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("1")  // 声明 key = "1"，用于注册和命令行查找

    vector<int> twoSum(vector<int>& nums, int target) {
        // ... 题解实现
        return {};
    }

    void test() override {
        vector<int> nums = {2, 7, 11, 15};
        auto res = twoSum(nums, 9);
        for (int x : res) cout << x << " ";
        cout << endl;
    }
};

FNT_REGISTER(Solution1);
```

**关键步骤：**
1. 类名为 `Solution` + 题号（如 `Solution1`、`Solution25`）
2. 必须 `public` 继承 `BaseSolution`
3. 在 `public` 区域使用 `FNT_SOLUTION_KEY("题号")` 声明 key
4. 实现 `void test() override`
5. 文件末尾调用 `FNT_REGISTER(Solution1)`（传入类名）

### 2. 编译

由 CMake 统一管理：`fnt` 被编成静态库，再被题解 target 链接（顶层项目 = `CPP/CMakeLists.txt`）：

```bash
cd CPP
cmake --preset gcc16                            # 配置
cmake --build --preset gcc16 --target fnt       # 只编译框架库
cmake --build --preset gcc16                    # 编译全部 -> build/gcc16/solutions
```

`fnt` 以 `PUBLIC` 方式导出头文件搜索路径，所以链接它的题解可以直接写
`#include "fnt/fnt_utils.h"`，无需再手写 `-I`：

```cmake
add_library(fnt STATIC fnt/fnt_utils.cpp fnt/fnt_solution.cpp)
target_include_directories(fnt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})   # 即 CPP/
```

### 3. 运行

```bash
./build/gcc16/solutions        # 按提示输入题号
```


---

## 交互命令

| 命令 | 功能 |
|------|------|
| `run` | 进入子模式，输入题号（如 `1`）→ 工厂创建实例 → `test()` → 销毁 |
| `runall` | 依次执行所有已注册题解（每个一次性创建→执行→销毁） |
| `print` | 列出所有已注册的题号 |
| `erase` | 进入子模式，输入题号从注册表中移除 |
| `clear` | 清空所有已注册题解 |
| `exit` | 退出程序 |

---

## 项目入口

`main.cpp` 位于 `CPP/` 根目录：

```cpp
#include "fnt/fnt_solution.h"
using namespace fnt;

int main() {
    FntApp::Instance().Run();
    return 0;
}
```
