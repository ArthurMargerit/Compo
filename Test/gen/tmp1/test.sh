#!/bin/env bash

set -euxo pipefail

# cmake . >> cmake.log
# make 2>&1  >> make.log
# ./dep1 >> exec.log
cmake .
make --jobs=$[ $(nproc) ]
./dep1
#doxygen


cppcheck --std=c++11 -I inc --enable=all --suppress=noExplicitConstructor --suppress=missingIncludeSystem --suppress=missingOverride  --suppress=unusedFunction --suppress=unmatchedSuppression  --xml ./src ./inc  2> log.xml

if [ $(cat log.xml | grep "<error " | wc -l) > 10 ]
then
    r=$(mktemp -d)
    cppcheck-htmlreport --file=log.xml --report-dir=html --source-dir=.
fi


exit 0
