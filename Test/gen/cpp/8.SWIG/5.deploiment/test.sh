#!/bin/env bash
set -euxo pipefail

cmake -DCMAKE_INSTALL_PREFIX=${COMPOME_PATH}/CompoMe .
make --jobs=$[ $(nproc) ]
make install

p=$(pwd)
cd ${COMPOME_PATH}/CompoMe
export LD_LIBRARY_PATH=${COMPOME_PATH}/CompoMe/lib
python3 ${p}/test.py
cd $p

exit 0