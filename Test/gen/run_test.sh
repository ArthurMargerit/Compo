#!/usr/bin/env bash
set -euo pipefail

FAIL=0

if [[ ! -v FULL_RESULT_REPORT || -z $FULL_RESULT_REPORT ]]
then
    FULL_RESULT_REPORT=/dev/null
else
    FULL_RESULT_REPORT=$(realpath $FULL_RESULT_REPORT)
    echo "target;result" > $FULL_RESULT_REPORT
fi

if [[ ! -v TERM || -z $TERM ]]
then
    export TERM=dumb
fi

export COMPOME_PATH="$(realpath ../..)"
COMPO="$(realpath ../..)"
COMPOME="${COMPO}/compome"
COMPO_GEN_TEST="${COMPO}/Test/gen"

function rm_dir {
    if [[ "$COMPO_RMDIR" == 1 ]]
    then
        rm -rf "$COMPO_WORKDIR"
    fi
}

function test_one {

    lang=$1
    test=$2
    sub_test=$3
    tmp=$4

    export LANG=$lang
    export TEST=$test
    export SUB_TEST=$sub_test

    tput setab 4 && echo $lang : $test : $sub_test in $tmp $(tput sgr0)
    tput setab 2 && echo "> > > CLEAN PREVIOUS TEST" $(tput sgr0)

    if [ -d $tmp ]
    then
        rm -rf $tmp
    fi

    tput setab 2 && echo "> > > PREPARE TEST"  $(tput sgr0)
    BASE=$"${COMPO_GEN_TEST}/${lang}_base"
    cp -r "${BASE}" "${tmp}"

    cp -r "${COMPO_GEN_TEST}/${lang}/${test}/${sub_test}/"* "$tmp/"
    cd "$tmp/"

    if [ -f before.sh ]
    then
        source before.sh
    fi

    CODE_FILE=code.yaml
    if [ -f file.list ]
    then
        CODE_FILE=$(cat file.list)
    fi


    tput setab 2 && echo "> > > GENERATE" $(tput sgr0)
    $COMPOME generate -f ${CODE_FILE}

    tput setab 2 && echo "> > > TEST"  $(tput sgr0)
    sh test.sh && result=$? || result=$?


    echo  "$LANG/$TEST/$SUB_TEST;$result" >> $FULL_RESULT_REPORT

    if [ $result = 0 ]
    then
        tput setab 2 && echo -- OK -- $(tput sgr0)
    else
        FAIL=1
        tput setab 1 && echo - FAIL - $(tput sgr0)
    fi

    if [ -f after.sh ]
    then
        source after.sh
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
    exit $FAIL
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
        exit 2
    fi
else # size 3
    test_one $@ ${COMPO_WORKDIR}
fi
