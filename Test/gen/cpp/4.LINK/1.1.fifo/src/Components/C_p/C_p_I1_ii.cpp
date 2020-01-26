
#include "Components/C_p/C_p_I1_ii.hpp"
#include "Components/C_p/C_p.hpp"

namespace C_p {

I1_ii::I1_ii(C_p *comp) : composant(comp), a(), b() { return; }

//! Destructor
I1_ii::~I1_ii() noexcept { return; }

C_p &I1_ii::get_c() const { return *this->composant; }

void I1_ii::f1() {

  void();

  return;
}
int I1_ii::f3() {

  int ret =

      int();

  return ret;
}
void I1_ii::f2(int p1) {

  void();

  return;
}
int I1_ii::f4(int p1) {

  int ret =

      int();

  return ret;
}
int I1_ii::f5(int p1, int p2) {

  int ret =

      int();

  return ret;
}

// I1 ///////////////////////////////////////////////////////////////////
// get/set a
int I1_ii::get_a() const { return this->a; }

void I1_ii::set_a(const int &a) { this->a = a; }
// get/set b
int I1_ii::get_b() const { return this->b; }

void I1_ii::set_b(const int &b) { this->b = b; }

void I1_ii::save(std::ostream &os) const {
  os << "{";
  os << "type:"
     << "I1_ii";

  os << ",data:{";

  os << "a:" << this->get_a();
  os << ",";
  os << "b:" << this->get_b();

  os << "}";

  os << "}";
}

void I1_ii::load(std::istream &is) {}

} // namespace C_p