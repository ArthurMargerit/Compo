

#include "Components/C2_Math_async_return_back_call.hpp"
#include "Components/C2.hpp"

C2_Math_async_return_back_call::C2_Math_async_return_back_call(C2 *comp)
    : composant(comp) {
  return;
}

//! Destructor
C2_Math_async_return_back_call::~C2_Math_async_return_back_call() noexcept {
  return;
}

C2 &C2_Math_async_return_back_call::get_c() const { return *this->composant; }
