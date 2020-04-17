#!/usr/bin/env bash
set -euo pipefail

export COMPOME_PATH="$(realpath ../..)"
export COMPOME_MODEL_PATH=.

if [[ ! -v XTERM ]]
then
    export XTERM=xterm-256color
fi

COMPOME="$(realpath ../../compome)"

function rm_dir {
    if [ "$COMPO_RMDIR" == 0 ]
    then
        rm -rf "$COMPO_WORKDIR"
    fi
}

function test_one {

    lang=$1
    test=$2
    sub_test=$3
    tmp=$4

    tput setab 4 && echo $lang : $test : $sub_test in $tmp $(tput sgr0)
    tput setab 2 && echo "> > > CLEAN PREVIOUS TEST" $(tput sgr0)

    if [ -d $tmp ]
    then
        rm -rf $tmp
    fi

    tput setab 2 && echo "> > > PREPARE TEST"  $(tput sgr0)
    BASE=$"${1}_base"
    cp -r ${BASE} $tmp

    cp -r $1/$2/$3/* $tmp/
    cd $tmp/

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

    rm_dir
    return
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


if [[ -v "COMPO_WORKDIR_TMP" && "$COMPO_WORKDIR_TMP" == 1 ]]
then
    COMPO_WORKDIR=$(mktemp -d)
    COMPO_RMDIR=1
else
    COMPO_WORKDIR=tmp
    COMPO_RMDIR=0
fi

# section split by "/"
if [[ ( $# == 1 ) && ( "$1" =~ .*/..*  ) ]]
then
    r=$(echo ${1} | tr "/" " ")
    if [[ $(echo $r | wc -w) == 3 ]]
    then
        test_one $r ${COMPO_WORKDIR}
    else
        for one_sub_test in $(ls "${1}" )
        do
            test_one ${r} ${one_sub_test} ${COMPO_WORKDIR}
        done

    fi
    exit 0
fi

# section split by " "
if [[ $# == 1 ]] # size 1
then
    for one_test in $(ls "$1")
    do
        if [ -d "${1}/$one_test" ]
        then
            for one_sub_test in $(ls "${1}/${one_test}")
            do
                test_one ${1} ${one_test} ${one_sub_test} ${COMPO_WORKDIR}
            done
        fi
    done
elif [[ $# == 2 ]] # size 2
then
    if [ -d "${1}/${2}" ]
    then
        for one_sub_test in $(ls "${1}/${2}" )
        do
            test_one ${1} ${2} ${one_sub_test} ${COMPO_WORKDIR}
        done
    else
        echo "no dir: ${1}/${2}"
    fi
else # size 3
    test_one $@ ${COMPO_WORKDIR}
fi
