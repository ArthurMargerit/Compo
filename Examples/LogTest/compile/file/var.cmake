set(compo_project_name "LogTest")
set(compo_lib_name "file")

set(src_file src/Data/file.cpp 
src/Deployments/Log_server/Log_server_get_set.cpp 
src/Deployments/Log_server/Log_server.cpp)

set(inc_file inc/Data/file.hpp 
inc/Data/file_template.hpp 
inc/Deployments/Log_server/Log_server.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
