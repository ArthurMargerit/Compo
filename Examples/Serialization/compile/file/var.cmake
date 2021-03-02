set(compo_project_name "Serialization")
set(compo_lib_name "file")

set(src_file src/Data/file.cpp 
src/Structs/File.cpp 
src/Structs/File_serialization.cpp 
src/Structs/User.cpp 
src/Structs/User_serialization.cpp 
src/Structs/File_get_set.cpp 
src/Structs/User_get_set.cpp 
src/Structs/File_function.cpp 
src/Structs/User_function.cpp 
src/Structs/File_fac.cpp 
src/Structs/User_fac.cpp 
src/Structs/File_builder.cpp 
src/Structs/User_builder.cpp)

set(inc_file inc/Data/file.hpp 
inc/Data/file_template.hpp 
inc/Structs/File.hpp 
inc/Structs/User.hpp 
inc/Structs/File_fac.hpp 
inc/Structs/User_fac.hpp 
inc/Structs/File_builder.hpp 
inc/Structs/User_builder.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
