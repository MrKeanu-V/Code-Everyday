# algorithm — 算法题解

## 概述

`algorithm` 目录存放 LeetCode、牛客网等平台的算法题解代码，按照标准 C++ 项目结构组织。

## 目录结构

```
algorithm/
├── inc/                          # 头文件 —— 算法模板
│   ├── 0_Template_BinarySearch.hpp    # 二分查找模板
│   ├── 0_Template_DynamicProgram.hpp  # 动态规划模板（含 0/1 背包）
│   ├── 0_Template_Grid.hpp            # 网格图 BFS/DFS 模板
│   ├── 0_Template_UnionFind.hpp       # 并查集模板
│   └── ...
└── src/                          # 题解实现（209 个 .cpp 文件）
    ├── 3.cpp                     # Leetcode 3. Longest Substring Without Repeating Characters
    ├── 5.cpp                     # Leetcode 5. Longest Palindromic Substring
    ├── 10.01.cpp                 # Leetcode 10.01. Sorted Merge LCCI
    └── ...
```

## 模板说明

`inc/` 目录下以 `0_Template_` 前缀命名的 `.hpp` 文件为常用算法模板，以 header-only 方式提供，可直接 `#include` 使用：

| 模板文件 | 命名空间 | 内容 |
|----------|----------|------|
| `0_Template_BinarySearch.hpp` | `BinarySearch` | 二分查找三种写法，STL `lower_bound`/`upper_bound` 示例 |
| `0_Template_DynamicProgram.hpp` | `DynamicProgram` | 动态规划分类概览，0/1 背包及多维背包模板实现 |
| `0_Template_Grid.hpp` | `GridTemplate` | 网格图类，包含 BFS/DFS 遍历 |
| `0_Template_UnionFind.hpp` | `UnionFindTemplate` | 并查集（路径压缩），支持 find / unite / count |
| `0_Template_Vector.hpp` | `STLTemplate` | C++ STL 常用容器操作速查 |

## 题解文件格式

每个题解文件遵循统一的 `BaseSolution` 派生类格式，示例参见 `3.cpp`：

```cpp
#include "fnt_utils.h"
#include "fnt_solution.h"
using namespace std;
using namespace fnt;

class Solution3 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("3")
    // 算法实现 ...
    void test() override {
        // 测试用例 ...
    }
};

FNT_REGISTER(Solution3);
```

## 编译与运行

题解源文件依赖 `fnt/` 基础框架，由 `CPP/main.cpp` 统一调度运行。

```bash
cd CPP
g++ -std=c++20 -I. main.cpp fnt/*.cpp algorithm/src/*.cpp -o main
./main
```

## 题目来源

- **LeetCode**：主要来源，覆盖 Easy / Medium / Hard
- **牛客网 / LCCI**：如 `10.01.cpp`（Sorted Merge LCCI）
- **LCR**：如 `052.cpp`、`068.cpp`

## 题解覆盖范围

共 209 道题解，覆盖以下类别：

- **数组/字符串**：双指针、滑动窗口、前缀和
- **链表**：反转、合并、环检测、排序
- **二叉树**：遍历、构建、搜索、路径问题
- **动态规划**：线性 DP、区间 DP、背包、矩阵 DP、树形 DP、状态压缩
- **图论**：DFS、BFS、并查集、拓扑排序、最短路径
- **贪心**：区间调度、排序贪心
- **二分查找**：有序数组二分、答案二分
- **位运算**：汉明重量、位操作技巧
- **数据结构设计**：LRU、Trie、栈/队列实现