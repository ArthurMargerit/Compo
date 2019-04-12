
#include "Components/C5/C5_I1_a.hpp"
#include "Components/C5/C5.hpp"

namespace C5 {

I1_a::I1_a(C5 *comp) : composant(comp) { return; }

//! Destructor
I1_a::~I1_a() noexcept { return; }

// //! Move assignment operator
// a& a::operator=(a &&other) noexcept
//                       {

//                       }
int I1_a::add(int x, int y) { return 0; }

}; // namespace C5
