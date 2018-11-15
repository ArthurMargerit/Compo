# !/bin/env bash

function test_one {

    lang=$1
    test=$2
    sub_test=$3

    echo $lang : $test

    if [ -d tmp ]
    then
        rm -r tmp
    fi

    mkdir tmp

    cd tmp/

    compome generate -f ../$1/$2/$3/code.yaml 2>&1 >> out.log
    cp ../$1/$2/$3/main.cpp src/main.cpp >> out.log
    ln -s ../../../tool/CMakeLists_full.txt CMakeLists.txt >> out.log
    cmake . >> out.log
    make 2>&1  >> out.log
    ./dep1 >> out.log
    result=$?
    if [ $result = 0 ]
    then
        echo oK
    fi

    cd ..

}


if [[ $# == 1 ]]
then 
    for one_test in $(ls "$1")
    do
        for one_sub_test in $(ls "$1/$one_test")
        do
            echo $1 $one_test $one_sub_test
            test_one $1 $one_test $one_sub_test

        done
    done
else
    test_one $@
fi
