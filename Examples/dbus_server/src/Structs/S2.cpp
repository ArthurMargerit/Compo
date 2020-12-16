#include "Structs/S2.hpp"
#include "Structs/S2_fac.hpp"

#include <istream>
#include <ostream>
#include <sstream>

S2::S2() : S2(i32(), i32()) {}

S2::S2(i32 p_i1, i32 p_i2)
    : Struct(), i1(p_i1)

      ,
      i2(p_i2) {}

S2::~S2() {}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool S2::operator==(const S2 &other) const {
  return true

         && this->i1 == other.i1

         && this->i2 == other.i2;
}

bool S2::operator!=(const S2 &other) const { return !(*this == other); }
