#include "Components/C1/C1.hpp"
#include "Components/C4/C4.hpp"
#include "Components/C2/C2.hpp"
#include <iostream>

#include "catch.hpp"
#include "Data/code.hpp"

TEST_CASE("Component serialization", "[Component][serialization]") {

  C1::C1 c1;
  std::cout << c1 << "\n";

  C2::C2 c2;
  std::cout << c2 << "\n";

  C4::C4 c4;
  std::cout << c4 << "\n";
}
