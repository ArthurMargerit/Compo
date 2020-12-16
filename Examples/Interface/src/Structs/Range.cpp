#include "Structs/Range.hpp"
#include "Structs/Range_fac.hpp"

#include <istream>
#include <ostream>
#include <sstream>

Range::Range() : Range(double(), double()) {}

Range::Range(double p_min, double p_max)
    : Struct(), min(p_min)

      ,
      max(p_max) {}

Range::~Range() {}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool Range::operator==(const Range &other) const {
  return true

         && this->min == other.min

         && this->max == other.max;
}

bool Range::operator!=(const Range &other) const { return !(*this == other); }
