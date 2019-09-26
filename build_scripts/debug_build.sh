#!/bin/bash

for x in "g++" "clang++"; do
    for y in "c++11" "c++14" "c++17"; do
	$x src/apps/CLIProteinViewer.cc -o CLIProteinViewer -Isrc -O0 -g -DDEBUG -std=$y -Wall -Wextra -Wunused
	$x src/apps/set_CLIPV_params.cc -o set_CLIPV_params -Isrc -O0 -g -DDEBUG -std=$y -Wall -Wextra -Wunused
    done
done
