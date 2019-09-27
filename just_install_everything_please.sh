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
else
    echo "Error: Unable to find c++ compiler"
    exit 1
fi

rm CLIProteinViewer set_CLIPV_params 2>/dev/null

$CXX src/apps/CLIProteinViewer.cc -o CLIProteinViewer -Isrc -O3 -std=c++11 \
     1>/dev/null 2>/dev/null
$CXX src/apps/set_CLIPV_params.cc -o set_CLIPV_params -Isrc -O3 -std=c++11 \
     1>/dev/null 2>/dev/null

if [ ! -f CLIProteinViewer ] && [ ! -f set_CLIPV_params ]; then
    echo "Error: Compilation seemed to fail somehow"
    exit 1
fi

#install to PATH if needed
echo $PATH | sed 's/:/\n/g' > .temp
 while read line; do
    if [ `realpath $line` == `pwd` ]; then
	#pwd is already in our working directory
	echo "Installation was a success!"
	exit 0
    fi
done < .temp

rm .temp

file=""
if [ -f $HOME/.bashrc ]; then
    file="$HOME/.bashrc"
    echo 'export PATH=$PATH:'`pwd` >> $HOME/.bashrc
elif [ -f $HOME/.bash_profile ]; then
    file="$HOME/.bash_profile"
    echo 'export PATH=$PATH:'`pwd` >> $HOME/.bash_profile
else
    echo "Error: Unable to find $HOME/.bashrc"
    exit 1
fi

echo "Installation was a success. To use this tool in your current session, run 'source $file'. The CLIProteinViewer will be available for all future session."
