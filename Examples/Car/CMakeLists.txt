cmake_minimum_required(VERSION 3.0)

PROJECT("Car")

SET(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE file_compo src/*.cpp)

ADD_EXECUTABLE(car_bin ${file_compo})
TARGET_INCLUDE_DIRECTORIES(car_bin PUBLIC "inc")
