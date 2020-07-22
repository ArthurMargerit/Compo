cmake_minimum_required(VERSION 3.0)
project("compo_catch")
set(CMAKE_CXX_STANDARD 11)

add_library(Catch_shared SHARED src/catch.cpp)
add_library(Catch_static STATIC src/catch.cpp)
add_library(Catch_module MODULE src/catch.cpp)

target_include_directories(Catch_shared PUBLIC "inc")
target_include_directories(Catch_static PUBLIC "inc")
target_include_directories(Catch_module PUBLIC "inc")

install(TARGETS Catch_static Catch_shared Catch_module
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY inc/ DESTINATION inc
        FILES_MATCHING PATTERN "*.hpp")
