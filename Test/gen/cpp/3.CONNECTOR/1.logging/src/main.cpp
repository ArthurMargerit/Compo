#define COMPOME_LOG 1
#include "catch.hpp"

#include "CompoMe/Log.hpp"
#include "Components/CompoMe/Log/To_File.hpp"
#include "Structs/test_struct.hpp"


void LOG_SIMPLE() {
  {
    C_ERROR("Error message");
    C_ERROR("Error message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_ERROR("Error message with struct ", ms1);
    C_ERROR("Error message with struct ", ms2);
  }

  {
    C_WARNING("WARNING message");
    C_WARNING("WARNING message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_WARNING("WARNING message with struct ", ms1);
    C_WARNING("WARNING message with struct ", ms2);
  }

  {
    C_INFO("Info message");
    C_INFO("Info message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_INFO("Info message with struct ", ms1);
    C_INFO("Info message with struct ", ms2);
  }

  {
    C_DEBUG("Debug message");
    C_DEBUG("Debug message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_DEBUG("Debug message with struct ", ms1);
    C_DEBUG("Debug message with struct ", ms2);
  }
}

void LOG_WITH_TAG() {
  {
    C_ERROR_TAG("tag", "Error message");
    C_ERROR_TAG("tag", "Error message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_ERROR_TAG("tag", "Error message with struct ", ms1);
    C_ERROR_TAG("tag", "Error message with struct ", ms2);
  }

  {
    C_WARNING_TAG("tag", "WARNING message");
    C_WARNING_TAG("tag", "WARNING message with data du to a=", 1,
                  " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_WARNING_TAG("tag", "WARNING message with struct ", ms1);
    C_WARNING_TAG("tag", "WARNING message with struct ", ms2);
  }

  {
    C_INFO_TAG("tag", "Info message");
    C_INFO_TAG("tag", "Info message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_INFO_TAG("tag", "Info message with struct ", ms1);
    C_INFO_TAG("tag", "Info message with struct ", ms2);
  }

  {
    C_DEBUG_TAG("tag", "Debug message");
    C_DEBUG_TAG("tag", "Debug message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_DEBUG_TAG("tag", "Debug message with struct ", ms1);
    C_DEBUG_TAG("tag", "Debug message with struct ", ms2);
  }
}

void LOG_WITH_TO() {
  CompoMe::Log::To_File tf;
  tf.set_path("log_1.txt");
  tf.start();

  CompoMe::Require_helper_t<CompoMe::Log::Log_I> new_log = &tf.log;
  {
    C_TO_ERROR(new_log, "Error message");
    C_TO_ERROR(new_log, "Error message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_TO_ERROR(new_log, "Error message with struct ", ms1);
    C_TO_ERROR(new_log, "Error message with struct ", ms2);
  }

  {
    C_TO_WARNING(new_log, "WARNING message");
    C_TO_WARNING(new_log, "WARNING message with data du to a=", 1,
                 " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_TO_WARNING(new_log, "WARNING message with struct ", ms1);
    C_TO_WARNING(new_log, "WARNING message with struct ", ms2);
  }

  {
    C_TO_INFO(new_log, "Info message");
    C_TO_INFO(new_log, "Info message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_TO_INFO(new_log, "Info message with struct ", ms1);
    C_TO_INFO(new_log, "Info message with struct ", ms2);
  }

  {
    C_TO_DEBUG(new_log, "Debug message");
    C_TO_DEBUG(new_log, "Debug message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_TO_DEBUG(new_log, "Debug message with struct ", ms1);
    C_TO_DEBUG(new_log, "Debug message with struct ", ms2);
  }

  tf.stop();
}

void LOG_WITH_TAG_AND_TO() {
  CompoMe::Log::To_File tf;

  tf.set_path("log_2.txt");
  tf.start();

  CompoMe::Require_helper_t<CompoMe::Log::Log_I> new_log = &tf.log;
  {
    C_TO_ERROR_TAG(new_log, "tag1,tag2,tag3", "Error message");
    C_TO_ERROR_TAG(new_log, "tag1,tag2,tag3",
                   "Error message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_TO_ERROR_TAG(new_log, "tag1,tag2,tag3", "Error message with struct ",
                   ms1);
    C_TO_ERROR_TAG(new_log, "tag1,tag2,tag3", "Error message with struct ",
                   ms2);
  }

  {
    C_TO_WARNING_TAG(new_log, "tag1,tag2,tag3", "WARNING message");
    C_TO_WARNING_TAG(new_log, "tag1,tag2,tag3",
                     "WARNING message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_TO_WARNING_TAG(new_log, "tag1,tag2,tag3", "WARNING message with struct ",
                     ms1);
    C_TO_WARNING_TAG(new_log, "tag1,tag2,tag3", "WARNING message with struct ",
                     ms2);
  }

  {
    C_TO_INFO_TAG(new_log, "tag1,tag2,tag3", "Info message");
    C_TO_INFO_TAG(new_log, "tag1,tag2,tag3",
                  "Info message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_TO_INFO_TAG(new_log, "tag1,tag2,tag3", "Info message with struct ", ms1);
    C_TO_INFO_TAG(new_log, "tag1,tag2,tag3", "Info message with struct ", ms2);
  }

  {
    C_TO_DEBUG_TAG(new_log, "tag1,tag2,tag3", "Debug message");
    C_TO_DEBUG_TAG(new_log, "tag1,tag2,tag3",
                   "Debug message with data du to a=", 1, " and b=", 10);
    test_sub_struct ms1;
    test_struct ms2;
    C_TO_DEBUG_TAG(new_log, "tag1,tag2,tag3", "Debug message with struct ",
                   ms1);
    C_TO_DEBUG_TAG(new_log, "tag1,tag2,tag3", "Debug message with struct ",
                   ms2);
  }

  tf.stop();
}

TEST_CASE("Connector logger", "[Connector][logger]") {
  LOG_SIMPLE();
  LOG_WITH_TAG();
  LOG_WITH_TO();
  LOG_WITH_TAG_AND_TO();
}
