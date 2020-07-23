cmake_minimum_required(VERSION 3.0)

PROJECT("compo_test")

SET(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE file_compo_dep1 src/*/*.cpp src/main.cpp)
FILE(GLOB_RECURSE file_compo_dep2 src/*/*.cpp src/main2.cpp)
include("compile/import.cmake")
include("compile/links.cmake")

ADD_EXECUTABLE(dep1 ${file_compo_dep1})
ADD_EXECUTABLE(dep2 ${file_compo_dep2})

target_include_directories(dep1 PUBLIC ${_include_directories})
target_include_directories(dep2 PUBLIC ${_include_directories})

target_link_libraries(dep1 ${_links_lib})
target_link_libraries(dep2 ${_links_lib})

