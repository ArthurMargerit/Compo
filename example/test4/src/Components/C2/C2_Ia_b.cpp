
#include "Components/C2/C2_Ia_b.hpp"
#include "Components/C2/C2.hpp"

namespace C2 {

Ia_b::Ia_b(C2 *comp) : composant(comp) { return; }

//! Destructor
Ia_b::~Ia_b() noexcept { return; }
i Ia_b::ping(vec<i> p) { return i(); }
i Ia_b::pp(vec<i> p1, vec<d> p2) { return i(); }
vec<i> Ia_b::p() { return vec<i>(); }

}; // namespace C2
