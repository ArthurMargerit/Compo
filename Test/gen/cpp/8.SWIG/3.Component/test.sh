#!/bin/env bash

set -euxo pipefail

rm src/catch.cpp
cmake .
make

cp $(find swig -name "*.py") .
python3 test.py
exit 0
