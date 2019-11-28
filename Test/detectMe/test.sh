#!/usr/bin/env bash

export COMPOME_PATH=../../

for v in $( ls ./*.yaml ) ; do
    tmp_file=$(mktemp)
    tmp_file_err=$(mktemp)

    ../../compome -v 5 expand ${v} 2> ${tmp_file_err} > ${tmp_file}
    sucess=$?

    if [[ $sucess == 0 ]]
    then
        echo NOT DETECTED: ${v}
        printf "====================================\n"
        cat ${v}
        printf "____________________________________\n\n"
    fi

    err=$(cat $tmp_file_err | wc -w )
    if [[ $err != 0 ]]
    then
        echo PYTHON ERROR: ${v}
        printf "====================================\n"
        cat $tmp_file_err
        printf "____________________________________\n\n"
    fi

    rm $tmp_file_err $tmp_file
done
