#include "catch.hpp"

#include "Structs/A.hpp"
#include "Structs/B.hpp"
#include "Structs/C.hpp"

#include "Types/pA.hpp"
#include "Types/pC.hpp"

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
