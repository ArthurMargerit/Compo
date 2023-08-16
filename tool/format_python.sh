#!/usr/bin/env bash

function format_py_dir {
    printf "$1: "

    if [ -d $1 ]
    then
        # ok
        printf "."
    else
        printf "\e[0;33m NO DIR\e[m\n"
        return 0
    fi

    files="$(find ${1} -name "*.py" | grep -v ".#")"
    if [ "${files}" = "" ]
    then
        printf "\e[0;33m NO FILES\e[m\n"
        return 0
    fi

    printf "."

    autopep8  ${files} --diff

    printf "."

    autopep8  ${files} --in-place --exit-code

    if [ "$?" != "0" ]
    then
        printf "\e[0;31m Format have to be applied\e[m\n"
        return 1
    else
        printf "\e[0;32m OK\e[m\n"
        return 0
    fi
}

format_py_dir src && \
    format_py_dir script && \
    format_py_dir tool
