
#include "Components/C1/C1_I1_b.hpp"
#include "Components/C1/C1.hpp"

namespace C1 {

I1_b::I1_b(C1 *comp) : composant(comp) { return; }

//! Destructor
I1_b::~I1_b() noexcept { return; }

// //! Move assignment operator
// b& b::operator=(b &&other) noexcept
//                       {

//                       }
int I1_b::add(int x, int y) { return 0; }

}; // namespace C1
