#include "Components/C/C1.hpp"
#include "Components/C/C1_I1_p1.hpp"

namespace C {

// I1 ///////////////////////////////////////////////////////////////////
// get/set v
B::i C1_I1_p1::get_v() const { return this->v; }

void C1_I1_p1::set_v(const B::i &v) { this->v = v; }

} // namespace C
