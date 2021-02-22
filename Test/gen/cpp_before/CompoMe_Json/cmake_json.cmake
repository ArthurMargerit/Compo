

add_library(json src/json.cpp)
target_include_directories(json PUBLIC inc)

add_executable(json_code src/main.cpp)
target_include_directories(json_code PUBLIC inc)
target_link_libraries(json_code PUBLIC json)
