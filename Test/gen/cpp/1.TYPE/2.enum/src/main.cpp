#include "Data/code.hpp"
#include "Types/E1.hpp"
#include "Types/E2.hpp"
#include "Types/S1/E3.hpp"
#include "Types/S2/S1/E4.hpp"
#include "Types/SUP.hpp"
#include "catch.hpp"

TEST_CASE("Type enum string convertion", "[Type][Enum]") {

  std::stringstream ss;
  E1 e1;
  
  // from value
  ss << "1";
  ss >> e1;

  // from name
  ss << "1";
  ss >> e1;

  // from name with namespace
  ss << "1";
  ss >> e1;

  // from name with namespace with :: force
  ss << "1";
  ss >> e1;



}

TEST_CASE("Type enum", "[Type][Enum]") {

  std::stringstream ss;
  E1 e1c;
  E1 e1 = E1::A;
  ss << e1;
  CHECK(ss.str() == "::E1::A");
  ss >> e1c;
  CHECK(e1c == E1::A);

  std::stringstream ss1;
  e1 = E1::B;
  ss1 << e1;
  CHECK(ss1.str() == "::E1::B");
  ss1 >> e1c;
  CHECK(e1c == E1::B);
  ss1.str("");

  std::stringstream ss2;
  e1 = E1::C;
  ss2 << e1;
  CHECK(ss2.str() == "::E1::C");
  ss2 >> e1c;
  CHECK(e1c == E1::C);

  std::stringstream ss3;
  S1::E3 e3 = S1::E3::G;
  S1::E3 e3c;
  ss3 << e3;
  CHECK(ss3.str() == "S1::E3::G");
  ss3 >> e3c;
  CHECK(e3c == S1::E3::G);

  std::stringstream ss4;
  S2::S1::E4 e4 = S2::S1::E4::H;
  S2::S1::E4 e4c;
  ss4 << e4;
  CHECK(ss4.str() == "S2::S1::E4::H");
  ss4 >> e4c;
  CHECK(e4c == S2::S1::E4::H);
}

TEST_CASE("Type enum flags value", "[Type][Enum]") {
  CHECK(SUP::V1 == SUP(1 << 0));
  CHECK(SUP::V2 == SUP(1 << 1));
  CHECK(SUP::V3 == SUP(1 << 2));
  CHECK(SUP::V4 == SUP(1 << 3));
}

TEST_CASE("Type enum flags assignement", "[Type][Enum]") {
  std::stringstream ss;

  SUP s = SUP::V1;
  CHECK(s == SUP::V1);
  ss << s;
  CHECK(ss.str() == "::SUP::V1");
  ss.str("");

  s = SUP::V2;
  CHECK(s == SUP::V2);
  ss << s;
  CHECK(ss.str() == "::SUP::V2");
  ss.str("");

  s = SUP::V3;
  CHECK(s == SUP::V3);
  ss << s;
  CHECK(ss.str() == "::SUP::V3");
  ss.str("");

  s = SUP::V4;
  CHECK(s == SUP::V4);
  ss << s;
  CHECK(ss.str() == "::SUP::V4");
  ss.str("");
}

TEST_CASE("Type enum flags opperation 'and' 'or' 'is' & 'not'",
          "[Type][Enum]") {
  SUP s = SUP::V1;
  CHECK(is(s, SUP::V1) == true);

  s = SUP::V2;
  CHECK(is(s, SUP::V2) == true);

  s = SUP::V3;
  CHECK(is(s, SUP::V3) == true);

  s = SUP::V4;
  CHECK(is(s, SUP::V4) == true);

  s = SUP::V1 | SUP::V2 | SUP::V3 | SUP::V4;
  int v = static_cast<int>(s);
  CHECK(v == (8 + 4 + 2 + 1));
  CHECK(true == is(s, SUP::V1));
  CHECK(true == is(s, SUP::V2));
  CHECK(true == is(s, SUP::V3));
  CHECK(true == is(s, SUP::V4));

  CHECK(true == is(s, SUP::V1 | SUP::V2));
  CHECK(true == is(s, SUP::V1 | SUP::V3));
  CHECK(true == is(s, SUP::V1 | SUP::V4));
  CHECK(true == is(s, SUP::V2 | SUP::V3));
  CHECK(true == is(s, SUP::V2 | SUP::V4));
  CHECK(true == is(s, SUP::V3 | SUP::V4));

  CHECK(true == is(s, SUP::V1 | SUP::V2 | SUP::V3));
  CHECK(true == is(s, SUP::V1 | SUP::V2 | SUP::V4));
  CHECK(true == is(s, SUP::V1 | SUP::V3 | SUP::V4));
  CHECK(true == is(s, SUP::V2 | SUP::V3 | SUP::V4));

  CHECK(true == is(s, SUP::V1 | SUP::V2 | SUP::V3 | SUP::V4));

  s = SUP::V1 | SUP::V4;
  int v2 = static_cast<int>(s);
  CHECK(v2 == (8 + 1));
  CHECK(true == is(s, SUP::V1));
  CHECK(false == is(s, SUP::V2));
  CHECK(false == is(s, SUP::V3));
  CHECK(true == is(s, SUP::V4));

  CHECK(false == is(s, SUP::V1 | SUP::V2));
  CHECK(false == is(s, SUP::V1 | SUP::V3));
  CHECK(true == is(s, SUP::V1 | SUP::V4));
  CHECK(false == is(s, SUP::V2 | SUP::V3));
  CHECK(false == is(s, SUP::V2 | SUP::V4));
  CHECK(false == is(s, SUP::V3 | SUP::V4));

  CHECK(false == is(s, SUP::V1 | SUP::V2 | SUP::V3));
  CHECK(false == is(s, SUP::V1 | SUP::V2 | SUP::V4));
  CHECK(false == is(s, SUP::V1 | SUP::V3 | SUP::V4));
  CHECK(false == is(s, SUP::V2 | SUP::V3 | SUP::V4));

  CHECK(false == is(s, SUP::V1 | SUP::V2 | SUP::V3 | SUP::V4));

  s = SUP::V1;
  s = s | SUP::V2;
  CHECK(s == (SUP::V2 | SUP::V1));
  s = s & ~SUP::V2;
  CHECK(s == SUP::V1);

  s = SUP::V1 | SUP::V2 | SUP::V3;
  s = s & ~(SUP::V2 | SUP::V1);
  CHECK(s == SUP::V3);
}
