#!/bin/env bash

set -euxo pipefail

if [ ! -v CMAKE_COMPOME_OPTION ]
then
    CMAKE_COMPOME_OPTION=""
fi

cmake ${CMAKE_COMPOME_OPTION} -DCMAKE_INSTALL_PREFIX=${COMPOME_PATH}/CompoMe .
make --jobs=$[ $(nproc) ]
./dep1 -r junit -o ${COMPOME_PATH}/result_${LANG}_${TEST}_${SUB_TEST}.xml

if [[ -v VALGRIND_COMPOME && ${VALGRIND_COMPOME} ]]
then
    valgrind --leak-check=full ./dep1
fi

exit 0
