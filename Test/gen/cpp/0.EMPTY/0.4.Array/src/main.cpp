#include "catch.hpp"
#include "Types/Array.hpp"
#include "Structs/A.hpp"
#include <sstream>
#include <string>

TEST_CASE( "Vec serialization to string", "[vector]") {
  Array<i32,10> a = {0,0,0,0,0,0,0,0,0,0};

  std::stringstream ss;

  ss << a ;
  CHECK(ss.str() == "[0,0,0,0,0,0,0,0,0,0]");

  ss.str("");
  a = {1,2,4,8,16,32,64,128,256,512};
  ss << a ;
  CHECK(ss.str() == "[1,2,4,8,16,32,64,128,256,512]");
}

TEST_CASE( "array empty", "[vector]") {
  Array<i32,0> a;
  Array<i32,0> b;
  std::stringstream ss;

  ss << a;
  CHECK(ss.str() == "[]");
  ss << "[]";
  ss >> b;
  CHECK(a == b);
}

TEST_CASE( "Vec serialization to string 2", "[vector]") {
  Array<i32,100> a;
  Array<i32,100> b;

  std::stringstream ss;

  for (int i = 0; i < 100; ++i) {
    a[i] = rand()%99999;
  }

  ss << a ;
  ss >> b ;

  CHECK(a==b);
}
