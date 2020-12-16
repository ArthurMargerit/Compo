set(compo_project_name "SwigWithMe")
set(compo_lib_name "file")

set(src_file src/Data/file.cpp 
src/Interfaces/Calc_I/Calc_I.cpp 
src/Interfaces/Calc_I/Calc_I_fake_stream.cpp 
src/Interfaces/Calc_I/Calc_I_caller_stream.cpp 
src/Components/Compute.cpp 
src/Components/Compute_serialization.cpp 
src/Components/Compute_function.cpp 
src/Components/Compute_get_set.cpp 
src/Components/Compute_fac.cpp 
src/Components/Compute_Calc_I_compute.cpp 
src/Components/Compute_Calc_I_compute_get_set.cpp 
src/Components/Compute_Calc_I_compute_fac.cpp 
src/Components/Compute_Calc_I_compute_function.cpp)

set(inc_file inc/Data/file.hpp 
inc/Interfaces/Calc_I/Calc_I.hpp 
inc/Interfaces/Calc_I/Calc_I_fake_stream.hpp 
inc/Interfaces/Calc_I/Calc_I_caller_stream.hpp 
inc/Components/Compute.hpp 
inc/Components/Compute_fac.hpp 
inc/Components/Compute_Calc_I_compute.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
