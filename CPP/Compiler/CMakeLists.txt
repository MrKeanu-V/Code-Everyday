####################################################################
# Compiler
#
#   用途：探索编译器差异与底层实现（代码生成、标准特性、内建函数…）
#   特点：每个 .cpp 独立成一个可执行文件；不加任何 -I，不链接 fnt。
#
#   单文件构建：
#     cd CPP/Compiler
#    GCC编译器：
#     g++ -std=C++20 -O2 -Wall -Wextra -o <name> <name>.cpp // gcc 完整指令
#     g++ <name>.cpp -o <name>  // 简化指令
#    Clang编译器：
#     clang++ <name>.cpp -o <name>
#     clang++ -std=c++20 -O2 -Wall -Wextra -o <name> <name>.cpp
#   运行文件：
#     ./<name>
#
####################################################################
cmake_minimum_required(VERSION 3.20)
project(compiler_lab LANGUAGES CXX)

# CACHE 形式：保证 preset / -D 能覆盖默认值
set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ 标准版本 (17/20/23)")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "关闭 GNU 扩展（-std=c++20 而非 gnu++20）")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 每个实验文件 → 一个可执行文件
file(GLOB LAB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# 汇编输出目录
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/asm")

foreach(src IN LISTS LAB_SOURCES)
    get_filename_component(name "${src}" NAME_WE)
    add_executable(${name} "${src}")

    # 同名汇编导出目标：cmake --build --preset <p> --target asm_<name>
    add_custom_target(asm_${name}
        COMMAND ${CMAKE_CXX_COMPILER}
                -S -O2
                -std=c++${CMAKE_CXX_STANDARD}
                -o "${CMAKE_CURRENT_BINARY_DIR}/asm/${name}.s"
                "${src}"
        COMMENT "导出汇编 → asm/${name}.s"
        VERBATIM
    )
endforeach()

list(LENGTH LAB_SOURCES _lab_count)
message(STATUS "compiler_lab : 实验文件 ${_lab_count} 个（每个一个可执行文件）")
message(STATUS "compiler_lab : C++ 标准 = ${CMAKE_CXX_STANDARD}, 扩展 = ${CMAKE_CXX_EXTENSIONS}")
message(STATUS "compiler_lab : 编译器 = ${CMAKE_CXX_COMPILER}")
