
#include "Components/C_turn/C_turn_I1_ii.hpp"
#include "Components/C_turn/C_turn.hpp"

namespace C_turn {

I1_ii::I1_ii(C_turn *comp) : composant(comp) { return; }

//! Destructor
I1_ii::~I1_ii() noexcept { return; }

C_turn &I1_ii::get_c() const { return *this->composant; }

void I1_ii::f1() {

  //
  this->get_c().get_sc_cp().get_ii().f1();

  return;
}
int I1_ii::f3() {

  int ret =

      //
      this->get_c().get_sc_cp().get_ii().f3();

  return ret;
}
void I1_ii::f2(int p1) {

  //
  this->get_c().get_sc_cp().get_ii().f2(p1);

  return;
}
int I1_ii::f4(int p1) {

  int ret =

      //
      this->get_c().get_sc_cp().get_ii().f4(p1);

  return ret;
}
int I1_ii::f5(int p1, int p2) {

  int ret =

      //
      this->get_c().get_sc_cp().get_ii().f5(p1, p2);

  return ret;
}

// I1 ///////////////////////////////////////////////////////////////////
// get/set a
int I1_ii::get_a() const { return this->get_c().get_sc_cp().get_ii().get_a(); }

void I1_ii::set_a(const int &a) { this->get_c().get_sc_cp().get_ii().set_a(a); }
// get/set b
int I1_ii::get_b() const { return this->get_c().get_sc_cp().get_ii().get_b(); }

void I1_ii::set_b(const int &b) { this->get_c().get_sc_cp().get_ii().set_b(b); }

void I1_ii::save(std::ostream &os) const {
  os << "{";
  os << "type:"
     << "I1_ii";

  os << "}";
}

void I1_ii::load(std::istream &is) {}

} // namespace C_turn