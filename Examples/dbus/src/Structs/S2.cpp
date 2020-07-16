#include "Structs/S2.hpp"
#include "Structs/S2_fac.hpp"

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

S2::S2() : S2(i32(), i32()) {}

S2::S2(i32 p_i1, i32 p_i2)
    : Struct(), i1(p_i1)

      ,
      i2(p_i2) {}

S2::~S2() {}

// GET SET ////////////////////////////////////////////////////////////////////
// get/set i1
i32 S2::get_i1() const { return this->i1; }

void S2::set_i1(const i32 &p_i1) { this->i1 = p_i1; }

i32 &S2::a_i1() { return this->i1; }
// get/set i2
i32 S2::get_i2() const { return this->i2; }

void S2::set_i2(const i32 &p_i2) { this->i2 = p_i2; }

i32 &S2::a_i2() { return this->i2; }

// FUNCTION ///////////////////////////////////////////////////////////////////
// from S2

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool S2::operator==(const S2 &other) const {
  return true

         && this->i1 == other.i1

         && this->i2 == other.i2;
}

bool S2::operator!=(const S2 &other) const { return !(*this == other); }
