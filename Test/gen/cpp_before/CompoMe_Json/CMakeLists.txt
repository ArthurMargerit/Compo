cmake_minimum_required(VERSION 3.14)

PROJECT("CompoMe_Json")
include("compile/CompoMe_Json/main.cmake")

include(FetchContent)

#
# WARNING COMPOME have to functionnal without COMPOME_JSON
# IF you change the version to not forget to copy json_fwd to compome cpp generator
#
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(JSON_BuildTests OFF CACHE INTERNAL "") #Disable json tests
set(JSON_Install OFF)
FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2)
FetchContent_MakeAvailable(json)
