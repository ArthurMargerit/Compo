

#include "Components/Compute_Calc_I_compute.hpp"
#include "Components/Compute.hpp"

Compute_Calc_I_compute::Compute_Calc_I_compute(Compute *comp)
    : composant(comp) {
  return;
}

//! Destructor
Compute_Calc_I_compute::~Compute_Calc_I_compute() noexcept { return; }

Compute &Compute_Calc_I_compute::get_c() const { return *this->composant; }
