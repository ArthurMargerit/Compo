# !/bin/env bas
set -euo pipefail

export COMPOME_PATH=../../../
export COMPOME_MODEL_PATH=.

COMPOME=../../../compome

function test_one {

    lang=$1
    test=$2
    sub_test=$3

    tput setab 4 && echo $lang : $test : $sub_test  $(tput sgr0)

    tput setab 2 && echo "> > > CLEAN PREVIOUS TEST" $(tput sgr0)
    if [ -d tmp ]
    then
        rm -rf tmp
    fi

    tput setab 2 && echo "> > > PREPARE TEST"  $(tput sgr0)
    mkdir tmp
    cp $1/config.py tmp/.compoMe.py
    cp $1/test.sh tmp/test.sh
    cp $1/Doxyfile tmp/Doxyfile
    cp $1/CMakeLists.txt tmp/CMakeLists.txt
    cp -r $1/$2/$3/* tmp/
    cd tmp/

    tput setab 2 && echo "> > > GENERATE" $(tput sgr0)

    $COMPOME generate -f code.yaml

    tput setab 2 && echo "> > > TEST"  $(tput sgr0)
    sh test.sh
    echo 1
    result=$?
    if [ $result = 0 ]
    then
        tput setab 2 && echo -- OK -- $(tput sgr0)
    else
        tput setab 1 && echo - FAIL - $(tput sgr0)
    fi

    cd ..
}

if [[ $# == 0 ]]
then
    echo "arg error:"
    echo "Example"
    echo "All test of CPP"
    echo "./run_test.sh lang"

    echo "All test of lang cat"
    echo "./run_test.sh lang cat"

    echo "Execute test in lang cat named test"
    echo "./run_test.sh lang cat test"
    exit 1
fi

if [[ $# == 1 ]]
then
    for one_test in $(ls "$1")
    do
        if [ -d "${1}/$one_test" ]
        then
            for one_sub_test in $(ls "${1}/${one_test}")
            do
                test_one ${1} ${one_test} ${one_sub_test}
            done
        fi
    done
elif [[ $# == 2 ]]
then
    if [ -d "${1}/${2}" ]
    then
        for one_sub_test in $(ls "${1}/${2}" )
        do
            echo $one_sub_test
            test_one ${1} ${2} ${one_sub_test}
        done
    else
        echo "no dir: ${1}/${2}"
    fi
else
    test_one $@
fi
