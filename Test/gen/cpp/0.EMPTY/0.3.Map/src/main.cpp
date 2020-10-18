#include "catch.hpp"
#include "Types/Map.hpp"
#include "Data/CompoMe.hpp"
#include "Types/CompoMe/String.hpp"
#include "Structs/A.hpp"
#include <sstream>

TEST_CASE( "map initialisation", "[String][Initialisation]" ) {
  Map<CompoMe::String,i32> m;
  m["A"] = 1;
  m["B"] = 2;
  m["C"] = 3;

  REQUIRE(m["A"] == 1);
  REQUIRE(m["B"] == 2);
  REQUIRE(m["C"] == 3);
}

TEST_CASE("map printable", "[String][Initialisation]" ) {
  Map<CompoMe::String,i32> m;
  m["A"] = 1;
  m["B"] = 2;
  m["C"] = 3;

  std::stringstream ss;
  ss << m ;
  REQUIRE(ss.str() == "{\"A\":1,\"B\":2,\"C\":3}");
}

TEST_CASE("map from string ", "[String][Initialisation]" ) {
  Map<CompoMe::String,i32> m;
  std::stringstream ss;
  ss << "{\"A\":1,\"B\":2,\"C\":3}";
  ss >> m;

  REQUIRE(m.size() == 3);
  REQUIRE(m["A"] == 1);
  REQUIRE(m["B"] == 2);
  REQUIRE(m["C"] == 3);
}


TEST_CASE("map of map from string ", "[String][Initialisation]" ) {
  Map<CompoMe::String,Map<CompoMe::String,CompoMe::String>> m;
  m["a"]["b"] = "ab";
  m["a"]["c"] = "ac";
  m["b"]["c"] = "bc";
  m["b"]["e"] = "be";

  std::stringstream ss;
  ss << m;
  REQUIRE(ss.str()== "{\"a\":{\"b\":\"ab\",\"c\":\"ac\"},\"b\":{\"c\":\"bc\",\"e\":\"be\"}}");
}


TEST_CASE("empty ", "[String][Initialisation]" ) {
  Map<CompoMe::String,i32> m;

  std::stringstream ss;
  ss << m;
  REQUIRE(ss.str()== "{}");
}

TEST_CASE("empty from string ", "[String][Initialisation]" ) {
  Map<CompoMe::String,i32> m;
  m["a"] = 1;

  std::stringstream ss;
  ss << "{}";
  ss >> m;
  REQUIRE(m.empty() == true);
}

TEST_CASE("Map struct to string / from string ", "[String][Initialisation]" ) {
  Map<CompoMe::String,A> m;
  for (i32 i = 0; i < 100000; ++i) {
    i32 size_s = rand()%10+1;
     auto s_k = std::string(size_s, ' ');
     for (i32 i2 = 0; i2 < size_s; ++i2) {
       s_k[i2] = rand()%('~'-' ')+' ';
      }

     A a;
     a.set_a(rand()%6666);
     a.set_b(rand()%9999);
     i32 size_s2 = rand()%100+1;
     auto s_k2 = std::string(size_s, ' ');
     for (i32 i2 = 0; i2 < size_s; ++i2) {
       s_k2[i2] = rand()%('Z'-'A')+'A';
     }
     a.set_s(s_k2);


     m[s_k] = a;
  }

  std::stringstream ss;
  Map<CompoMe::String,A> m2;
  ss << m;
  ss >> m2;
  REQUIRE(m == m2);
}
