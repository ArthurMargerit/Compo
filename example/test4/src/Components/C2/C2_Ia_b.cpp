
#include "Components/C2/C2_Ia_b.hpp"
#include "Components/C2/C2.hpp"

namespace C2 {

Ia_b::Ia_b(C2 *comp) : composant(comp) { return; }

//! Destructor
Ia_b::~Ia_b() noexcept { return; }
int_tt Ia_b::ping(vec<int_tt> p) { return int_tt(); }
int_tt Ia_b::pp(vec<int_tt> p1, vec<d> p2) { return int_tt(); }
vec<int_tt> Ia_b::p() { return vec<int_tt>(); }

}; // namespace C2
