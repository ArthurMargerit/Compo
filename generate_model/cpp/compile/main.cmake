

list(APPEND CMAKE_MODULE_PATH "compile/{{FILE.replace('.yaml','')}}")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)

include(CompoMe)
include(CompoMe_Swig)

include("${CMAKE_CURRENT_LIST_DIR}/var.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/log.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/option.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/import.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/links.cmake")

project(${compo_project_name})

add_library(${compo_lib_name} ${src_file})

set_property(TARGET ${compo_lib_name} PROPERTY POSITION_INDEPENDENT_CODE ON)
set_target_properties(${compo_lib_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY lib/)
set_target_properties(${compo_lib_name} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib/)
target_include_directories(${compo_lib_name} PUBLIC ${_include_directories})
target_link_libraries(${compo_lib_name} ${_links_lib} ${_links_lib} ${_links_dir})
include("${CMAKE_CURRENT_LIST_DIR}/install.cmake")
