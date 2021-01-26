#include "catch.hpp"

#include "Structs/A.hpp"
#include "Structs/AA.hpp"
#include "Structs/Square.hpp"

#include <dbus/dbus.h>


TEST_CASE("Struct serialization on dbus struct with parent",
          "[Struct][Serialization][Simple][int][DUBS]") {

  // data
  AA a;
  a.set_a(1);
  a.set_c(10);

  DBusMessage *msg = dbus_message_new_method_call("test.target", "/t", "I.m", "M");
  DBusMessageIter iter;

  // serialization_context output
  CompoMe::Serialization_context_export l_ctx_e;
  dbus_message_iter_init_append(msg, &iter);
  a.to_stream(iter, l_ctx_e);

  // test
  REQUIRE(std::string(dbus_message_get_signature(msg)) == "a{sv}");

  // serialization_context input
  CompoMe::Serialization_context_import l_ctx_i;
  dbus_message_iter_init(msg, &iter);
  a.from_stream(iter, l_ctx_i);

  // test
  REQUIRE(a.get_a() == 1);
  REQUIRE(a.get_c() == 10);
}

TEST_CASE("Struct serialization on dbus message of one field Struct ",
          "[Struct][Serialization][Simple][int][DUBS]") {

  // data
  A a;
  a.set_a(1);

  DBusMessage *msg = dbus_message_new_method_call("test.target", "/t", "I.m", "M");
  DBusMessageIter iter;

  // serialization_context output
  CompoMe::Serialization_context_export l_ctx_e;
  dbus_message_iter_init_append(msg, &iter);
  a.to_stream(iter, l_ctx_e);

  // test
  REQUIRE(std::string(dbus_message_get_signature(msg)) == "a{sv}");

  // serialization_context input
  CompoMe::Serialization_context_import l_ctx_i;
  dbus_message_iter_init(msg, &iter);
  a.from_stream(iter, l_ctx_i);

  // test
  REQUIRE(a.get_a() == 1);
}

TEST_CASE("Struct serialization on dbus message of sub struct field Struct ",
          "[Struct][Serialization][Simple][int][DUBS]") {

  Square s,s_i;
  s.a_position().a_x() = GENERATE(range(-5, 5));
  s.a_position().a_x() = GENERATE(range(-5, 5));
  s.a_size().a_h() = GENERATE(range(-5, 5));
  s.a_size().a_w() = GENERATE(range(-5, 5));

  DBusMessage *msg = dbus_message_new_method_call("test.target", "/t", "I.m", "M");
  DBusMessageIter iter;

  // serialization_context output
  CompoMe::Serialization_context_export l_ctx_e;
  dbus_message_iter_init_append(msg, &iter);
  s.to_stream(iter, l_ctx_e);

  // test
  REQUIRE(std::string(dbus_message_get_signature(msg)) == "a{sv}");

  // serialization_context input
  CompoMe::Serialization_context_import l_ctx_i;
  dbus_message_iter_init(msg, &iter);
  s_i.from_stream(iter, l_ctx_i);

  // test
  CHECK(s.a_position().a_x() == s_i.a_position().a_x());
  CHECK(s.a_position().a_y() == s_i.a_position().a_y());
  CHECK(s.a_size().a_h() == s_i.a_size().a_h());
  CHECK(s.a_size().a_w() == s_i.a_size().a_w());
}
