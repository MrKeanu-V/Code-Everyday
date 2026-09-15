####################################################################
# 项目①：fnt 基础框架 + algorithm 题解
#
#   设计前提：algorithm/src/ 下所有 .cpp 最终都迁移为 FNT 框架型题解
#             （继承 BaseSolution + FNT_REGISTER，自身不带 main）
#             因此全部题解源文件合入【同一个 target】，与 main.cpp 一起链接。
#
#   构建方式：
#     cd CPP
#     cmake --preset gcc16
#     cmake --build --preset gcc16
#     ./build/gcc16/solutions
####################################################################
cmake_minimum_required(VERSION 3.20)
project(cpp_lab LANGUAGES CXX)

# ---------- 语言标准 ----------
# 注意：这里必须用 CACHE 形式。若写成普通的 set(CMAKE_CXX_STANDARD 20)，
# 会屏蔽掉 -DCMAKE_CXX_STANDARD=17 以及 CMakePresets 里设置的值。
set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ 标准版本 (17/20/23)")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "关闭 GNU 扩展（-std=c++20 而非 gnu++20）")

# 生成 compile_commands.json（供 cpptools / clangd 做 IntelliSense）
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 可选：严格告警（默认关，避免迁移期间刷屏）
option(LAB_STRICT_WARNINGS "开启 -Wall -Wextra" OFF)

# ---------- 1) fnt 基础库 ----------
add_library(fnt STATIC
    fnt/fnt_utils.cpp
    fnt/fnt_solution.cpp
)

# PUBLIC：链接 fnt 的目标自动获得 -I<CPP>，
# 这样题解里的 #include "fnt/fnt_utils.h" 才能被找到
# （这正是最初 "fnt_utils.h: No such file or directory" 缺的那个搜索路径）。
target_include_directories(fnt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(LAB_STRICT_WARNINGS)
    target_compile_options(fnt PRIVATE -Wall -Wextra)
endif()

# ---------- 2) 题解：全部合入一个 target ----------
file(GLOB ALGORITHM_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/algorithm/src/*.cpp"
)

# ---------- 已迁移清单：默认只构建已迁移的题解，构建始终为绿 ----------
# 清单文件：CPP/migrated_solutions.cmake —— 每迁移完一个题解就往里追加一行。
set(MIGRATED_LIST_FILE "${CMAKE_CURRENT_SOURCE_DIR}/migrated_solutions.cmake")
if(NOT EXISTS "${MIGRATED_LIST_FILE}")
    message(FATAL_ERROR "找不到已迁移清单文件：${MIGRATED_LIST_FILE}")
endif()
include("${MIGRATED_LIST_FILE}")

# 登记为 configure 依赖：改完清单后直接 cmake --build 会自动重新 configure
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${MIGRATED_LIST_FILE}")

# 把清单里的题号翻译成源文件路径，同时做拼写校验
set(MIGRATED_ALGORITHM_SOURCES "")
set(_missing_ids "")
foreach(_id IN LISTS MIGRATED_SOLUTIONS)
    set(_src "${CMAKE_CURRENT_SOURCE_DIR}/algorithm/src/${_id}.cpp")
    if(EXISTS "${_src}")
        list(APPEND MIGRATED_ALGORITHM_SOURCES "${_src}")
    else()
        list(APPEND _missing_ids "${_id}")
    endif()
endforeach()

if(_missing_ids)
    message(FATAL_ERROR
        "migrated_solutions.cmake 中以下题号找不到对应源文件（请检查拼写）：\n  ${_missing_ids}")
endif()

# 默认只构建已迁移的题解；全部迁移完成后可打开此开关构建全部
option(LAB_BUILD_ALL_SOLUTIONS
       "忽略已迁移清单，构建 algorithm/src 下全部题解（迁移完成后的终态）" OFF)

if(LAB_BUILD_ALL_SOLUTIONS)
    set(BUILD_SOURCES ${ALGORITHM_SOURCES})
    set(_build_mode "全部题解（LAB_BUILD_ALL_SOLUTIONS=ON）")
else()
    set(BUILD_SOURCES ${MIGRATED_ALGORITHM_SOURCES})
    set(_build_mode "已迁移清单")
endif()

add_executable(solutions
    main.cpp
    ${BUILD_SOURCES}
)

target_link_libraries(solutions PRIVATE fnt)

if(LAB_STRICT_WARNINGS)
    target_compile_options(solutions PRIVATE -Wall -Wextra)
endif()

# ---------- configure 时打印迁移进度 ----------
list(LENGTH BUILD_SOURCES              _build_count)
list(LENGTH MIGRATED_ALGORITHM_SOURCES _migrated_count)
list(LENGTH ALGORITHM_SOURCES          _total_count)
math(EXPR _remaining_count "${_total_count} - ${_migrated_count}")

message(STATUS "cpp_lab  : 迁移进度 ${_migrated_count}/${_total_count}（待迁移 ${_remaining_count}）")
message(STATUS "cpp_lab  : 本次构建 ${_build_count} 个源文件，来源 = ${_build_mode}")
message(STATUS "cpp_lab  : C++ 标准 = ${CMAKE_CXX_STANDARD}, GNU 扩展 = ${CMAKE_CXX_EXTENSIONS}")
message(STATUS "cpp_lab  : 构建类型 = ${CMAKE_BUILD_TYPE}, 编译器 = ${CMAKE_CXX_COMPILER}")
