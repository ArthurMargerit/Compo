
#include "Components/Computer_temperature/Computer_temperature_Temperature_i_gpu_temp.hpp"
#include "Components/Computer_temperature/Computer_temperature.hpp"

namespace Computer_temperature {

Temperature_i_gpu_temp::Temperature_i_gpu_temp(Computer_temperature *comp)
    : composant(comp) {
  return;
}

//! Destructor
Temperature_i_gpu_temp::~Temperature_i_gpu_temp() noexcept { return; }

// //! Move assignment operator
// gpu_temp& gpu_temp::operator=(gpu_temp &&other) noexcept
//                       {

//                       }
Temperature_sample Temperature_i_gpu_temp::get() {

  return Temperature_sample();
}

}; // namespace Computer_temperature
