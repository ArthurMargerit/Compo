#include "catch.hpp"

#include "Data/Struct_A.hpp"
#include "Data/Struct_A1.hpp"
#include "Data/Struct_Full_hide.hpp"

#include <memory>
#include <sstream>

TEST_CASE("Struct extra", "[Struct][Extra]") {
  A a;
  A1 a1;
  Full_hide fh;

  std::cout << a << "\n";
  std::cout << fh << "\n";
  std::cout << a1 << "\n";
}
