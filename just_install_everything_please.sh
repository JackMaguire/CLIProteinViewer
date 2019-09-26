#!/bin/bash

CXX="no_cc"

if `g++ --version 1>/dev/null 2>/dev/null`; then
    CXX="g++"
elif `gcc --version 1>/dev/null 2>/dev/null`; then
    CXX="gcc"
elif `clang++ --version 1>/dev/null 2>/dev/null`; then
    CXX="clang++"
elif `clang --version 1>/dev/null 2>/dev/null`; then
    CXX="clang"
fi

CXX=clang++

$CXX src/apps/CLIProteinViewer.cc -o CLIProteinViewer -Isrc -O3 -std=c++11 #\
     1>/dev/null 2>/dev/null
$CXX src/apps/set_CLIPV_params.cc -o set_CLIPV_params -Isrc -O3 -std=c++11 #\
     1>/dev/null 2>/dev/null

