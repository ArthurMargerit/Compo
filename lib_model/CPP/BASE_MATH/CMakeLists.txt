cmake_minimum_required(VERSION 3.0)

PROJECT("compo_test")

SET(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE file_compo src/*.cpp)


add_library(Math_static STATIC ${file_compo})
add_library(Math_shared SHARED ${file_compo})
add_library(Math_module MODULE ${file_compo})

target_include_directories(Math_static PUBLIC "inc" "../BASE_TYPES/inc" "../BASE/inc")
target_include_directories(Math_shared PUBLIC "inc" "../BASE_TYPES/inc" "../BASE/inc")
target_include_directories(Math_module PUBLIC "inc" "../BASE_TYPES/inc" "../BASE/inc")
