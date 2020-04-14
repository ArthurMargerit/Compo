
#include "Components/C_p/C_p_I1_ii.hpp"
#include "Components/C_p/C_p.hpp"

namespace C_p {

I1_ii::I1_ii(C_p *comp) : composant(comp) { return; }

//! Destructor
I1_ii::~I1_ii() noexcept { return; }

C_p &I1_ii::get_c() const { return *this->composant; }

// I1 ///////////////////////////////////////////////////////////////////

void I1_ii::save(std::ostream &os) const {
  os << "{";
  os << "type:"
     << "I1_ii";

  os << "}";
}

void I1_ii::load(std::istream &is) {}

} // namespace C_p
