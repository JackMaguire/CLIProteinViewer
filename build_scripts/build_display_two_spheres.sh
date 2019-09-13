#!/bin/bash

g++ src/apps/display_two_spheres.cc -o bin/display_two_spheres -Isrc -O3 -std=c++17
#g++ src/apps/display_two_spheres.cc -o bin/display_two_spheres -Isrc -O0 -g -DDEBUG -std=c++17
