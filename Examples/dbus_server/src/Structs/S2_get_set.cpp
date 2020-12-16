#include "Structs/S2.hpp"

// GET SET ////////////////////////////////////////////////////////////////////

// get/set i1
i32 S2::get_i1() const { return this->i1; }

void S2::set_i1(const i32 &p_i1) { this->i1 = p_i1; }

i32 &S2::a_i1() { return this->i1; }

// get/set i2
i32 S2::get_i2() const { return this->i2; }

void S2::set_i2(const i32 &p_i2) { this->i2 = p_i2; }

i32 &S2::a_i2() { return this->i2; }
