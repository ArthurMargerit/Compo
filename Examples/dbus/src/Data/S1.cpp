#include "Data/S1.hpp"
#include "Data/S1_fac.hpp"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

S1::S1() : S1(i32()) {}

S1::S1(i32 p_i1) : Struct(), i1(p_i1) {}

S1::~S1() {}

// GET SET ////////////////////////////////////////////////////////////////////
// get/set i1
i32 S1::get_i1() const { return this->i1; }

void S1::set_i1(const i32 &p_i1) { this->i1 = p_i1; }

i32 &S1::a_i1() { return this->i1; }

// FUNCTION ///////////////////////////////////////////////////////////////////
// from S1

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool S1::operator==(const S1 &other) const {
  return true

         && this->i1 == other.i1;
}

bool S1::operator!=(const S1 &other) const { return !(*this == other); }
