# CMake — 学习与语法整理沙盒

> ⚠️ **目录名必须保持大写 `CMake`。**
> 本机文件系统不区分大小写（实测 `/Users/keanu/workspace` 与 `/Users/keanu/WORKSPACE` 指向同一目录），
> 所以**不要再新建一个小写 `cmake/`**，两者会互相覆盖。

## 定位

这里是**独立的 CMake 学习沙盒**，与真实项目刻意隔离：

- 不属于 `CPP/CMakeLists.txt`（项目①）的构建范围，**不会**被主项目 configure 到；
- 每一级练习**自己建子目录 + 自己的 `CMakeLists.txt`**，独立 configure，互不干扰；
- 练习建议挂着本项目的真实诉求做，比跟教程走更扎实。

## 目录约定（建议）

```
CPP/CMake/
├── README.md          ← 本文件
├── 01-hello/          ← 每级一个子目录
│   ├── CMakeLists.txt
│   └── main.cpp
├── 02-library/
├── 03-include/
└── ...
```

每级独立构建（不污染主项目）：

```bash
cmake -S CPP/CMake/01-hello -B CPP/CMake/01-hello/build
cmake --build CPP/CMake/01-hello/build
```

## 学习阶梯（每级都标注它在本项目里的真实出处）

| 级 | 主题 | 本项目里的真实出处 |
|----|------|--------------------|
| 01 | `project()` / `add_executable()` / 构建产物落在哪 | `CPP/Compiler/` 里编译单个实验文件 |
| 02 | `add_library()` + `target_link_libraries()` | `fnt` 静态库被 `solutions` 复用 |
| 03 | `target_include_directories()` 的 PRIVATE / PUBLIC / INTERFACE | **最初那个「`fnt_utils.h: No such file or directory`」** |
| 04 | `set()` / `list()` / `foreach()` / `get_filename_component()` | 把 209 个题解批量生成目标 |
| 05 | `file(GLOB CONFIGURE_DEPENDS)` 与显式列表的取舍 | 自动发现新增的题解文件 |
| 06 | `option()` / `if()` / `EXCLUDE_FROM_ALL` | 126 个自包含题解「按需构建」 |
| 07 | `CMAKE_CXX_STANDARD` / `CMAKE_CXX_EXTENSIONS` / `target_compile_features()` | 统一 C++20；`char8_t` 在 C++17 下直接编不过 |
| 08 | **CMakePresets**：configure/build presets、`inherits`、`condition` | `gcc16` vs `clang` 编译器矩阵 |
| 09 | `add_custom_command()` / `add_custom_target()` | 导出 `.s` 汇编做底层对比（`asm_<name>`） |
| 10 | `add_test()` / CTest | 题解结果回归测试 |
| 11 | `include()` 拆模块 / `add_subdirectory()` | 项目结构演进（同样注意大小写冲突） |
| 12 | 生成器表达式 `$<...>` / `install()` / `export()` | 进阶：按编译器/配置差异化 |

## 两个已经踩过的坑（留作教材）

1. **`set(CMAKE_CXX_STANDARD 20)` 会屏蔽 preset。**
   必须写成 `set(CMAKE_CXX_STANDARD 20 CACHE STRING "...")`，
   否则 `-DCMAKE_CXX_STANDARD=17` 和 preset 里的设置**静默失效**。

2. **同名 `class Solution` 放在同一个 target 里不会报错。**
   实测两个各自定义 `Solution::f()`（返回 1 / 返回 2）的 TU 链接**退出码 0**，
   属静默 ODR 违规 —— 生效的是被任意选中的那个实现。
   而重复的 `main()` 是硬报错（`duplicate symbol '_main'`）。
   这正是 `algorithm/src/` 里的题解类必须改名 `Solution<题号>` 才能合并进单一 target 的原因。
