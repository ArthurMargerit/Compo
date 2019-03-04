#!/bin/env bash

cmake . >> cmake.log
make 2>&1  >> make.log
./dep1 >> exec.log
exit 0
