#include "Data/code.hpp"
#include "catch.hpp"

TEST_CASE("Type namespace", "[type][namespace]") {

  W::int8 a0;
  W1::int8 a1;
  W2::W1::int8 a2;

  L::int8 a3;
  L1::int8 a4;
  L2::L1::int8 a5;

  M::int8 a6;
  M1::int8 a7;
  M2::M1::int8 a8;
}
