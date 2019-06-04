cmake_minimum_required(VERSION 3.0)

link_directories("../../lib_model/CPP/BASE")
link_directories("../../lib_model/CPP/BASE_TYPES")
link_directories("../../lib_model/CPP/BASE_Link")

PROJECT("project")

SET(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE file_compo src/*.cpp src/**/*.cpp)


add_executable(project1  ${file_compo})

target_include_directories(project1 PUBLIC "inc" "../../lib_model/CPP/BASE_TYPES/inc" "../../lib_model/CPP/BASE/inc" "../../lib_model/CPP/BASE_LINK/inc")


target_link_libraries(project1 LINK_PUBLIC base_shared)
target_link_libraries(project1 LINK_PUBLIC Types_shared)
target_link_libraries(project1 LINK_PUBLIC pthread)
