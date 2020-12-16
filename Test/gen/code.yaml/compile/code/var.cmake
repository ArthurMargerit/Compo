set(compo_project_name "code.yaml")
set(compo_lib_name "code")

set(src_file src/Types/B/i.cpp 
src/Data/code.cpp 
src/Structs/S1.cpp 
src/Structs/S1_serialization.cpp 
src/Structs/S/S2.cpp 
src/Structs/S/S2_serialization.cpp 
src/Structs/S1_get_set.cpp 
src/Structs/S/S2_get_set.cpp 
src/Structs/S1_function.cpp 
src/Structs/S/S2_function.cpp 
src/Structs/S1_fac.cpp 
src/Structs/S/S2_fac.cpp 
src/Structs/S1_builder.cpp 
src/Structs/S/S2_builder.cpp 
src/Interfaces/II/I1/I1.cpp 
src/Interfaces/II/I1/I1_fake_stream.cpp 
src/Interfaces/II/I1/I1_caller_stream.cpp 
src/Components/C/C1.cpp 
src/Components/C/C1_serialization.cpp 
src/Components/C/C1_function.cpp 
src/Components/C/C1_get_set.cpp 
src/Components/C/C1_fac.cpp 
src/Components/C/C1_I1_p1.cpp 
src/Components/C/C1_I1_p1_get_set.cpp 
src/Components/C/C1_I1_p1_fac.cpp 
src/Components/C/C1_I1_p1_function.cpp 
src/Deployments/D1/D1.cpp 
src/Deployments/A/D1/D1.cpp 
src/Deployments/B/D1/D1.cpp 
src/Deployments/B/A/D1/D1.cpp 
src/Deployments/A/B/D1/D1.cpp 
src/Deployments/D1/A/A.cpp 
src/Deployments/D1/D1_get_set.cpp 
src/Deployments/A/D1/D1_get_set.cpp 
src/Deployments/B/D1/D1_get_set.cpp 
src/Deployments/B/A/D1/D1_get_set.cpp 
src/Deployments/A/B/D1/D1_get_set.cpp 
src/Deployments/D1/A/A_get_set.cpp)

set(inc_file inc/Types/B/i.hpp 
inc/Data/code.hpp 
inc/Structs/S1.hpp 
inc/Structs/S/S2.hpp 
inc/Structs/S1_fac.hpp 
inc/Structs/S/S2_fac.hpp 
inc/Structs/S1_builder.hpp 
inc/Structs/S/S2_builder.hpp 
inc/Interfaces/II/I1/I1.hpp 
inc/Interfaces/II/I1/I1_fake_stream.hpp 
inc/Interfaces/II/I1/I1_caller_stream.hpp 
inc/Components/C/C1.hpp 
inc/Components/C/C1_fac.hpp 
inc/Components/C/C1_I1_p1.hpp 
inc/Deployments/D1/D1.hpp 
inc/Deployments/A/D1/D1.hpp 
inc/Deployments/B/D1/D1.hpp 
inc/Deployments/B/A/D1/D1.hpp 
inc/Deployments/A/B/D1/D1.hpp 
inc/Deployments/D1/A/A.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
