#include "catch.hpp"

#include "Data/Full_hide.hpp"
#include "Data/With_extra.hpp"
#include "Data/With_hide.hpp"

#include <memory>
#include <sstream>

TEST_CASE("Struct with some Hide", "[Struct][Serialization][Hide]") {
  With_hide wh, wh_i;
  wh.set_hide(1);

  std::stringstream ss;
  ss << wh;
  ss >> wh_i;

  REQUIRE(wh.get_hide() == 1);
  REQUIRE(wh_i.get_hide() == 0);
}

TEST_CASE("Struct with  Hide", "[Struct][Serialization][Hide]") {
  Full_hide wh, wh_i;
  wh.set_hide1(1);
  wh.set_hide2(2);
  wh.set_hide3(3);

  std::stringstream ss;
  ss << wh;
  ss >> wh_i;

  REQUIRE(wh.get_hide1() == 1);
  REQUIRE(wh.get_hide2() == 2);
  REQUIRE(wh.get_hide3() == 3);

  REQUIRE(wh_i.get_hide1() == 0);
  REQUIRE(wh_i.get_hide2() == 0);
  REQUIRE(wh_i.get_hide3() == 0);
}

TEST_CASE("Struct with extra", "[Struct][Serialization][Extra]") {
  With_extra we;

  std::stringstream ss;
  ss << we;

  auto t = ss.str().find("extra");
  REQUIRE(t != std::string::npos);
}
