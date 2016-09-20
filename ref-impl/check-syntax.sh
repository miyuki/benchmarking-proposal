#!/bin/bash -e
GCC_PATH=/opt/gcc-5.2.0/bin
"$GCC_PATH/g++" -xc++ -std=c++1z -fsyntax-only -c benchmark.h -o /dev/null
