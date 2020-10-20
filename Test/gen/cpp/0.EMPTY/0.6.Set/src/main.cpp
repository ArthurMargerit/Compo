#include "catch.hpp"
#include "Types/Set.hpp"
#include "Structs/A.hpp"
#include <sstream>
#include <string>

TEST_CASE( "Set to string", "[Set]") {
  Set<i32> a;

  a.insert(5);
  a.insert(10);
  a.insert(15);

  std::stringstream ss;
  ss << a;
  REQUIRE(ss.str() == "{5,10,15}");
}

TEST_CASE( "Set from string", "[Set]") {
  Set<i32> a;

  std::stringstream ss;
  ss << "{1,5,25,125}";
  ss >> a;
  REQUIRE(a.count(1) == 1 );
  REQUIRE(a.count(5) == 1 );
  REQUIRE(a.count(25) == 1 );
  REQUIRE(a.count(125) == 1 );
  REQUIRE(a.count(2) == 0 );
}

TEST_CASE( "Set empty", "[Set]") {
  Set<i32> a;
  std::stringstream ss;
  ss << "{}";
  ss >> a;

  REQUIRE(a.empty() == true );
}


TEST_CASE( "Set rand from to string", "[Set]") {
  Set<i32> a;
  Set<i32> r;
  for (int i = 0; i < 100; ++i) {
    a.insert(rand()%6666);
  }

  std::stringstream ss;
  ss << a;
  ss >> r;

  REQUIRE(a == r);
}
