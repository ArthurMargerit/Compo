#include "Data/code.hpp"
#include "Types/E1.hpp"
#include "Types/E2.hpp"
#include "Types/S1/E3.hpp"
#include "Types/S2/S1/E4.hpp"
#include "catch.hpp"

TEST_CASE("Type enum", "[Type][Enum]") {

  E1 e1;
  e1 = E1::A;
  e1 = E1::B;
  e1 = E1::C;

  e1 = E1::A | E1::B;
  e1 = E1::A & E1::A;
  e1 = E1::B & E1::B;
  e1 = E1::A;

  e1 = !(e & E1::A);
  e1 = (e & E1::A);

  E2 e2;
  S1::E3 e3;
  S2::S1::E4 e4;
}
