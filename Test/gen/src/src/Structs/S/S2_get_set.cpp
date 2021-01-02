#include "Structs/S/S2.hpp"

namespace S {

// GET SET ////////////////////////////////////////////////////////////////////

// get/set s
S1 S2::get_s() const { return this->s; }

void S2::set_s(const S1 &p_s) { this->s = p_s; }

S1 &S2::a_s() { return this->s; }

} // namespace S
