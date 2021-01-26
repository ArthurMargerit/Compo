#include "Data/code.hpp"
#include "catch.hpp"
#include <dbus/dbus.h>
#include <iostream>

template <typename T> void test(T t) {
  T e = t;
  T e_i;

  DBusMessageIter iter_r;
  DBusMessageIter iter_w;
  DBusMessage *msg =
      dbus_message_new_method_call("test.method.server", "/test/method/Object",
                                   "test.method.Type", "Method");

  dbus_message_iter_init_append(msg, &iter_w);
  iter_w << e;

  dbus_message_iter_init(msg, &iter_r);
  iter_r >> e_i;

  CHECK(e == e_i);
  dbus_message_unref(msg);
}

TEST_CASE("Type dbus CompoMe", "[Type][Simple][Dbus][CompoMe]") {

  i8 v8 = 10;
  i16 v16 = 10;
  i32 v32 = 10;
  i64 v64 = 10;

  ui8 uv8 = 10;
  ui16 uv16 = 10;
  ui32 uv32 = 10;
  ui64 uv64 = 10;

  CompoMe::String vs = "test";
  bool vb = true;
  double vd = 25.2552;
  float vf = 0.5;

  Map<CompoMe::String, CompoMe::String> vmap = {
      {"a", "b"}, {"c", "d"}, {"e", "f"}};
  Map<CompoMe::String, Map<CompoMe::String, CompoMe::String>> vmap2 = {
      {"t1", vmap}, {"t2", vmap}, {"t3", vmap}};

  Map<CompoMe::String,
      Map<CompoMe::String, Map<CompoMe::String, CompoMe::String>>>
      vmap3 = {{"u1", vmap2}, {"u2", vmap2}, {"u3", vmap2}};

  Vec<CompoMe::String> vvec = {"a", "b", "c"};
  Vec<float> vvecf = {0.1f,0.3f};
  Vec<bool> vvecb = {true,false};
  Vec<Vec<CompoMe::String>> vvec2 = {{"a", "b", "c"}, {"a", "b"}, {"a"}};
  Vec<Vec<Vec<CompoMe::String>>> vvec3 = {
      {{"a1", "b1", "c1"}, {"d1", "e1"}, {"f1"}},
      {{"a2", "b2", "c2"}, {"d2", "e2"}, {"f2"}},
      {{"a3", "b3", "c3"}, {"d3", "e3"}, {"f3", "g3", "h3"}}};
  Array<CompoMe::String, 5> varr = {"a", "b", "c", "a", "b"};

  Array<Array<CompoMe::String, 5>, 3> varr2 = {{{"a", "b", "c", "b", "c"},
                                                {"a", "b", "c", "b", "c"},
                                                {"a", "b", "c", "b", "c"}}};

  Array<Array<Array<CompoMe::String, 5>, 3>, 3> varr3 = {varr2, varr2, varr2};

  Pair<CompoMe::String, i32> vpair = {"A", 2};
  Pair<Pair<CompoMe::String, i32>, Pair<CompoMe::String, i32>> vpair2 = {
      {"A", 2}, {"A", 2}};
  Tuple<CompoMe::String, i32, bool> vtup1 = {"A", 2, false};
  Tuple<CompoMe::String, i32, Tuple<CompoMe::String, i32>> vtup2 = {
      "A", 2, {"A", 2}};
  ;

  REQUIRE(dbus_type_cls<Pair<CompoMe::String, CompoMe::String>>::sig() ==
          "(ss)");
  REQUIRE(dbus_type_cls<Pair<i32, CompoMe::String>>::sig() == "(is)");
  REQUIRE(dbus_type_cls<Pair<i32, i32>>::sig() == "(ii)");
  REQUIRE(dbus_type_cls<Pair<Pair<i32, i32>, i32>>::sig() == "((ii)i)");
  REQUIRE(
      dbus_type_cls<
          Pair<Pair<i32, i32>, Pair<i32, Pair<i32, Pair<i32, i32>>>>>::sig() ==
      "((ii)(i(i(ii))))");

  REQUIRE(
      dbus_type_cls<
          Tuple<CompoMe::String, CompoMe::String, CompoMe::String>>::sig() ==
      "(sss)");
  REQUIRE(dbus_type_cls<Tuple<i32>>::sig() == "(i)");
  REQUIRE(dbus_type_cls<Tuple<i32, i32>>::sig() == "(ii)");
  REQUIRE(dbus_type_cls<Tuple<i32, i32, i32>>::sig() == "(iii)");
  REQUIRE(dbus_type_cls<Tuple<i32, i32, i32, i32, i32, i32>>::sig() ==
          "(iiiiii)");

  REQUIRE(dbus_type_cls<Vec<Vec<Vec<CompoMe::String>>>>::sig() == "aaas");
  REQUIRE(dbus_type_cls<Vec<Vec<CompoMe::String>>>::sig() == "aas");
  REQUIRE(dbus_type_cls<Vec<CompoMe::String>>::sig() == "as");

  REQUIRE(dbus_type_cls<Vec<Vec<Vec<int>>>>::sig() == "aaai");
  REQUIRE(dbus_type_cls<Vec<Vec<int>>>::sig() == "aai");
  REQUIRE(dbus_type_cls<Vec<int>>::sig() == "ai");

  REQUIRE(dbus_type_cls<Map<CompoMe::String, int>>::sig() == "a{si}");
  REQUIRE(
      dbus_type_cls<Map<CompoMe::String, Map<CompoMe::String, int>>>::sig() ==
      "a{sa{si}}");
  REQUIRE(dbus_type_cls<
              Map<CompoMe::String,
                  Map<CompoMe::String, Map<CompoMe::String, int>>>>::sig() ==
          "a{sa{sa{si}}}");

  // int
  test(v8);
  test(v16);
  test(v32);
  test(v64);

  // unsigned int
  test(uv8);
  test(uv16);
  test(uv32);
  test(uv64);

  // other
  test(vs); // string

  // bool
  test(vb); // bool

  // floating values
  test(vd); // double
  test(vf); // float

  // vector
  test(vvec);  // vec
  test(vvec2); // vec of vec
  test(vvec3); // vec of vec of vec
  test(vvecb); // vec of boolean
  test(vvecf); // vec of float

  // array
  test(varr);  // varr
  test(varr2); // arr of arr
  test(varr3); // arr of arr of arr

  // map
  test(vmap);  // map
  test(vmap2); // map of map
  test(vmap3); // map of map of map

  // pair
  test(vpair);  // pair
  test(vpair2); // pair of pair

  // tuple
  test(vtup1); // tuple
  test(vtup2); // tuple of tuple

  dbus_shutdown();
}
