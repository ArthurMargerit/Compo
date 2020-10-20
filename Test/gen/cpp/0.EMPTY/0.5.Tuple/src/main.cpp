#include "catch.hpp"
#include "Types/Tuple.hpp"
#include "Structs/A.hpp"
#include <sstream>
#include <string>

TEST_CASE( "Tuple to string", "[Tuple]") {
  {
  Tuple<i32,i32,CompoMe::String> a;
  a = std::make_tuple(1,2,"Lapin");

  std::stringstream ss;
  ss << a;
  REQUIRE(ss.str() == "<1,2,\"Lapin\">");
  }

  {
    Tuple<Tuple<i32,i32>,Tuple<i32,i32>> a;
    a = std::make_tuple(std::make_tuple(1,2),std::make_tuple(3,4));

    std::stringstream ss;
    ss << a;
    REQUIRE(ss.str() == "<<1,2>,<3,4>>");
  }
}

TEST_CASE( "Tuple from string", "[Tuple]") {
  
  Tuple<i32,i32,CompoMe::String> a;

  std::stringstream ss;
  ss <<  "<1,2,\"Lapin\">";
  ss >>  a;
  REQUIRE(std::get<0>(a) ==  1) ;
  REQUIRE(std::get<1>(a) ==  2) ;
  REQUIRE(std::get<2>(a) ==  "Lapin") ;
}

TEST_CASE( "Tuple empty", "[Tuple]") {
  Tuple<> a;
  std::stringstream ss,ss2;

  ss << "<>"; //
  ss >> a;    //

  ss2 << a;
  REQUIRE(ss2.str() ==  "<>") ;
}


// TEST_CASE( "Tuple rand from to string", "[Tuple]") {
//   Tuple<i32> a;
//   Tuple<i32> r;
//   for (int i = 0; i < 100; ++i) {
//     a.insert(rand()%6666);
//   }

//   std::stringstream ss;
//   ss << a;
//   ss >> r;

//   REQUIRE(a == r);
// }
