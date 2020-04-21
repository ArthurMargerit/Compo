
if [[ -v COMPO_WORKDIR_TMP && COMPO_WORKDIR_TMP == 1 ]]
then
    export COMPOME_PATH="$(realpath ../../..)"
else
    p=$(pwd)
    cd -
    export COMPOME_PATH="$(realpath ../..)"
    cd ${p}
fi

export COMPOME_MODEL_PATH=.
