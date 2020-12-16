#include "Structs/S1.hpp"

// GET SET ////////////////////////////////////////////////////////////////////

// get/set i1
i32 S1::get_i1() const { return this->i1; }

void S1::set_i1(const i32 &p_i1) { this->i1 = p_i1; }

i32 &S1::a_i1() { return this->i1; }
