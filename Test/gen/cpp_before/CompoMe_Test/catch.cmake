
add_library(Catch_static STATIC src/catch.cpp )
target_include_directories(Catch_static PUBLIC inc)

add_library(Catch_thread_static STATIC src/catch_thread.cpp )
target_include_directories(Catch_thread_static PUBLIC inc)

install(TARGETS Catch_static Catch_thread_static)
