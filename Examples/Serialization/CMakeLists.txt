cmake_minimum_required(VERSION 3.0)

PROJECT("Serialization_bin")

SET(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE file_compo src/*.cpp)

ADD_EXECUTABLE(Serialization_bin ${file_compo})
TARGET_INCLUDE_DIRECTORIES(Serialization_bin PUBLIC "inc")
