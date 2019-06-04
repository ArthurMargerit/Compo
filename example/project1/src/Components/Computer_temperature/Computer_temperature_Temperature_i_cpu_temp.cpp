
#include "Components/Computer_temperature/Computer_temperature_Temperature_i_cpu_temp.hpp"
#include "Components/Computer_temperature/Computer_temperature.hpp"

namespace Computer_temperature {

Temperature_i_cpu_temp::Temperature_i_cpu_temp(Computer_temperature *comp)
    : composant(comp) {
  return;
}

//! Destructor
Temperature_i_cpu_temp::~Temperature_i_cpu_temp() noexcept { return; }

// //! Move assignment operator
// cpu_temp& cpu_temp::operator=(cpu_temp &&other) noexcept
//                       {

//                       }
Temperature_sample Temperature_i_cpu_temp::get() {

  return Temperature_sample();
}

}; // namespace Computer_temperature
