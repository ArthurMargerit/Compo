

#include "Components/C/C1_I1_p1.hpp"
#include "Components/C/C1.hpp"

namespace C {

C1_I1_p1::C1_I1_p1(C1 *comp) : composant(comp), v() { return; }

//! Destructor
C1_I1_p1::~C1_I1_p1() noexcept { return; }

C1 &C1_I1_p1::get_c() const { return *this->composant; }

} // namespace C
