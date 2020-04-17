#include "catch.hpp"

#include "Data/Struct_A.hpp"
#include "Data/Struct_B.hpp"
#include "Data/Struct_C.hpp"

#include "Data/Type_pA.hpp"
#include "Data/Type_pC.hpp"

#include <memory>
#include <sstream>

TEST_CASE("Struct gen", "[Struct][gen]") {
  C c;
  A a;
  pC pc = nullptr;
  pA pa = nullptr;
  if (pc != NULL) {
    throw "wrong";
  }
  if (pa != NULL) {
    throw "wrong";
  }

  pc = &c;
  pa = &a;

  if (pc == NULL) {
    throw "wrong";
  }
  if (pa == NULL) {
    throw "wrong";
  }
}
