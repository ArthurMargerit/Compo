
#include "Components/C2/C2_I1_a.hpp"
#include "Components/C2/C2.hpp"

namespace C2 {

I1_a::I1_a(C2 *comp) : composant(comp) { return; }

//! Destructor
I1_a::~I1_a() noexcept { return; }

// //! Move assignment operator
// a& a::operator=(a &&other) noexcept
//                       {

//                       }
int I1_a::add(int x, int y) { return 0; }

}; // namespace C2
