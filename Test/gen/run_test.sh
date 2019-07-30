# !/bin/env bas
set -e

COMPOME=../../../compome

function test_one {

    lang=$1
    test=$2
    sub_test=$3

    echo $lang : $test : $sub_test

    echo "> > > CLEAN PREVIOUS TEST"
    if [ -d tmp ]
    then
        rm -rf tmp
    fi

    echo "> > > PREPARE TEST"
    mkdir tmp
    cp $1/config.py tmp/.compoMe.py
    cp $1/test.sh tmp/test.sh
    cp -r $1/$2/$3/* tmp/
    cd tmp/

    echo "> > > GENERATE"
    $COMPOME generate -f code.yaml 2>&1 >> gen.log
    bash test.sh
    result=$?
    if [ $result = 0 ]
    then
        echo --OK--
    else
        echo -FAIL-
    fi

    cd ..
}


if [[ $# == 1 ]]
then
    for one_test in $(ls "$1")
    do
        if [ -d "${1}/$one_test" ]
        then
            for one_sub_test in $(ls "${1}/${one_test}")
            do
                echo "$1 - ${one_test} - ${one_sub_test}"
                test_one ${1} ${one_test} ${one_sub_test}
            done
        fi
    done
else
    test_one $@
fi
