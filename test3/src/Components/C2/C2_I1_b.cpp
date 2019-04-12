
#include "Components/C2/C2_I1_b.hpp"
#include "Components/C2/C2.hpp"

namespace C2 {

I1_b::I1_b(C2 *comp) : composant(comp) { return; }

//! Destructor
I1_b::~I1_b() noexcept { return; }

// //! Move assignment operator
// b& b::operator=(b &&other) noexcept
//                       {

//                       }
int I1_b::add(int x, int y) { return 0; }

}; // namespace C2
