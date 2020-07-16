#include "catch.hpp"

#include "Structs/A.hpp"
#include "Structs/Square.hpp"

#include <dbus-cxx.h>


TEST_CASE("Struct serialization on dbus message of one field Struct ",
          "[Struct][Serialization][Simple][int][DUBS]") {

  auto m = DBus::CallMessage::create();
  A a;
  a.set_a(1);

  CompoMe::Serialization_context_export l_ctx_e;
  auto l_ite_w = m->append();
  a.to_stream(l_ite_w, l_ctx_e);

  CompoMe::Serialization_context_import l_ctx_i;
  auto l_ite_r = m->begin();
  a.from_stream(l_ite_r, l_ctx_i);

  REQUIRE(a.get_a() == 1);
}

TEST_CASE("Struct serialization on dbus message of sub struct field Struct ",
          "[Struct][Serialization][Simple][int][DUBS]") {

  auto m = DBus::CallMessage::create();
  Square s,s_i;
  s.a_position().a_x() = GENERATE(range(-5, 5));
  s.a_position().a_x() = GENERATE(range(-5, 5));
  s.a_size().a_h() = GENERATE(range(-5, 5));
  s.a_size().a_w() = GENERATE(range(-5, 5));

  CompoMe::Serialization_context_export l_ctx_e;
  auto l_ite_w = m->append();
  s.to_stream(l_ite_w, l_ctx_e);

  CompoMe::Serialization_context_import l_ctx_i;
  auto l_ite_r = m->begin();
  s_i.from_stream(l_ite_r, l_ctx_i);

  REQUIRE(s.a_position().a_x() == s_i.a_position().a_x());
  REQUIRE(s.a_position().a_y() == s_i.a_position().a_y());
  REQUIRE(s.a_size().a_h() == s_i.a_size().a_h());
  REQUIRE(s.a_size().a_w() == s_i.a_size().a_w());
}

