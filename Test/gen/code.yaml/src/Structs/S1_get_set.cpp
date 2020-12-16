#include "Structs/S1.hpp"

// GET SET ////////////////////////////////////////////////////////////////////

// get/set a
B::i S1::get_a() const { return this->a; }

void S1::set_a(const B::i &p_a) { this->a = p_a; }

B::i &S1::a_a() { return this->a; }
