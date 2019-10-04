
#include "Components/C1/C1_Lapin_p1.hpp"
#include "Components/C1/C1.hpp"

namespace C1 {

Lapin_p1::Lapin_p1(C1 *comp) : composant(comp) { return; }

//! Destructor
Lapin_p1::~Lapin_p1() noexcept { return; }

int Lapin_p1::add(int a, int b) {

  return a+b;
}
int Lapin_p1::sub(int a, int b) {

  return a-b;
}
int Lapin_p1::time(int a, int b) {

  return a*b;
}

// Lapin ///////////////////////////////////////////////////////////////////

}; // namespace C1
