#include "Structs/Range.hpp"
#include "Structs/Range_fac.hpp"

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

Range::Range() : Range(double(), double()) {}

Range::Range(double p_min, double p_max)
    : Struct(), min(p_min)

      ,
      max(p_max) {}

Range::~Range() {}

// GET SET ////////////////////////////////////////////////////////////////////
// get/set min
double Range::get_min() const { return this->min; }

void Range::set_min(const double &p_min) { this->min = p_min; }

double &Range::a_min() { return this->min; }
// get/set max
double Range::get_max() const { return this->max; }

void Range::set_max(const double &p_max) { this->max = p_max; }

double &Range::a_max() { return this->max; }

// FUNCTION ///////////////////////////////////////////////////////////////////
// from Range

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool Range::operator==(const Range &other) const {
  return true

         && this->min == other.min

         && this->max == other.max;
}

bool Range::operator!=(const Range &other) const { return !(*this == other); }
