#include "catch.hpp"
#define COMPOME_LOG
#include "CompoMe/Log.hpp"
#include <unistd.h>

TEST_CASE("logger", "[logger]") {
  C_DEBUG_TAG("Debug message", "init");
  C_INFO_TAG("Info message", "init");
  C_WARNING_TAG("Warning message", "init");
  C_ERROR_TAG("Error message", "init");

  sleep(1);
  C_DEBUG_TAG("Debug message", "init");
  C_INFO_TAG("Info message", "init");
  C_WARNING_TAG("Warning message", "init");
  C_ERROR_TAG("Error message", "init");

  sleep(1);
  C_DEBUG_TAG("Debug message", "init");
  C_INFO_TAG("Info message", "init");
  C_WARNING_TAG("Warning message", "init");
  C_ERROR_TAG("Error message", "init");

  C_DEBUG("Debug message");
  C_INFO("Info message");
  C_WARNING("Warning message");
  C_ERROR("Error message");

  sleep(1);
  C_DEBUG("Debug message");
  C_INFO("Info message");
  C_WARNING("Warning message");
  C_ERROR("Error message");

  sleep(1);
  C_DEBUG("Debug message");
  C_INFO("Info message");
  C_WARNING("Warning message");
  C_ERROR("Error message");
}
