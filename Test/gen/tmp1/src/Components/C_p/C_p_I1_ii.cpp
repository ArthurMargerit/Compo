
#include "Components/C_p/C_p_I1_ii.hpp"
#include "Components/C_p/C_p.hpp"

namespace C_p {

I1_ii::I1_ii(C_p *comp) : composant(comp) { return; }

//! Destructor
I1_ii::~I1_ii() noexcept { return; }

C_p &I1_ii::get_c() const { return *this->composant; }

void I1_ii::f() {

  void();

  return;
}
void I1_ii::f1() {

  void();

  return;
}
void I1_ii::f2(i32 a) {

  void();

  return;
}
void I1_ii::f3(i32 a, i32 b) {

  void();

  return;
}
i32 I1_ii::f4() {

  i32 ret =

      i32();

  return ret;
}
i32 I1_ii::f5(i32 a) {

  i32 ret =

      i32();

  return ret;
}

// I1 ///////////////////////////////////////////////////////////////////

void I1_ii::save(std::ostream &os) const {
  os << "{";
  os << "type:"
     << "I1_ii";

  os << "}";
}

void I1_ii::load(std::istream &is) {}

} // namespace C_p
