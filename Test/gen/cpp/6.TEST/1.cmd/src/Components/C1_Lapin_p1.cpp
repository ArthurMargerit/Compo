
#include "Components/C1_Lapin_p1.hpp"
#include "Components/C1.hpp"

C1_Lapin_p1::C1_Lapin_p1(C1 *comp) : composant(comp) { return; }

//! Destructor
C1_Lapin_p1::~C1_Lapin_p1() noexcept { return; }

C1 &C1_Lapin_p1::get_c() const { return *this->composant; }

int C1_Lapin_p1::add(int a, int b) {

  int ret =

      int();

  return ret;
}
int C1_Lapin_p1::sub(int a, int b) {

  int ret =

      int();

  return ret;
}
int C1_Lapin_p1::time(int a, int b) {

  int ret =

      int();

  return ret;
}
int C1_Lapin_p1::div(int a, int b) {

  int ret =

      int();

  return ret;
}

// Lapin ///////////////////////////////////////////////////////////////////

void C1_Lapin_p1::save(std::ostream &os) const {
  os << "{";
  os << "type:"
     << "C1_Lapin_p1";

  os << "}";
}

void C1_Lapin_p1::load(std::istream &is) {}
