cmake_minimum_required(VERSION 3.0)
project(Dbus_server)
include("compile/file/main.cmake")
add_executable(Dbus_server_bin src/main.cpp)
target_link_libraries(Dbus_server_bin ${compo_lib_name})
