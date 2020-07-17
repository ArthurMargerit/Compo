cmake_minimum_required(VERSION 3.0)

PROJECT("CompoMe")
SET(CMAKE_CXX_STANDARD 11)
FILE(GLOB_RECURSE file_compo src/*.cpp)

add_library(CompoMe_static STATIC ${file_compo})
add_library(CompoMe_shared SHARED ${file_compo})
add_library(CompoMe_module MODULE ${file_compo})

target_include_directories(CompoMe_module PUBLIC "inc")
target_include_directories(CompoMe_static PUBLIC "inc")
target_include_directories(CompoMe_shared PUBLIC "inc")

