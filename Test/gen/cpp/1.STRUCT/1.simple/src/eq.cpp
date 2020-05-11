#include "catch.hpp"

#include "Data/Struct_A.hpp"
#include "Data/Struct_Square.hpp"

TEST_CASE("Struct Simple Equal", "[Struct][Equal][Simple]") {
  A a1, a2;
  REQUIRE(a1 == a2);

  a1.set_a(1);
  REQUIRE(a1 != a2);

  a2.set_a(1);
  REQUIRE(a1 == a2);
}

TEST_CASE("Struct get set", "[Struct][get_][set_][a_][Simple]") {
  A a1, a2;
  SECTION("default") { REQUIRE(a1.get_a() == 0); }

  SECTION("set/get") {
    auto r = GENERATE(range(-10, 10));
    a1.set_a(r);
    REQUIRE(a1.get_a() == r);
  }

  SECTION("get") {
    auto r = GENERATE(range(-10, 10));
    a1 = A(r);
    REQUIRE(a1.get_a() == r);
  }

  SECTION("get") {
    auto r = GENERATE(range(-10, 10));
    a1.a_a() = r;
    REQUIRE(a1.get_a() == r);
  }
}

TEST_CASE("Struct  get/set sub struct", "[Struct][get_][set_][a_][Substruct]") {
  Square s;

  Pos p1;
  auto p2 = s.get_position();

  REQUIRE(p1 == p2);

  s.get_position().set_x(1);
  REQUIRE(s.get_position().get_x() == 0);

  s.a_position().set_x(2);
  REQUIRE(s.a_position().get_x() == 2);

  auto p = s.get_position();
  p.set_x(33);
  s.set_position(p);
  REQUIRE(s.get_position().get_x() == 33);

  // s.a_position().set_x(3);
  // REQUIRE(s.get_position().get_x() == 3);

  // Pos p;
  // p.set_x(GENERATE(range(-10, 10)));
  // p.set_y(GENERATE(range(-10, 10)));
  // Dot d;
  // d.set_h(GENERATE(range(-10, 10)));
  // d.set_w(GENERATE(range(-10, 10)));

  // Square s;
  // s.set_position(p);
  // s.set_size(d);

  // test_stream(s);
}
