set(compo_project_name "tmp")
set(compo_lib_name "b")

set(src_file src/Data/b.cpp 
src/Components/C2.cpp 
src/Components/C2_serialization.cpp 
src/Components/C2_function.cpp 
src/Components/C2_get_set.cpp 
src/Components/C2_fac.cpp 
src/Components/C2_Math_async_return_back_call.cpp 
src/Components/C2_Math_async_return_back_call_get_set.cpp 
src/Components/C2_Math_async_return_back_call_fac.cpp 
src/Components/C2_Math_async_return_back_call_function.cpp)

set(inc_file inc/Data/b.hpp 
inc/Components/C2.hpp 
inc/Components/C2_fac.hpp 
inc/Components/C2_Math_async_return_back_call.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR} OPTIONAL)
