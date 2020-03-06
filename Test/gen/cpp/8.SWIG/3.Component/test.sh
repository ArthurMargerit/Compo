#!/bin/env bash

set -euxo pipefail

# cmake . >> cmake.log
# make 2>&1  >> make.log
# ./dep1 >> exec.log
cmake .
make --jobs=$[ $(nproc) ]

cp swig/*/*.py .
python3 test.py
exit 0
