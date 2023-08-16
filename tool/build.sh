#!/usr/bin/env bash


DOCKER_BUILD_NAME=$(basename $(pwd))${IMAGE_DOCKER_NAME}
DOCKER_BUILD_NAME=$(echo $DOCKER_BUILD_NAME | tr '[:upper:]' '[:lower:]')
ENV_FILE=./.build_env

force=0
persist=0
debug=0

helpFunction()
{
   echo ""
   echo "Usage: $0 make-command"
   echo "If you want to pass env var to the docker, put it inside a file named : \"$ENV_FILE\""
   echo -e "\t-h Print this"
   echo -e "\t-f force recreation of docker image and build dir"
   echo -e "\t-d Compile in debug"
   echo -e "\t-c custom command to execute"
   exit 1 # Exit script after printing help
}

while getopts "fdhc:" opt
do
   case "$opt" in
      h ) helpFunction ;;
      f ) force=1 ;;
      d ) debug=1 ;;
      p ) persist=1 ;;
      c ) COMMAND=$OPTARG ;;
   esac
done

shift "$((OPTIND-1))"

build_docker_image() {
    docker build -t ${DOCKER_BUILD_NAME}_img $( [ -z "$IMAGE_DOCKER_FILE" ] || echo " -f ${IMAGE_DOCKER_FILE}" ) . || exit 1
}

# Print helpFunction in case parameters are empty
if [ "$force" = "1" ]
then
   build_docker_image
fi

CMAKE_DEFAULT_FLAG='-DWITH_DOC=ON -DCODE_COVERAGE=ON'
if [ $debug ]
then
    CMAKE_FLAG=$(echo ${CMAKE_DEFAULT_FLAG} -DCMAKE_BUILD_TYPE=Debug)
else
    CMAKE_FLAG=$(echo ${CMAKE_DEFAULT_FLAG} -DCMAKE_BUILD_TYPE=Release)
fi

if [ "$(docker image ls ${DOCKER_BUILD_NAME}_img | wc -l)" = "1" ]
then
	build_docker_image
fi

if [ -z "$COMMAND" ]
then
    [ -z "$BUILD_PATH" ] && BUILD_PATH="build"
    COMMAND="bash -c 'cd Test/gen/ && ./core_build.sh'"
fi

ENV_CMD=""
if [ -f "$ENV_FILE" ]; then
    ENV_CMD="--env-file=$ENV_FILE"
fi

if [ "$persist" = "1" ]; then
    # persist run
    # check if container is running
    if docker container ls --format "table {{.Names}}" | grep ${DOCKER_BUILD_NAME}_inst
    then
        echo __ RESTART THE DOCKER __
        docker run -d --rm \
           --name ${DOCKER_BUILD_NAME}_inst \
           --user $UID:$GID \
           --workdir $(pwd) \
           --cap-add=NET_ADMIN \
           --interactive --tty \
           --network host \
           ${DOCKER_OPTION} \
           $ENV_CMD \
           -v $(pwd):$(pwd) \
           -v ${HOME}/.ssh:/home/lapin/.ssh \
           ${DOCKER_BUILD_NAME}_img sleep infinity
    fi

    # call Command inside
    docker exec ${DOCKER_BUILD_NAME}_inst bash -c "${COMMAND} $@"


else
    # normal run
    docker run --rm \
           --name ${DOCKER_BUILD_NAME}_inst \
           --user $UID:$GID \
           --workdir $(pwd) \
           --cap-add=NET_ADMIN \
           --interactive --tty \
           --network host \
           ${DOCKER_OPTION} \
           $ENV_CMD \
           -v $(pwd):$(pwd) \
           -v ${HOME}/.ssh:/home/lapin/.ssh \
           ${DOCKER_BUILD_NAME}_img \
           bash -c \
           "${COMMAND} $@"

fi

