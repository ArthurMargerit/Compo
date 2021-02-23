#include "Data/code.hpp"
#include "catch.hpp"
#include "json.hpp"
#include <algorithm>
#include <limits.h>
#include <limits>
#include <string>

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

TEST_CASE("Type json CompoMe int", "[Type][Simple][josn][CompoMe]") {

  SECTION("i8") {
    i8 v8 =
        GENERATE(std::numeric_limits<i8>::min(), std::numeric_limits<i8>::max(),
                 0, 1, 2, -1, -2, 10, 100, -10, -100);
    test(v8);
  }

  SECTION("i16") {
    i16 v16 = GENERATE(std::numeric_limits<i16>::min(),
                       std::numeric_limits<i16>::max(), 0, 1, 2, -1, -2, 10,
                       100, -10, -100);
    test(v16);
  }

  SECTION("i32") {
    i32 v32 = GENERATE(std::numeric_limits<i32>::min(),
                       std::numeric_limits<i32>::max(), 0, 1, 2, -1, -2, 10,
                       100, -10, -100);
    test(v32);
  }

  SECTION("i64") {
    i64 v64 = GENERATE(std::numeric_limits<i64>::min(),
                       std::numeric_limits<i64>::max(), 0, 1, 2, -1, -2, 10,
                       100, -10, -100);
    test(v64);
  }
  SECTION("ui8") {
    ui8 v8 = GENERATE(std::numeric_limits<ui8>::min(),
                      std::numeric_limits<ui8>::max(), 0, 1, 2, -1, -2, 10, 100,
                      -10, -100);
    test(v8);
  }

  SECTION("ui16") {
    ui16 v16 = GENERATE(std::numeric_limits<ui16>::min(),
                        std::numeric_limits<ui16>::max(), 0, 1, 2, -1, -2, 10,
                        100, -10, -100);
    test(v16);
  }

  SECTION("ui32") {
    ui32 v32 = GENERATE(std::numeric_limits<ui32>::min(),
                        std::numeric_limits<ui32>::max(), 0, 1, 2, -1, -2, 10,
                        100, -10, -100);
    test(v32);
  }

  SECTION("ui64") {
    ui64 v64 = GENERATE(std::numeric_limits<ui64>::min(),
                        std::numeric_limits<ui64>::max(), 0, 1, 2, -1, -2, 10,
                        100, -10, -100);
    test(v64);
  }
}
TEST_CASE("Type json CompoMe float/double", "[Type][Simple][json][CompoMe]") {
  SECTION("bool") {
    bool vb = GENERATE(true, false);
    test(vb); // bool
  }
  SECTION("double") {
    double vd = GENERATE(std::numeric_limits<double>::min(),
                         std::numeric_limits<double>::max(), 0, 0.1, 0.2, 1.30);
    test(vd); // double
  }
  SECTION("float") {
    float vf = GENERATE(std::numeric_limits<float>::min(),
                        std::numeric_limits<float>::max(), 0, 0.1, 0.2, 1.30);
    test(vf); // float
  }
}

TEST_CASE("Type json CompoMe map", "[Type][Simple][json][CompoMe]") {
  Map<std::string, int> c_map{{"one", 1}, {"two", 2}, {"three", 3}};
  Map<CompoMe::String, CompoMe::String> vmap = {
      {"a", "b"}, {"c", "d"}, {"e", "f"}};
  Map<CompoMe::String, Map<CompoMe::String, CompoMe::String>> vmap2 = {
      {"t1", vmap}, {"t2", vmap}, {"t3", vmap}};

  Map<CompoMe::String,
      Map<CompoMe::String, Map<CompoMe::String, CompoMe::String>>>
      vmap3 = {{"u1", vmap2}, {"u2", vmap2}, {"u3", vmap2}};

  test(c_map); // map
  test(vmap);  // map
  test(vmap2); // map of map
  test(vmap3); // map of map of map
}

TEST_CASE("Type json CompoMe vec", "[Type][Simple][json][CompoMe]") {
  Vec<CompoMe::String> vvec = {"a", "b", "c"};
  Vec<float> vvecf = {0.1f, 0.3f};
  Vec<bool> vvecb = {true, false};
  Vec<Vec<CompoMe::String>> vvec2 = {{"a", "b", "c"}, {"a", "b"}, {"a"}};
  Vec<Vec<Vec<CompoMe::String>>> vvec3 = {
      {{"a1", "b1", "c1"}, {"d1", "e1"}, {"f1"}},
      {{"a2", "b2", "c2"}, {"d2", "e2"}, {"f2"}},
      {{"a3", "b3", "c3"}, {"d3", "e3"}, {"f3", "g3", "h3"}}};

  // // vector
  test(vvec);  // vec
  test(vvec2); // vec of vec
  test(vvec3); // vec of vec of vec
  test(vvecb); // vec of boolean
  test(vvecf); // vec of float
}

TEST_CASE("Type json  std::string/CompoMe::String",
          "[Type][Simple][json][CompoMe]") {
  SECTION("std::String") {
    std::string vs = GENERATE("", " ", "test", "lapin is fun");
    test(vs);
  }

  SECTION("CompoMe::String") {
    CompoMe::String vs = GENERATE("", " ", "test", "lapin is fun");
    test(vs);
  }
}

TEST_CASE("Type json CompoMe pair/tupple/array",
          "[Type][Simple][json][CompoMe]") {

  SECTION("Pair") {
    Pair<CompoMe::String, i32> vpair = {"A", 2};
    Pair<Pair<CompoMe::String, i32>, Pair<CompoMe::String, i32>> vpair2 = {
        {"A", 2}, {"B", 4}};

    // pair
    test(vpair);

    // this failled
    // github error open
    // test(vpair2); // pair of pair with 2 first field with the same name
  }

  SECTION("Array") {
    Array<CompoMe::String, 5> varr = {"a", "b", "c", "a", "b"};

    Array<Array<CompoMe::String, 5>, 3> varr2 = {{{"a", "b", "c", "b", "c"},
                                                  {"a", "b", "c", "b", "c"},
                                                  {"a", "b", "c", "b", "c"}}};

    Array<Array<Array<CompoMe::String, 5>, 3>, 3> varr3 = {varr2, varr2, varr2};
    // array
    test(varr);  // varr
    test(varr2); // arr of arr
    test(varr3); // arr of arr of arr
  }

  SECTION("Tupple") {
    Tuple<CompoMe::String, i32, bool> vtup1 = {"A", 2, false};
    Tuple<CompoMe::String, i32, Tuple<CompoMe::String, i32>> vtup2 = {
        "A", 2, {"A", 2}};
    // tuple
    test(vtup1); // tuple
    test(vtup2); // tuple of tuple
  }
}
