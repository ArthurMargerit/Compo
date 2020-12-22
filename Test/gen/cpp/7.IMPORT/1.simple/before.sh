export PATH=${PATH}:${COMPOME_PATH}
export COMPOME_MODEL_PATH=$(echo $(pwd)/M_*.yaml | sed "s/.yaml /_d\/:/g;s/.yaml/_d/g"):$(echo ${COMPOME_PATH}/build/* | tr ' ' ':'):.
echo $COMPOME_MODEL_PATH

function generate {
    echo ">> $1"
    cp ${1} ${1:0:-5}_d
    cp T_${1:2:-5}.list ${1:0:-5}_d/target.list
    cp I_${1:2:-5}.list ${1:0:-5}_d/ignore.list
    cp .compoMe.py ${1:0:-5}_d/.compoMe.py

    mkdir ${1:0:-5}_d/compile
    touch ${1:0:-5}_d/compile/${1:0:-5}_import.cmake
    touch ${1:0:-5}_d/compile/${1:0:-5}_links.cmake

    cd ${1:0:-5}_d
    compome generate -f $1
    cd ..
}


function compile {
    cp CMakeLists_lib.txt ${1:0:-5}_d/CMakeLists.txt
    cd ${1:0:-5}_d
    cmake .
    make
    cd ..
}


for yamlfile in ./M_*.yaml ;
do
    mkdir ${yamlfile:0:-5}_d -p
done

generate M_types.yaml
generate M_structs.yaml
generate M_interfaces.yaml
generate M_components.yaml
generate M_links.yaml
generate M_deploiments.yaml

compile M_types.yaml
compile M_structs.yaml
compile M_interfaces.yaml
compile M_components.yaml
compile M_links.yaml
compile M_deploiments.yaml

cp $(find -name "*.a") .
