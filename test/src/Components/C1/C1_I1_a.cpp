
#include "Components/C1/C1_I1_a.hpp"
#include "Components/C1/C1.hpp"

namespace C1 {

I1_a::I1_a(C1 *comp) : composant(comp) { return; }

//! Destructor
I1_a::~I1_a() noexcept { return; }

// //! Move assignment operator
// a& a::operator=(a &&other) noexcept
//                       {

//                       }
int I1_a::add(int x, int y) { return 0; }

}; // namespace C1
