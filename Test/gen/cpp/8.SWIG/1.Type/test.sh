#!/bin/env bash
set -euxo pipefail

#cmake -DCMAKE_INSTALL_PREFIX=${COMPOME_PATH}/CompoMe .
cmake .
make --jobs=$[ $(nproc) ]
#make install

python3 ./test.py

exit 0
