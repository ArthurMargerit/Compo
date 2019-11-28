#!/usr/bin/env bash

export COMPOME_PATH=../../
FAIL=0

for v in $( ls ./*.yaml ) ; do
    tmp_file=$(mktemp)
    tmp_file_err=$(mktemp)

    ../../compome -v 5 expand ${v} 2> ${tmp_file_err} > ${tmp_file}
    sucess=$?

    err=$(cat $tmp_file_err | wc -w )
    if [[ $err != 0 ]]
    then
        echo PYTHON ERROR: ${v}
        printf "====================================\n"
        cat $tmp_file_err
        printf "____________________________________\n\n"
        FAIL=1
    elif [[ $sucess != 0 ]]
    then
        echo ERROR: ${v}
        printf "====================================\n"
        cat ${tmp_file}
        printf "____________________________________\n\n"
        FAIL=1
    fi

    rm $tmp_file_err $tmp_file
done

if [[ $FAIL != 0 ]]
then exit 1
fi
