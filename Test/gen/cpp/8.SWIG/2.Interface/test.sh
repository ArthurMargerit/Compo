#!/bin/env bash
set -euxo pipefail

cmake .
make --jobs=$[ $(nproc) ]

export LD_LIBRARY_PATH=${COMPOME_PATH}/CompoMe/lib:.
python3 ./test.py
