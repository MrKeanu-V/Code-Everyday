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
#include "fnt/fnt_utils.h"
#include "fnt/fnt_solution.h"
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

整个 `algorithm/src/` 与 `fnt` 框架由 **CMake** 统一管理（顶层项目 = `CPP/CMakeLists.txt`），
所有题解源文件与 `main.cpp` 一起合入**同一个 target：`solutions`**。

编译/运行薄壳：
```bash
cd CPP
./run.sh -h
```
CMakeLists核心：
```cmake
add_library(fnt STATIC fnt/fnt_utils.cpp fnt/fnt_solution.cpp)
target_include_directories(fnt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})   # 即 CPP/
```

### 迁移清单

`CPP/migrated_solutions.cmake` 维护着「已迁移到 FNT 框架的题解」清单。
每迁移完一个题解就往里追加一行，然后直接构建即可
（该文件已登记为 configure 依赖，改完会自动重新 configure）：

```bash
cmake --preset gcc16            # 输出：迁移进度 66/209（待迁移 143）
cmake --build --preset gcc16    # 只编译清单内的题解 → build/gcc16/solutions
```


全部迁移完成后，使用或修改这个开关切到全量：

```bash
cmake --preset gcc16 -DLAB_BUILD_ALL_SOLUTIONS=ON
```

### 迁移期进度说明

迁移进度：76 / 216
迁移完成前 `solutions` 目标编译失败属预期现象，期间可用上面的 `SOLUTION_FILTER` 逐个验证。

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

## 题解数据统计

难度统计：
类别统计：