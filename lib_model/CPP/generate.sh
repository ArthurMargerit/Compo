#!/usr/bin/env bash

for path_lib in *
do
    if [ -d $path_lib ]
    then
        cd $path_lib
        cmake .
        make
        cd ..
    fi
done
