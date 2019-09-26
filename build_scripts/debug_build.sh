#!/bin/bash

g++ src/apps/CLIProteinViewer.cc -o CLIProteinViewer -Isrc -O0 -g -DDEBUG -std=c++17 -Wall -Wextra

#set_CLIPV_params.cc
g++ src/apps/set_CLIPV_params.cc -o set_CLIPV_params -Isrc -O0 -g -DDEBUG -std=c++17 -Wall -Wextra

#g++ src/apps/CLIProteinViewer.cc -o CLIProteinViewer -Isrc -O0 -g -DDEBUG -std=c++17
