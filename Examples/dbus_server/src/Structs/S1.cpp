#include "Structs/S1.hpp"
#include "Structs/S1_fac.hpp"

#include <istream>
#include <ostream>
#include <sstream>

S1::S1() : S1(i32()) {}

S1::S1(i32 p_i1) : Struct(), i1(p_i1) {}

S1::~S1() {}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool S1::operator==(const S1 &other) const {
  return true

         && this->i1 == other.i1;
}

bool S1::operator!=(const S1 &other) const { return !(*this == other); }
