set(compo_project_name "Interface")
set(compo_lib_name "file")

set(src_file src/Data/file.cpp 
src/Structs/Range.cpp 
src/Structs/Range_serialization.cpp 
src/Structs/Range_get_set.cpp 
src/Structs/Range_function.cpp 
src/Structs/Range_fac.cpp 
src/Structs/Range_builder.cpp 
src/Interfaces/Information/Information.cpp 
src/Interfaces/Sensor/Sensor.cpp 
src/Interfaces/Sensor_v2/Sensor_v2.cpp 
src/Interfaces/Information/Information_fake_stream.cpp 
src/Interfaces/Sensor/Sensor_fake_stream.cpp 
src/Interfaces/Sensor_v2/Sensor_v2_fake_stream.cpp 
src/Interfaces/Information/Information_caller_stream.cpp 
src/Interfaces/Sensor/Sensor_caller_stream.cpp 
src/Interfaces/Sensor_v2/Sensor_v2_caller_stream.cpp)

set(inc_file inc/Data/file.hpp 
inc/Data/file_template.hpp 
inc/Structs/Range.hpp 
inc/Structs/Range_fac.hpp 
inc/Structs/Range_builder.hpp 
inc/Interfaces/Information/Information.hpp 
inc/Interfaces/Sensor/Sensor.hpp 
inc/Interfaces/Sensor_v2/Sensor_v2.hpp 
inc/Interfaces/Information/Information_fake_stream.hpp 
inc/Interfaces/Sensor/Sensor_fake_stream.hpp 
inc/Interfaces/Sensor_v2/Sensor_v2_fake_stream.hpp 
inc/Interfaces/Information/Information_caller_stream.hpp 
inc/Interfaces/Sensor/Sensor_caller_stream.hpp 
inc/Interfaces/Sensor_v2/Sensor_v2_caller_stream.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
