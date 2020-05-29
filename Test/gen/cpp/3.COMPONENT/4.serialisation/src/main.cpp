#include "Components/C1.hpp"
#include "Components/C2.hpp"
#include "Components/C4.hpp"
#include <iostream>

#include "Data/code.hpp"
#include "catch.hpp"
#include <sstream>

TEST_CASE("Component serialization", "[Component][serialization]") {

  C1 c1;
  std::stringstream ss;

  ss << c1;
  INFO("c1 = " << c1);
  CHECK(ss.str().find("pi1") != std::string::npos);
  CHECK(ss.str().find("pi2") != std::string::npos);
  CHECK(ss.str().find("pi3") != std::string::npos);

  // CHECK(ss.str().find("ri1") != std::string::npos);
  // CHECK(ss.str().find("ri2") != std::string::npos);
  // CHECK(ss.str().find("ri3") != std::string::npos);

  CHECK(ss.str().find("a1") != std::string::npos);
  CHECK(ss.str().find("a2") != std::string::npos);
  CHECK(ss.str().find("a3") != std::string::npos);

  CHECK(ss.str().find("sc1") != std::string::npos);
  CHECK(ss.str().find("sc2") != std::string::npos);
}
