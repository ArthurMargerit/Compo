#!/bin/env bash

set -euxo pipefail

if [ ! -v CMAKE_COMPOME_OPTION ]
then
    CMAKE_COMPOME_OPTION=""
fi

cmake ${CMAKE_COMPOME_OPTION} .
make --jobs=$[ $(nproc) ]
LD_LIBRARY_PATH=${COMPOME_PATH}/CompoMe/lib ./dep1 -r junit -o ${COMPOME_PATH}/result_${LANG}_${TEST}_${SUB_TEST}.xml

if [[ -v VALGRIND_COMPOME && ${VALGRIND_COMPOME} ]]
then
    LD_LIBRARY_PATH=${COMPOME_PATH}/CompoMe/lib valgrind --leak-check=full ./dep1
fi


# #doxygen
# CPP_FILE=$(find src -name "*.cpp" | grep -v "main.cpp")
# HPP_FILE=$(find inc -name "*.hpp")
# cppcheck --std=c++11 -I inc --enable=all  --xml $CPP_FILE $HPP_FILE  2> log.xml
# cppcheck-htmlreport --file=log.xml --report-dir=html --source-dir=.
# if [ $(cat log.xml | grep "<error " | wc -l) > 10 ]
# then
#     r=$(mktemp -d)

# fi

exit 0
