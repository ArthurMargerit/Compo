cmake_minimum_required(VERSION 3.0)

PROJECT("CompoMe")

include("compile/var.cmake")
include("compile/import.cmake")
include("compile/links.cmake")
# add_definitions(-D COMPOME_LOG=1)
SET(CMAKE_CXX_STANDARD 11)
FILE(GLOB_RECURSE file_compo src/*.cpp)

add_library(${compo_project_name}_static STATIC ${file_compo})
# add_library(${compo_project_name}_shared SHARED ${file_compo})
# add_library(${compo_project_name}_module MODULE ${file_compo})

target_include_directories(${compo_project_name}_static PUBLIC ${_include_directories})
# target_include_directories(${compo_project_name}_module PUBLIC ${_include_directories})
# target_include_directories(${compo_project_name}_shared PUBLIC ${_include_directories})

target_link_libraries(${compo_project_name}_static ${_links_lib})
# target_link_libraries(${compo_project_name}_module ${_links_lib})
# target_link_libraries(${compo_project_name}_shared ${_links_lib})


set_property(TARGET
  ${compo_project_name}_static
  # ${compo_project_name}_module
  # ${compo_project_name}_shared
  PROPERTY POSITION_INDEPENDENT_CODE ON)

install(TARGETS
  ${compo_project_name}_static
  # ${compo_project_name}_shared
  # ${compo_project_name}_module
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(DIRECTORY inc/ DESTINATION inc
  FILES_MATCHING PATTERN "*.hpp")

install(FILES ${compo_project_name}.yaml DESTINATION .)
install(FILES compile/${compo_project_name}_links.cmake DESTINATION compile)
install(FILES compile/${compo_project_name}_import.cmake DESTINATION compile)
