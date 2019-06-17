cmake_minimum_required(VERSION 3.0)

PROJECT("compo_test")

SET(CMAKE_CXX_STANDARD 11)
FILE(GLOB_RECURSE file_compo src/*.cpp)

ADD_EXECUTABLE(dep1 ${file_compo})

target_include_directories(dep1 PUBLIC "inc")
target_include_directories(dep1 PUBLIC "../lib_model/CPP/BASE_LINK/inc")
target_include_directories(dep1 PUBLIC "../lib_model/CPP/BASE/inc")
target_include_directories(dep1 PUBLIC "../lib_model/CPP/BASE_STRUCTS/inc")
target_include_directories(dep1 PUBLIC "../lib_model/CPP/BASE_TYPES/inc")

