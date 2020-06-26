#include "catch.hpp"
#include <sstream>

#include "Test.hpp"

#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IA/IA_caller_stream.hpp"

#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IB/IB_caller_stream.hpp"

class IB_test : public IB {
public:
  IB_test() {}
  virtual ~IB_test() {}

  void f0() override { return; }
  int f1() override { return 1; }
  int f2(int p1) override { return p1 + 1; }
  int f3(int p1, int p2) override { return p1 + p2; }
  int f4(int p1, int p2, int p3) override { return p1 + p2 + p3; }
};

class IA_test : public IA {
  int a1;
  int a2;
  int a3;

public:
  int get_a1() const override { return a1; }
  void set_a1(const int &a1) override { this->a1 = a1; }
  int get_a2() const override { return a2; }
  void set_a2(const int &a2) override { this->a2 = a2; }
  int get_a3() const override { return a3; }
  void set_a3(const int &a3) override { this->a3 = a3; }

  IA_test() {}
  virtual ~IA_test() {}
};

TEST_CASE("Interfaces Call simple get/set", "[Interface][Call][Get/Set]") {
  IA_test ia_t;
  IA_caller_stream ia_c(ia_t);
  std::stringstream so;
  std::stringstream si;

  Function_string_stream_recv fs_c(so);
  Return_string_stream_send rs_c(si);
  SECTION("set") {
    auto v = GENERATE(1, 2, 3, 4, 5, 6);
    so << "set_a1(" << v << ")";
    REQUIRE(ia_c.call(fs_c, rs_c) == true);
    REQUIRE(ia_t.get_a1() == v);
  }

  SECTION("get") {
    auto v = GENERATE(1, 2, 3, 4, 5, 6);
    ia_t.set_a1(v);

    so << "get_a1()";
    REQUIRE(ia_c.call(fs_c, rs_c) == true);
    int a;
    si >> a;
    REQUIRE(a == v);
  }

  SECTION("set/get") {
    auto v = GENERATE(1, 2, 3, 4, 5, 6);
    so << "set_a1(" << v << ")";
    REQUIRE(ia_c.call(fs_c, rs_c) == true);

    so << "get_a1()";
    REQUIRE(ia_c.call(fs_c, rs_c) == true);
    int a;
    si >> a;
    REQUIRE(a == v);
  }
}

TEST_CASE("Interfaces Call simple function", "[Interface][Call][Function]") {

  IB_test ib_t;
  IB_caller_stream ib_c(ib_t);
  std::stringstream so;
  std::stringstream si;

  Function_string_stream_recv fs_c(so);
  Return_string_stream_send rs_c(si);
  SECTION("f0 - just call") {
    so << "f0()";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
  }

  SECTION("f1 - just return") {
    so << "f1()";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    int a = 0;
    si >> a;
    REQUIRE(a == 1);
  }

  SECTION("f2 - 1 params and return") {
    auto v1 = GENERATE(1, 2, 3, 4, 5);

    so << "f2(" << v1 << ")";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    int a = 0;
    si >> a;
    REQUIRE(a == (v1 + 1));
  }

  SECTION("f3 - 2 params and return") {
    auto v1 = GENERATE(1, 2, 3, 4, 5);
    auto v2 = GENERATE(1, 2, 3, 4, 5);

    so << "f3(" << v1 << "," << v2 << ")";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    int a = 0;
    si >> a;
    REQUIRE(a == (v1 + v2));
  }

  SECTION("f4 - 3 params and return") {
    auto v1 = GENERATE(-1, -2, 0, 1, 2);
    auto v2 = GENERATE(-1, -2, 0, 1, 2);
    auto v3 = GENERATE(-1, -2, 0, 1, 2);

    so << "f4(" << v1 << "," << v2 << "," << v3 << ")";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    int a = 0;
    si >> a;
    REQUIRE(a == (v1 + v2 + v3));
  }
}
