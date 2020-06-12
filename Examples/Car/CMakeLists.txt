cmake_minimum_required(VERSION 3.0)

PROJECT("Car")

SET(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE file_compo src/*.cpp)

add_library(Link_static STATIC ${file_compo})
