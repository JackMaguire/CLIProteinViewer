#!/bin/bash

g++ src/apps/display_single_sphere.cc -o display_single_sphere -Isrc -O3 -std=c++17
#g++ src/apps/display_single_sphere.cc -o display_single_sphere -Isrc -O0 -g -DDEBUG -std=c++17
