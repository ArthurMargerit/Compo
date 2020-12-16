#include "Structs/S1.hpp"
#include "Structs/S1_fac.hpp"

#include <istream>
#include <ostream>
#include <sstream>

S1::S1() : S1(B::i()) {}

S1::S1(B::i p_a) : Struct(), a(p_a) {}

S1::~S1() {}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool S1::operator==(const S1 &other) const {
  return true

         && this->a == other.a;
}

bool S1::operator!=(const S1 &other) const { return !(*this == other); }
