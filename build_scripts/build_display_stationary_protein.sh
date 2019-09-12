#!/bin/bash

#g++ src/apps/display_stationary_protein.cc -o display_stationary_protein -Isrc -O3
g++ src/apps/display_stationary_protein.cc -o display_stationary_protein -Isrc -O0 -g -DDEBUG
