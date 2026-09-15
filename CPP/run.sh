#!/usr/bin/env bash
#
# 薄壳：一键「构建 + 运行」solutions（用参数选择 gcc-16 / clang 版本）
#
# 用法:
#   ./run.sh gcc            # 构建并运行 gcc16 版
#   ./run.sh clang          # 构建并运行 clang 版
#   ./run.sh gcc 436        # 构建后自动跑 436，跑完退出（免手输题号）
#   ./run.sh gcc all        # 构建后自动执行 runall（把已注册的题全跑一遍）
#   ./run.sh gcc -b         # 只构建，不运行
#   ./run.sh gcc -r         # 只运行，不构建
#   ./run.sh -h             # 帮助
#
# preset 别名: gcc|gcc16 -> gcc16 ; clang -> clang ; rel|release|gcc16-rel -> gcc16-rel
#
#
set -euo pipefail

# 允许外部覆盖（便于在别处引用本脚本）
CPP_ROOT="${CPP_ROOT:-$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)}"

usage() {
    echo "用法: run.sh <gcc|clang|rel> [题号|all] [选项]"
    echo
    echo "  gcc | gcc16        使用 gcc16 preset     -> build/gcc16/solutions"
    echo "  clang              使用 clang preset     -> build/clang/solutions"
    echo "  rel | gcc16-rel    使用 gcc16-rel preset -> build/gcc16-rel/solutions（Release, -O2）"
    echo
    echo "选项:"
    echo "  -b, --build-only   只构建，不运行"
    echo "  -r, --run-only     只运行，不构建"
    echo "  -h, --help         显示本帮助"
    echo
    echo "示例:"
    echo "  ./run.sh gcc           构建后进入交互模式"
    echo "  ./run.sh clang 436     构建后用 clang 版跑 436"
    echo "  ./run.sh gcc all       构建后跑 runall（全部已注册题解）"
    echo "  ./run.sh gcc -b        只做增量构建"
    echo
    echo "交互模式可用命令: run / runall / print / erase / clear / exit"
}

preset_arg=""
mode="all"
solution_id=""

while [ $# -gt 0 ]; do
    case "$1" in
        -h|--help)       usage; exit 0 ;;
        -b|--build-only) mode="build" ;;
        -r|--run-only)   mode="run" ;;
        -*)              echo "错误: 未知选项: $1" >&2; usage >&2; exit 2 ;;
        *)
            if [ -z "$preset_arg" ]; then
                preset_arg="$1"
            elif [ -z "$solution_id" ]; then
                solution_id="$1"
            else
                echo "错误: 参数过多: $1" >&2
                usage >&2
                exit 2
            fi
            ;;
    esac
    shift
done

if [ -z "$preset_arg" ]; then
    echo "错误: 必须指定 gcc / clang / rel" >&2
    usage >&2
    exit 2
fi

case "$preset_arg" in
    gcc|gcc16)             preset="gcc16" ;;
    clang)                 preset="clang" ;;
    rel|release|gcc16-rel) preset="gcc16-rel" ;;
    *) echo "错误: 未知 preset: $preset_arg（可用: gcc / clang / rel）" >&2; exit 2 ;;
esac

build_dir="$CPP_ROOT/build/$preset"
bin="$build_dir/solutions"

# ---------- 构建 ----------
if [ "$mode" != "run" ]; then
    if [ ! -d "$build_dir" ]; then
        echo "==> [$preset] 首次配置"
        ( cd "$CPP_ROOT" && cmake --preset "$preset" )
    fi
    jobs="$(sysctl -n hw.ncpu 2>/dev/null || echo 4)"
    echo "==> [$preset] 增量构建 solutions"
    ( cd "$CPP_ROOT" && cmake --build --preset "$preset" --target solutions -j "$jobs" )
fi

if [ ! -x "$bin" ]; then
    echo "错误: 找不到可执行文件 $bin" >&2
    echo "      可能尚未构建成功，请去掉 -r 重跑一次" >&2
    exit 1
fi

if [ "$mode" = "build" ]; then
    echo "==> 构建完成: $bin"
    exit 0
fi

# ---------- 运行 ----------
echo "==> 运行: $bin"
if [ "$solution_id" = "all" ]; then
    { echo exit; echo runall; echo exit; } | "$bin"
elif [ -n "$solution_id" ]; then
    { echo "$solution_id"; echo exit; echo exit; } | "$bin"
else
    "$bin"
fi
