#include "Data/code.hpp"

#include "catch.hpp"
#include <sstream>

#include "Test.hpp"

#include "Errors/E1.hpp"
#include "Errors/E2.hpp"
#include "Errors/E3.hpp"

#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IA/IA_caller_stream.hpp"

#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IB/IB_caller_stream.hpp"

class IB_test_error : public IB {
public:
  IB_test_error() {}
  virtual ~IB_test_error() {}

  void f0() override {
    throw E1();
    return;
  }

  int f1() override {
    throw E2();
    return 1;
  }
  int f2(int p1) override {
    throw E3();
    return p1 + 1;
  }
  int f3(int p1, int p2) override { return p1 + p2; }
  int f4(int p1, int p2, int p3) override { return p1 + p2 + p3; }
};

TEST_CASE("Interfaces Call Error Function",
          "[Interface][Call][Function][Error]") {
  init_code();
  IB_test_error ib_t;
  IB_caller_stream ib_c(ib_t);

  std::stringstream so;
  std::stringstream si;

  Function_string_stream_recv fs_c(so);
  Return_string_stream_send rs_c(si);
  SECTION("f0 - just a error") {
    so << "f0()";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    INFO("Error " << si.str());

    REQUIRE(si.get() == '!');
    REQUIRE(si.str().find("type:E1") != std::string::npos);
    REQUIRE(si.str().find("addr:") != std::string::npos);

    CompoMe::Error* e;
    si >> e;
    REQUIRE(e->what() == "-> Error\n-> E1\n");
  }

  SECTION("f1 - just a error") {
    so << "f1()";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    INFO("Error " << si.str());

    REQUIRE(si.get() == '!');
    REQUIRE(si.str().find("type:E2") != std::string::npos);
    REQUIRE(si.str().find("addr:") != std::string::npos);

    CompoMe::Error* e;
    si >> e;
    REQUIRE(e->what() == "-> Error\n-> E2\n");
  }

  SECTION("f2 - just a error") {
    so << "f2(0)";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    INFO("Error " << si.str());

    REQUIRE(si.get() == '!');
    REQUIRE(si.str().find("type:E3") != std::string::npos);
    REQUIRE(si.str().find("addr:") != std::string::npos);

    CompoMe::Error* e;
    si >> e;
    REQUIRE(e->what() == "-> Error\n-> E3\n");
  }
}
