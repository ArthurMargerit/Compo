cmake_minimum_required(VERSION 3.0)

include("compile/var.cmake")
project("compo_test")

set(CMAKE_CXX_STANDARD 11)
file(GLOB_RECURSE file_compo src/*.cpp)

add_executable(dep1 ${file_compo})
target_compile_options(dep1 PRIVATE -Wall -Wextra -pedantic -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-private-field -Wno-string-plus-int)

include("compile/import.cmake")
target_include_directories(dep1 PUBLIC ${_include_directories})

include("compile/links.cmake")
target_link_libraries(dep1 ${_links_lib})
