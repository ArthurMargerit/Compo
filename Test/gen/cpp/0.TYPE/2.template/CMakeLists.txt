cmake_minimum_required(VERSION 3.0)

PROJECT("compo_test")

SET(CMAKE_CXX_STANDARD 11)
FILE(GLOB_RECURSE file_compo src/*.cpp)

ADD_EXECUTABLE(dep1 ${file_compo})

target_include_directories(dep1 PUBLIC "inc")
