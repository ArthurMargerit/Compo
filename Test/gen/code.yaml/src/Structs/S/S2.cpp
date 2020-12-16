#include "Structs/S/S2.hpp"
#include "Structs/S/S2_fac.hpp"

#include <istream>
#include <ostream>
#include <sstream>

namespace S {

S2::S2() : S2(S1()) {}

S2::S2(S1 p_s) : Struct(), s(p_s) {}

S2::~S2() {}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool S2::operator==(const S::S2 &other) const {
  return true

         && this->s == other.s;
}

bool S2::operator!=(const S::S2 &other) const { return !(*this == other); }

} // namespace S
