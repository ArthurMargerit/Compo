#include "Components/C1.hpp"
#include "Components/C2.hpp"

#include "Data/code.hpp"
#include "catch.hpp"
#include "connectors/Math_async_simple.hpp"

TEST_CASE("Connector async", "[Connector][async]") {
  C1 c1;
  C2 c2;
  Math_async_simple b;

  b.rr.set(&c2.get_back_call());
  b.r.set(&c1.get_p());
  c2.call.set(&b.get_c());

  c1.configuration();
  c2.configuration();

  c1.connection();
  c2.connection();

  c1.start();
  c2.start();

  c1.step();
  c2.step();

  c1.stop();
  c2.stop();
}

static int p_1;
static int p_2;

class I_Math : public Math {
public:
  I_Math() {}
  virtual ~I_Math() {}
  int ping(int a, int b) override { return a + b; }
  int f1(int a) override { return a + 1; }
  int f2() override { return 1; }
  void f3() override {}

  int a_a;
  int a_b;

  int get_a() const override { return a_a; }
  void set_a(const int &p_a) override { this->a_a = p_a; }
  int get_b() const override { return a_b; }
  void set_b(const int &p_b) override { this->a_b = p_b; }
};

class I_Math_return : public Math_async_return {
public:
  I_Math_return() {}
  virtual ~I_Math_return() {}

  void ping(int a) override {
    REQUIRE(a == p_1 + p_2);
    return;
  }
  void f1(int a) override {
    REQUIRE(a == p_1 + 1);
    return;
  }
  void f2(int a) override {
    REQUIRE(a == 1);
    return;
  }

  void f3() override {}

  void get_a(int p_a) override {}
  void set_a() override {}
  void get_b(int p_a) override {}
  void set_b() override {}
};

TEST_CASE("Connector async simple", "[Connector][async]") {
  Math_async_simple mas;
  I_Math_return imr;
  I_Math im;
  mas.rr.set(&imr);
  mas.r.set(&im);

  SECTION("2 arg with return") {
    auto v_1 = GENERATE(1, 2, 3, 4, 5);
    auto v_2 = GENERATE(1, 2, 3, 4, 5);
    mas.get_c().ping(p_1 = v_1, p_2 = -v_2);
  }

  SECTION("1 arg with return") {
    auto v_1 = GENERATE(1, 2, 3, 4, 5);
    mas.get_c().f1(p_1 = v_1);
  }

  SECTION("void return") { mas.get_c().f2(); }
  SECTION("void return void") { mas.get_c().f3(); }

  while (!mas.empty()) {
    mas.step();
  }
}
