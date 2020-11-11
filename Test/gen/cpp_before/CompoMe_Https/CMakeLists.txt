cmake_minimum_required(VERSION 3.0)

PROJECT("CompoMe")

SET(CMAKE_CXX_STANDARD 11)
cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

include("compile/var.cmake")
include("compile/import.cmake")
include("compile/links.cmake")

FILE(GLOB_RECURSE file_compo src/*.cpp)

# OPTION ######################################################################
option(COMPOME_LOG_D "ACTIVATE/DESACTIVATE log system")
add_compile_definitions(COMPOME_LOG=0)

add_library(${compo_project_name} SHARED ${file_compo})
target_include_directories(${compo_project_name} PUBLIC ${_include_directories})
target_link_libraries(${compo_project_name} ${_links_lib})
set_property(TARGET
  ${compo_project_name}
  PROPERTY POSITION_INDEPENDENT_CODE ON)

install(TARGETS
  ${compo_project_name}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(DIRECTORY inc/ DESTINATION inc
  FILES_MATCHING PATTERN "*.hpp")

install(FILES ${compo_project_name}.yaml DESTINATION .)
install(FILES compile/${compo_project_name}_links.cmake DESTINATION compile)
install(FILES compile/${compo_project_name}_import.cmake DESTINATION compile)

include(CompoMe_Swig.cmake)
