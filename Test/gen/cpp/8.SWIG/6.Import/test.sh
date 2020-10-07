#!/bin/env bash
set -euxo pipefail

cmake -DCMAKE_INSTALL_PREFIX=${COMPOME_PATH}/CompoMe .
make --jobs=$[ $(nproc) ]
make install

export LD_LIBRARY_PATH=${COMPOME_PATH}/CompoMe/lib
export PYTHONPATH=${COMPOME_PATH}/CompoMe
python3 test.py
exit 0
