cmake_minimum_required(VERSION 3.0)

PROJECT("HelloWord")

SET(CMAKE_CXX_STANDARD 11)

include("compile/var.cmake")
include("compile/import.cmake")
include("compile/links.cmake")

FILE(GLOB_RECURSE file_compo src/*.cpp)

ADD_EXECUTABLE(Hello_bin ${file_compo})
TARGET_INCLUDE_DIRECTORIES(Hello_bin PUBLIC ${_include_directories})
TARGET_LINK_LIBRARIES(Hello_bin ${_links_lib})
