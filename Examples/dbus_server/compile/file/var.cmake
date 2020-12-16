set(compo_project_name "dbus_server")
set(compo_lib_name "file")

set(src_file src/Data/file.cpp 
src/Structs/S1.cpp 
src/Structs/S1_serialization.cpp 
src/Structs/S2.cpp 
src/Structs/S2_serialization.cpp 
src/Structs/S1_get_set.cpp 
src/Structs/S2_get_set.cpp 
src/Structs/S1_function.cpp 
src/Structs/S2_function.cpp 
src/Structs/S1_dbus_serialization.cpp 
src/Structs/S2_dbus_serialization.cpp 
src/Structs/S1_fac.cpp 
src/Structs/S2_fac.cpp 
src/Structs/S1_builder.cpp 
src/Structs/S2_builder.cpp 
src/Interfaces/Calculator/Calculator.cpp 
src/Interfaces/test_p/test_p.cpp 
src/Interfaces/test/test.cpp 
src/Interfaces/Calculator/Calculator_fake_stream.cpp 
src/Interfaces/test_p/test_p_fake_stream.cpp 
src/Interfaces/test/test_fake_stream.cpp 
src/Interfaces/Calculator/Calculator_caller_stream.cpp 
src/Interfaces/test_p/test_p_caller_stream.cpp 
src/Interfaces/test/test_caller_stream.cpp 
src/Interfaces/Calculator/Calculator_caller_dbus.cpp 
src/Interfaces/test_p/test_p_caller_dbus.cpp 
src/Interfaces/test/test_caller_dbus.cpp 
src/Links/Link_dbus.cpp)

set(inc_file inc/Data/file.hpp 
inc/Structs/S1.hpp 
inc/Structs/S2.hpp 
inc/Structs/S1_fac.hpp 
inc/Structs/S2_fac.hpp 
inc/Structs/S1_builder.hpp 
inc/Structs/S2_builder.hpp 
inc/Interfaces/Calculator/Calculator.hpp 
inc/Interfaces/test_p/test_p.hpp 
inc/Interfaces/test/test.hpp 
inc/Interfaces/Calculator/Calculator_fake_stream.hpp 
inc/Interfaces/test_p/test_p_fake_stream.hpp 
inc/Interfaces/test/test_fake_stream.hpp 
inc/Interfaces/Calculator/Calculator_caller_stream.hpp 
inc/Interfaces/test_p/test_p_caller_stream.hpp 
inc/Interfaces/test/test_caller_stream.hpp 
inc/Interfaces/Calculator/Calculator_caller_dbus.hpp 
inc/Interfaces/test_p/test_p_caller_dbus.hpp 
inc/Interfaces/test/test_caller_dbus.hpp 
inc/Links/Link_dbus.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
