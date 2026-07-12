# fnt — Foundation Tool Library

## 概述

`fnt` 目录包含 C++ 算法刷题项目的基础工具库，提供数据结构定义、工具函数及题解注册/执行框架。

### 文件说明

| 文件 | 说明 |
|------|------|
| `fnt_solution.h` / `fnt_solution.cpp` | 题解注册与交互式执行框架。提供 `FNT_REGISTER` / `FNT_REGISTER_SOLUTION` 宏用于自动注册题解，`Run()` 进入命令行交互环境。 |
| `fnt_template.h` / `fnt_template.cpp` | 常用数据结构与工具函数模板，包括：<br>• `ListNode` — 单向链表节点及其创建(`createList`)、打印(`printList`)、释放(`freeList`)<br>• `TreeNode` — 二叉树节点及其层序构建(`createTree`)、打印(`printTree`)、前中后序遍历<br>• `printVector1D / printVector2D` — 一维/二维数组打印<br>• `GreaterCmp` — 自定义比较器（大顶堆用）<br>• `Bool2Str`、`count_one`、`longestCommonPrefix` 等辅助函数 |

---

## 使用方式

### 1. 注册题解

在 `algorithm/src/` 下编写题解 `.cpp` 文件，使用 `FNT_REGISTER` 宏注册：

```cpp
// algorithm/src/1.cpp — Two Sum
#include "fnt_solution.h"
#include <vector>
using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ... 题解实现
    }

    void test() {
        vector<int> nums = {2, 7, 11, 15};
        auto res = twoSum(nums, 9);
        for (int x : res) cout << x << " ";
        cout << endl;
    }
};

FNT_REGISTER(1);  // 注册题号 1，宏自动生成 Solution1 实例并调用 test()
```

**宏说明：**

| 宏 | 用法 | 适用场景 |
|----|------|----------|
| `FNT_REGISTER(n)` | 类名必须为 `Solution{n}`，如 `Solution25` | 标准命名，推荐使用 |
| `FNT_REGISTER_SOLUTION(ClassName, n)` | 可自定义类名，如 `FNT_REGISTER_SOLUTION(MyBFS, 200)` | 类名不等于 `Solution{n}` 时使用 |

> 宏利用静态全局对象的构造函数在 `main()` 执行前自动完成注册，无需手动调用任何初始化函数。

### 2. 编译

将所有源文件一起编译：

```bash
cd CPP
g++ -std=c++20 -I. main.cpp fnt/*.cpp algorithm/src/*.cpp -o main
```

或使用 CMake 等构建系统，确保 include path 包含 `CPP/` 根目录。

### 3. 运行

```bash
./main
```

启动后将看到欢迎界面，随后进入交互式命令行：

```
 ________________________________________________________
|                                                        |
|    _   _      _ _         _    _            _     _    |
|   | | | |    | | |       | |  | |          | |   | |   |
|   | |_| | ___| | | ___   | |  | | ___  _ __| | __| |   |
|   |  _  |/ _ \ | |/ _ \  | |/\| |/ _ \| '__| |/ _` |   |
|   | | | |  __/ | | (_) | \  /\  / (_) | |  | | (_| |   |
|   \_| |_/\___|_|_|\___/   \/  \/ \___/|_|  |_|\__,_|   |
|________________________________________________________|

------------- Welcome, adventurer!-------------
Enter a command (run, runall, print, erase, clear, exit):
```

### 4. 交互命令

| 命令 | 功能 |
|------|------|
| `run` | 进入子模式，输入题号（如 `25`）即可执行对应题解的 `test()` 方法；输入 `exit` 返回主菜单 |
| `runall` | 依次执行所有已注册题解 |
| `print` | 列出所有已注册的题解名称（格式为 `题号.cpp`） |
| `erase` | 进入子模式，输入题号从注册表中移除对应题解；输入 `exit` 返回 |
| `clear` | 清空所有已注册题解 |
| `exit` | 退出程序 |

**示例交互：**

```
Enter a command (run, runall, print, erase, clear, exit): print
------------- Info: Available Solutions: -------------
1.cpp
25.cpp
200.cpp
...

Enter a command (run, runall, print, erase, clear, exit): run
please enter the name of the solution to run (or enter 'exit' to exit): 25
------------- Info: Running solution: 25.cpp -------------
1 2 3 4 5
------------- Info: Solution 25.cpp finished! -------------
please enter the name of the solution to run (or enter 'exit' to exit): exit

Enter a command (run, runall, print, erase, clear, exit): exit
------------- Farewell, adventurer!-------------
```

---

## 项目入口

`main.cpp` 位于 `CPP/` 根目录（不在 `fnt/` 内）：

```
CPP/
├── main.cpp              # 项目入口，调用 fnt::Run()
├── fnt/
│   ├── fnt_solution.h / .cpp
│   └── fnt_template.h / .cpp
└── algorithm/
    ├── inc/   # 算法模板 .hpp
    └── src/   # 题解 .cpp