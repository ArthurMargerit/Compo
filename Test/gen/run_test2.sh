# !/bin/env bas
set -euo pipefail

export COMPOME_PATH="$(realpath ../..)"
export COMPOME_MODEL_PATH=.

COMPOME="$(realpath ../../compome)"

function test_one {

    lang=$1
    test=$2
    sub_test=$3

    echo $lang : $test : $sub_test
    echo "> > > PREPARE TEST"
    tmp="$(mktemp)"
    tmpa="${tmp}.dir"

    echo $$ > ${tmp}
    mkdir "${tmpa}"

    cp $1/config.py ${tmpa}/.compoMe.py
    cp $1/test.sh ${tmpa}/test.sh
    cp -r $1/$2/$3/* ${tmpa}
    cd ${tmpa}

    echo "> > > GENERATE"

    $COMPOME generate -f code.yaml

    echo "> > > TEST"
    sh test.sh
    result=$?
    if [ $result = 0 ]
    then
        echo -- OK --
    else
        echo - FAIL -
    fi

    rm -rf ${tmpa}
    rm ${tmp}


    cd -
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
