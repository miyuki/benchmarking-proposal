#!/bin/bash -e
GCC_PATH=/opt/gcc-5.2.0/bin
CLANG_PATH=/usr/bin

cd "$(dirname "$0")"

mkdir -p ./build
"$GCC_PATH/g++" test.cc -std=c++14 -Wall -Wextra -pedantic -S -O3 \
    -fdump-tree-gimple -fdump-tree-optimized -fverbose-asm \
    -o ./build/test.x86_64.gcc.s
"$GCC_PATH/g++" test.cc -std=c++14 -S -O3 -m32 \
    -o ./build/test.i386.gcc.s
"$CLANG_PATH/clang++" test.cc -std=c++14 -S -O3 \
    -o ./build/test.x86_64.clang.s
