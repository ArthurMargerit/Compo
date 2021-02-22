#include "Data/code.hpp"
#include "catch.hpp"
#include "json.hpp"
#include <iostream>
#include <map>

namespace CompoMe {
void to_json(nlohmann::json &nlohmann_json_j,
             const CompoMe::String &nlohmann_json_t) {
  nlohmann_json_j = nlohmann_json_t.str;
}
void from_json(const nlohmann::json &nlohmann_json_j,
               CompoMe::String &nlohmann_json_t) {
  nlohmann_json_t.str = nlohmann_json_j.get<std::string>();
}
} // namespace CompoMe

namespace CompoMe {
class A {
public:
  A(){}
  virtual ~A(){}
};
} // namespace CompoMe

namespace CompoMe {
void to_json(nlohmann::json &nlohmann_json_j,
             const CompoMe::A &nlohmann_json_t) {
  nlohmann_json_j = nlohmann_json_t.str;
}
void from_json(const nlohmann::json &nlohmann_json_j,
               CompoMe::A &nlohmann_json_t) {
  nlohmann_json_t.str = nlohmann_json_j.get<std::string>();
}
} // namespace CompoMe

template <typename T> void test(T t) {
  T e = t;
  T e_i;

  {
    nlohmann::json iter;
    iter = e;
    e_i = iter.get<T>();
    CHECK(e == e_i);
  }

  {
    nlohmann::json iter;
    iter = e;
    iter.get_to(e_i);
    CHECK(e == e_i);
  }

  {
    nlohmann::json iter;
    iter["lapin"] = e;
    e_i = iter["lapin"].get<T>();
    CHECK(e == e_i);
  }
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

  std::pair<const CompoMe::String_d, CompoMe::String_d> a(CompoMe::String("a"),
                                                          CompoMe::String("b"));

  Map<std::string, int> c_map{{"one", 1}, {"two", 2}, {"three", 3}};
  Map<CompoMe::String, CompoMe::String> vmap = {
      {"a", "b"}, {"c", "d"}, {"e", "f"}};
  Map<CompoMe::String, Map<CompoMe::String, CompoMe::String>> vmap2 = {
      {"t1", vmap}, {"t2", vmap}, {"t3", vmap}};

  Map<CompoMe::String,
      Map<CompoMe::String, Map<CompoMe::String, CompoMe::String>>>
      vmap3 = {{"u1", vmap2}, {"u2", vmap2}, {"u3", vmap2}};

  Vec<CompoMe::String> vvec = {"a", "b", "c"};
  Vec<float> vvecf = {0.1f, 0.3f};
  Vec<bool> vvecb = {true, false};
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
  initialization of 'value_type'(
      aka 'pair<const CompoMe::String_d, CompoMe::String_d>')
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

  // // vector
  test(vvec);  // vec
  test(vvec2); // vec of vec
  test(vvec3); // vec of vec of vec
  test(vvecb); // vec of boolean
  test(vvecf); // vec of float

  // // array
  // test(varr);  // varr
  // test(varr2); // arr of arr
  // test(varr3); // arr of arr of arr

  // // map
  test(c_map); // map
  test(vmap);  // map
  // test(vmap2); // map of map
  // test(vmap3); // map of map of map

  // // pair
  // test(vpair);  // pair
  // test(vpair2); // pair of pair

  // // tuple
  // test(vtup1); // tuple
  // test(vtup2); // tuple of tuple
}
