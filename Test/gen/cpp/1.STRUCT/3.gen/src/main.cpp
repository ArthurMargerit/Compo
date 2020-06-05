#include "catch.hpp"

#include "Data/A.hpp"
#include "Data/B.hpp"
#include "Data/C.hpp"

#include "Data/pA.hpp"
#include "Data/pC.hpp"

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
