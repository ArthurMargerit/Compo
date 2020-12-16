set(compo_project_name "Serialization")
set(compo_lib_name "file")

set(src_file src/Serialization_context.cpp 
src/Data/file.cpp 
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
src/Structs/User_builder.cpp 
src/Structs/Struct.cpp 
src/Errors/Error.cpp 
src/Interfaces/Interface.cpp 
src/Interfaces/Fake_stream.cpp 
src/Interfaces/Caller_stream.cpp 
src/Components/Component.cpp 
src/connectors/Async/Async_Connector.cpp 
src/connectors/Async/Async_Call.cpp 
src/Links/Link.cpp 
src/Deployments/Deployment.cpp)

set(inc_file inc/Serialization_context.hpp 
inc/Data/file.hpp 
inc/Structs/File.hpp 
inc/Structs/User.hpp 
inc/Structs/File_fac.hpp 
inc/Structs/User_fac.hpp 
inc/Structs/File_builder.hpp 
inc/Structs/User_builder.hpp 
inc/Structs/Struct.hpp 
inc/Errors/Error.hpp 
inc/Interfaces/Interface.hpp 
inc/Interfaces/Fake_stream.hpp 
inc/Interfaces/Caller_stream.hpp 
inc/Interfaces/Return_stream_send.hpp 
inc/Interfaces/Return_stream_recv.hpp 
inc/Interfaces/Function_stream_send.hpp 
inc/Interfaces/Function_stream_recv.hpp 
inc/Components/Component.hpp 
inc/Components/Require_helper.hpp 
inc/Components/Require_helper_multi.hpp 
inc/connectors/Async/Async_Connector.hpp 
inc/connectors/Async/Async_Call.hpp 
inc/Links/Link.hpp 
inc/Deployments/Deployment.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
