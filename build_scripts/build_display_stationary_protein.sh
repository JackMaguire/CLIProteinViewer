#!/bin/bash

#g++ src/apps/display_stationary_protein.cc -o bin/display_stationary_protein -Isrc -O3
g++ src/apps/display_stationary_protein.cc -o bin/display_stationary_protein -Isrc -O0 -g -DDEBUG
