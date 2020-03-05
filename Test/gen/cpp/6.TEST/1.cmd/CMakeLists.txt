cmake_minimum_required(VERSION 3.0)

PROJECT("compo_test")

SET(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE file_compo_dep1 src/Serialization_context.cpp src/*/*.cpp src/main.cpp)
FILE(GLOB_RECURSE file_compo_dep2 src/Serialization_context.cpp src/*/*.cpp src/main2.cpp)

ADD_EXECUTABLE(dep1 ${file_compo_dep1})
ADD_EXECUTABLE(dep2 ${file_compo_dep2})

target_include_directories(dep1 PUBLIC "inc")
target_include_directories(dep2 PUBLIC "inc")

