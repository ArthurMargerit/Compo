set(compo_project_name "CompoMe_Port")
set(compo_lib_name "CompoMe_Port")

set(src_file src/Data/CompoMe_Port.cpp 
src/Ports/CompoMe/Stream/in.cpp 
src/Ports/CompoMe/Stream/out.cpp 
src/Ports/CompoMe/Stream/map_in.cpp 
src/Ports/CompoMe/Stream/map_out.cpp 
src/Ports/CompoMe/Stream/in_get_set.cpp 
src/Ports/CompoMe/Stream/out_get_set.cpp 
src/Ports/CompoMe/Stream/map_in_get_set.cpp 
src/Ports/CompoMe/Stream/map_out_get_set.cpp 
src/Ports/CompoMe/Stream/in_function.cpp 
src/Ports/CompoMe/Stream/out_function.cpp 
src/Ports/CompoMe/Stream/map_in_function.cpp 
src/Ports/CompoMe/Stream/map_out_function.cpp)

set(inc_file inc/Data/CompoMe_Port.hpp 
inc/Data/CompoMe_Port_template.hpp 
inc/Ports/CompoMe/Stream/in.hpp 
inc/Ports/CompoMe/Stream/out.hpp 
inc/Ports/CompoMe/Stream/map_in.hpp 
inc/Ports/CompoMe/Stream/map_out.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
