cmake_minimum_required(VERSION 3.5.1)

PROJECT("compo_test")

link_directories("../Compome_cpp/Base")
link_directories("../Compome_cpp/Base_types")
link_directories("../Compome_cpp/Base_utils")

SET(CMAKE_CXX_STANDARD 14)
FILE(GLOB_RECURSE file_compo src/*.cpp)

add_executable(dep1 ${file_compo})

target_include_directories(dep1 PUBLIC "inc")
target_include_directories(dep1 PUBLIC "../Compome_cpp/Base/inc")
target_include_directories(dep1 PUBLIC "../Compome_cpp/Base_types/inc")
target_include_directories(dep1 PUBLIC "../Compome_cpp/Base_links/inc")
target_include_directories(dep1 PUBLIC "../Compome_cpp/Base_utils/inc")


target_link_libraries(dep1 LINK_PUBLIC Base)
target_link_libraries(dep1 LINK_PUBLIC Base_types)
target_link_libraries(dep1 LINK_PUBLIC Base_utils)

