
#include "Components/C1/C1_I1_g.hpp"
#include "Components/C1/C1.hpp"

namespace C1 {

I1_g::I1_g(C1 *comp) : composant(comp) { return; }

//! Destructor
I1_g::~I1_g() noexcept { return; }

// //! Move assignment operator
// g& g::operator=(g &&other) noexcept
//                       {

//                       }
int I1_g::add(int x, int y) { return 0; }

}; // namespace C1
