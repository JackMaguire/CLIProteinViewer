#!/bin/bash

defines=""
if [[ `tput colors` -ge 256 ]]; then
    defines="$defines -DCOLOR256"
fi

for x in "g++" "clang++"; do
    for y in "c++11" "c++14" "c++17"; do
	$x src/apps/CLIProteinViewer.cc -o CLIProteinViewer_debug -Isrc -O0 -g -DDEBUG -std=$y -Wall -Wextra -Wunused $defines
	$x src/apps/set_CLIPV_params.cc -o set_CLIPV_params_debug -Isrc -O0 -g -DDEBUG -std=$y -Wall -Wextra -Wunused $defines
    done
done
