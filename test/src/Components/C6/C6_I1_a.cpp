
#include "Components/C6/C6_I1_a.hpp"
#include "Components/C6/C6.hpp"

namespace C6 {

I1_a::I1_a(C6 *comp) : composant(comp) { return; }

//! Destructor
I1_a::~I1_a() noexcept { return; }

// //! Move assignment operator
// a& a::operator=(a &&other) noexcept
//                       {

//                       }
int I1_a::add(int x, int y) { return 0; }

}; // namespace C6
