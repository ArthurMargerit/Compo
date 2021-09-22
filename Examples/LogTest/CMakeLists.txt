cmake_minimum_required(VERSION 3.0)
project(Log_example)
include("compile/file/main.cmake")

add_executable(LogServer_bin src/main.cpp)
target_link_libraries(LogServer_bin ${compo_lib_name})

add_executable(LogCli_bin src/main_log_cli.cpp)
target_link_libraries(LogCli_bin ${compo_lib_name})
