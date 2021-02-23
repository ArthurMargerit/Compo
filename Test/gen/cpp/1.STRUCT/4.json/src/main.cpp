#include "catch.hpp"

#include "Structs/A.hpp"
#include "Structs/AA.hpp"
#include "Structs/Square.hpp"
#include "json.hpp"
#include <iostream>

TEST_CASE("Struct serialization on json struct with parent",
          "[Struct][Serialization][Simple][int][json]") {
  // data
  AA a, b;
  a.set_a(1);
  a.set_c(10);

  // serialization_context output
  nlohmann::json iter;

  CompoMe::Serialization_context_export l_ctx_e;
  a.to_stream(iter, l_ctx_e);
  std::cout << iter << std::endl;

  CompoMe::Serialization_context_import l_ctx_i;
  b.from_stream(iter, l_ctx_i);

  // test
  REQUIRE(b.get_a() == 1);
  REQUIRE(b.get_c() == 10);
  REQUIRE(b == a);
}

TEST_CASE("Struct serialization on json message of one field Struct ",
          "[Struct][Serialization][Simple][int][json]") {

  // data
  A a, b;
  a.set_a(1);

  nlohmann::json iter;

  CompoMe::Serialization_context_export l_ctx_e;
  a.to_stream(iter, l_ctx_e);
  CompoMe::Serialization_context_import l_ctx_i;
  b.from_stream(iter, l_ctx_i);

  // test
  REQUIRE(b.get_a() == 1);
  REQUIRE(b == a);
}

TEST_CASE("Struct serialization on json message of sub struct field Struct ",
          "[Struct][Serialization][Simple][int][json]") {
  Square s, s_i;
  s.a_position().a_x() = GENERATE(range(-5, 5));
  s.a_position().a_x() = GENERATE(range(-5, 5));
  s.a_size().a_h() = GENERATE(range(-5, 5));
  s.a_size().a_w() = GENERATE(range(-5, 5));

  nlohmann::json iter;

  CompoMe::Serialization_context_export l_ctx_e;
  s.to_stream(iter, l_ctx_e);
  CompoMe::Serialization_context_import l_ctx_i;
  s_i.from_stream(iter, l_ctx_i);

  // test
  CHECK(s.a_position().a_x() == s_i.a_position().a_x());
  CHECK(s.a_position().a_y() == s_i.a_position().a_y());
  CHECK(s.a_size().a_h() == s_i.a_size().a_h());
  CHECK(s.a_size().a_w() == s_i.a_size().a_w());
  CHECK(s == s_i);
}
