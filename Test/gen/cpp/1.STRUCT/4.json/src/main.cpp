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
  a.to_json(iter, l_ctx_e);
  std::cout << iter << std::endl;

  CompoMe::Serialization_context_import l_ctx_i;
  b.from_json(iter, l_ctx_i);

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
  a.to_json(iter, l_ctx_e);
  CompoMe::Serialization_context_import l_ctx_i;
  b.from_json(iter, l_ctx_i);

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
  s.to_json(iter, l_ctx_e);
  CompoMe::Serialization_context_import l_ctx_i;
  s_i.from_json(iter, l_ctx_i);

  // test
  CHECK(s.a_position().a_x() == s_i.a_position().a_x());
  CHECK(s.a_position().a_y() == s_i.a_position().a_y());
  CHECK(s.a_size().a_h() == s_i.a_size().a_h());
  CHECK(s.a_size().a_w() == s_i.a_size().a_w());
  CHECK(s == s_i);
}

// Test_case("Struct pointer serialization",
//           "[Struct][json][serialization][pointer]") {

//   Empty a, *b;
//   nlohmann::json j;
//   j = a;
//   to_stream();
// }

// nlohmann::json &operator<<(nlohmann::json &j, A *e) { return j; }
// nlohmann::json &operator<<(nlohmann::json &j, AA *e) { return j; }
// nlohmann::json &operator<<(nlohmann::json &j, const CompoMe::Struct *e) {
//   return j;
// }

void to_json(nlohmann::json &j, CompoMe::Struct *e,
             CompoMe::Serialization_context_export &ctx) {
  j.clear();
  j["pointer"] = (unsigned long int)e;
  if (e != nullptr) {
    CompoMe::Serializable_Item *er = e;
    nlohmann::json &jr = j["data"];
    er->to_json(jr, ctx);
  } else {
    j["data"] = nullptr;
  }
}

TEST_CASE("Struct complex nullptr pointer",
          "[Struct][complex][Pointer][Null][json]") {
  nlohmann::json j;
  CompoMe::Serialization_context_export ctx;
  SECTION("CompoMe CompoMe::Struct is nullptr") {
    A *pe = nullptr;
    to_json(j, pe, ctx);
    REQUIRE(j["addr"] == nullptr);
    REQUIRE(j["data"] == nullptr);
  }

  SECTION("CompoMe CompoMe::Struct is nullptr") {
    AA *pb = nullptr;
    to_json(j, pb, ctx);
    REQUIRE(j["addr"] == nullptr);
    REQUIRE(j["data"] == nullptr);
  }

  SECTION("CompoMe CompoMe::Struct is nullptr") {
    CompoMe::Struct *ps = nullptr;
    to_json(j, ps, ctx);
    REQUIRE(j["addr"] == nullptr);
    REQUIRE(j["data"] == nullptr);
  }
}
