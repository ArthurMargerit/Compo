set(compo_project_name "HelloWord")
set(compo_lib_name "file")

set(src_file src/Data/file.cpp 
src/Interfaces/Hello_I/Hello_I.cpp 
src/Interfaces/Hello_I/Hello_I_fake_stream.cpp 
src/Interfaces/Hello_I/Hello_I_caller_stream.cpp 
src/Components/HelloWord.cpp 
src/Components/HelloWord_serialization.cpp 
src/Components/HelloWord_function.cpp 
src/Components/HelloWord_get_set.cpp 
src/Components/HelloWord_fac.cpp 
src/Components/HelloWord_Hello_I_inter.cpp 
src/Components/HelloWord_Hello_I_inter_get_set.cpp 
src/Components/HelloWord_Hello_I_inter_fac.cpp 
src/Components/HelloWord_Hello_I_inter_function.cpp 
src/Deployments/HelloWord_server/HelloWord_server.cpp 
src/Deployments/HelloWord_server/HelloWord_server_get_set.cpp)

set(inc_file inc/Data/file.hpp 
inc/Interfaces/Hello_I/Hello_I.hpp 
inc/Interfaces/Hello_I/Hello_I_fake_stream.hpp 
inc/Interfaces/Hello_I/Hello_I_caller_stream.hpp 
inc/Components/HelloWord.hpp 
inc/Components/HelloWord_fac.hpp 
inc/Components/HelloWord_Hello_I_inter.hpp 
inc/Deployments/HelloWord_server/HelloWord_server.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
