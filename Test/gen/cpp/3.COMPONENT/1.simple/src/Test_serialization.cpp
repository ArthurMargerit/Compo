#include "catch.hpp"

#include "Data/code.hpp"

#include "Components/CA.hpp"
#include "Components/CAA.hpp"
#include "Components/CD.hpp"

TEST_CASE("Component data Serialization",
          "[Component][Simple][Serialization][Data]") {
  CA c, c_i;
  auto v = GENERATE(1, 2, 3, 4, 5, 6, 7);
  c.set_a(v);
  REQUIRE(c.get_a() == v);

  INFO("CA c = " << c);

  std::stringstream ss;
  ss << c;
  ss >> c_i;

  REQUIRE(c_i.get_a() == v);
  REQUIRE(c_i.get_a() == c.get_a());
}

TEST_CASE("Component sc Serialization",
          "[Component][Simple][Serialization][Data][SubComponent]") {
  CAA c, c_i;
  auto v1 = GENERATE(1, 2, 3, 4, 5, 6, 7);
  auto v2 = GENERATE(1, 2, 3, 4, 5, 6, 7);
  c.get_sc_a().set_a(v1);
  c.get_sc_b().set_a(v2);

  INFO("CAA c = " << c);
  std::stringstream ss;
  ss << c;
  ss >> c_i;

  REQUIRE(c.get_sc_a().get_a() == v1);
  REQUIRE(c_i.get_sc_a().get_a() == v1);

  REQUIRE(c.get_sc_b().get_a() == v2);
  REQUIRE(c_i.get_sc_b().get_a() == v2);
}

TEST_CASE("Component provide",
          "[Component][Simple][Serialization][Data][SubComponent]") {
  CD c, c_i;
  auto v1 = GENERATE(1, 2, 3, 4, 5, 6, 7);
  auto v2 = GENERATE(1, 2, 3, 4, 5, 6, 7);

  c.get_p1().set_a(v1);
  c.get_p2().set_a(v1 * 2);
  c.get_p3().set_a(v2);
  c.get_p4().set_a(v2 * 2);

  c.get_p1().set_b(-v1);
  c.get_p2().set_b(-v1 * 2);
  c.get_p3().set_b(-v2);
  c.get_p4().set_b(-v2 * 2);

  INFO("CAA c = " << c);
  std::stringstream ss;
  ss << c;
  ss >> c_i;

  REQUIRE(c.get_p1().get_a() == v1);
  REQUIRE(c_i.get_p1().get_a() == v1);

  REQUIRE(c.get_p2().get_a() == v1 * 2);
  REQUIRE(c_i.get_p2().get_a() == v1 * 2);

  REQUIRE(c.get_p3().get_a() == v2);
  REQUIRE(c_i.get_p3().get_a() == v2);

  REQUIRE(c.get_p4().get_a() == v2 * 2);
  REQUIRE(c_i.get_p4().get_a() == v2 * 2);

  REQUIRE(c.get_p1().get_b() == -v1);
  REQUIRE(c_i.get_p1().get_b() == -v1);

  REQUIRE(c.get_p2().get_b() == -v1 * 2);
  REQUIRE(c_i.get_p2().get_b() == -v1 * 2);

  REQUIRE(c.get_p3().get_b() == -v2);
  REQUIRE(c_i.get_p3().get_b() == -v2);

  REQUIRE(c.get_p4().get_b() == -v2 * 2);
  REQUIRE(c_i.get_p4().get_b() == -v2 * 2);
}


TEST_CASE("Component pointer",
          "[Component][Simple][Serialization][pointer]") {
  init_code();
  CA c, *c_i = NULL;
  auto v = GENERATE(1, 2, 3, 4, 5, 6, 7);
  c.set_a(v);
  INFO("CAA c = " << c);
  std::stringstream ss;
  ss << &c;
  ss >> c_i;

  REQUIRE(c_i != nullptr);
  REQUIRE(c_i->get_a() == v);
  delete c_i;
}
