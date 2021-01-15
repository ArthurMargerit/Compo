#define COMPOME_LOG 1
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include "CompoMe/Log.hpp"
#include "Components/CompoMe/Log/To_File.hpp"
#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"
#include "catch.hpp"
#include "unistd.h"

TEST_CASE("Log system to file", "[Log][to_stream]") {

  {
    CompoMe::Log::To_File lo;
    lo.set_path("/tmp/log.log");
    lo.configuration();
    lo.connection();
    lo.start();

    CompoMe::Require_helper_t<CompoMe::Log::Log_I> l = &lo.get_log();

    C_TO_ERROR(l, "a");
    C_TO_WARNING(l, "b");
    C_TO_DEBUG(l, "c");
    C_TO_INFO(l, "d");

    C_TO_ERROR_TAG(l, "TAG", "a");
    C_TO_WARNING_TAG(l, "TAG", "b");
    C_TO_DEBUG_TAG(l, "TAG", "c");
    C_TO_INFO_TAG(l, "TAG", "d");

    lo.step();
    lo.stop();
  }

  // check log file ///////////////////////////////////////////////////////////
  std::ifstream is;
  is.open("/tmp/log.log");

  ui64 v1 = 0, v2 = 0;
  ui64 v1_p = 0, v2_p = 0;

  std::string kind;     // kind of log
  CompoMe::String mess; // main messsage
  std::string tag;      // tag
  std::string file;     // path:file
  ui32 n;               // num ligne
  ui32 nb_log = 0;      // how many log

  do {
    is >> v1;
    REQUIRE(':' == is.get());
    is >> v2;
    REQUIRE(' ' == is.get());
    is >> kind;
    bool t_k = (kind == "ERROR" || kind == "WARNING" || kind == "DEBUG" ||
                kind == "INFO");
    REQUIRE(t_k == true);

    REQUIRE(' ' == is.get());
    is >> mess;
    INFO(mess);
    bool t_m = (mess == "a" || mess == "b" || mess == "c" || mess == "d");
    REQUIRE(t_m == true);

    is >> tag;
    bool t_t = (tag == "None" || tag == "TAG");
    REQUIRE(t_t == true);
    REQUIRE(' ' == is.get());

    std::getline(is, file, ':');
    REQUIRE(file == __FILE__);
    is >> n;

    // check if chrono is sort
    REQUIRE(v1 >= v1_p);
    double v = v1 + (v2 * 0.000001);
    double v_p = v1_p + (v2_p * 0.000001);
    REQUIRE(v > v_p);
    v1_p = v1;
    v2_p = v2;

    nb_log++;
  } while (is.get() == '\n' && is.peek() != EOF);

  REQUIRE(8 == nb_log);
}

TEST_CASE("log each second") {

  C_INFO("test to put a bool ", true);
  C_INFO("test to put a int ", 1);
  C_INFO("test to put a double ", 1.26);
  C_INFO("test to put a float ", 0.32);
  Vec<int> v = {1, 2, 3};
  C_INFO("test to put a vector ", v);

  std::map<CompoMe::String, CompoMe::String> s;
  s["A"] = "B";
  s["C"] = "D";
  s["E"] = "F";
  s["G"] = "H";
  C_INFO("test to put a map ", s);

  C_INFO("test to put a CompoMe::String ", CompoMe::String("test"));
}

TEST_CASE("Compilation test") {
  for (int i = 0; i < 2; ++i) {
    sleep(1);
    C_INFO("wait the ", i, "s");
  }
}

void log_to_file(ui64 p_i) {
  CompoMe::Log::To_File lo;
  lo.configuration();
  lo.connection();
  lo.start();

  CompoMe::Require_helper_t<CompoMe::Log::Log_I> l = &lo.get_log();
  for (ui64 i = 0; i < p_i; ++i) {
    C_TO_INFO_TAG(l, "wait the ", i, "s");
  }

  lo.step();
  auto l_p = lo.get_path();
  lo.stop();
  std::remove(l_p.str.c_str());
}

TEST_CASE("bench") {
  for (int i = 0; i < 10; i++) {
    std::stringstream ss;
    ss << "nb i=" << i*i*i*i*i;
    BENCHMARK(ss.str(), i) { log_to_file(i*i*i*i*i); };
  }
}
