cmake_minimum_required(VERSION 3.0)

PROJECT("Interface_bin")

SET(CMAKE_CXX_STANDARD 11)

include("compile/var.cmake")
include("compile/import.cmake")
include("compile/links.cmake")

FILE(GLOB_RECURSE file_compo src/*.cpp)

ADD_EXECUTABLE(Interface_bin ${file_compo})
TARGET_INCLUDE_DIRECTORIES(Interface_bin PUBLIC ${_include_directories})

TARGET_LINK_LIBRARIES(Interface_bin ${_links_lib})
