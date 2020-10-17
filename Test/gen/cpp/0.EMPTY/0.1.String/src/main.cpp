#include "catch.hpp"
#include "Types/CompoMe/String.hpp"
#include <sstream>

TEST_CASE( "String initialisation", "[String][Initialisation]" ) {
  CompoMe::String s1;
  REQUIRE(s1 == "");

  s1 = "lapin";
  REQUIRE(s1 == "lapin");

  s1.str = "lion";
  REQUIRE(s1 == "lion");
}

TEST_CASE( "String Serialization", "[String][Initialisation]" ) {
  std::stringstream ss;

  ss << "lapin";
  REQUIRE(ss.str() == "lapin");

  CompoMe::String s1 = "lapin";
  ss.str("");
  ss << s1;
  REQUIRE(ss.str() == "\"lapin\"");

  s1 = "lapin\"";
  ss.str("");
  ss << s1;
  REQUIRE(ss.str() == "\"lapin\\\"\"");
}

TEST_CASE( "String Serialization2", "[String][Initialisation]" ) {
  for (int i = 0; i < 10000; ++i) {
  std::stringstream ss;
  CompoMe::String s1 = "          ";
  CompoMe::String s2 = "";
  for (int i = 0; i < 10; ++i) {
    char c = rand()%255;
    s1.str[i] = c;
  }

  ss << s1;
  ss >> s2;

  REQUIRE(s1 == s2);
  REQUIRE(s1.str == s2.str);
 }
}

TEST_CASE("String printable", "[String][Initialisation]" ) {
  for (int i = 0; i < 100; ++i) {
    std::stringstream ss;
    CompoMe::String s1 = "          \n\r\t\v\f\a\b";
    for (int i = 0; i < 10; ++i) {
      char c = rand()%('~'-' ')+' ';
      s1.str[i] = c;
    }

    ss << s1;
    for (char i_c : ss.str()) {
      INFO("a= (" << (int)i_c << ") - '" << i_c<<"'");
      REQUIRE(std::isprint(i_c) != false);
    }
  }
}
