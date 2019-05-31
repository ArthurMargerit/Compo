
#include "Components/ESP32_temperature/ESP32_temperature_Temperature_i_room_temp.hpp"
#include "Components/ESP32_temperature/ESP32_temperature.hpp"

namespace ESP32_temperature {

Temperature_i_room_temp::Temperature_i_room_temp(ESP32_temperature *comp)
    : composant(comp) {
  return;
}

//! Destructor
Temperature_i_room_temp::~Temperature_i_room_temp() noexcept { return; }

// //! Move assignment operator
// room_temp& room_temp::operator=(room_temp &&other) noexcept
//                       {

//                       }
Temperature_sample Temperature_i_room_temp::get() {

  return Temperature_sample();
}

}; // namespace ESP32_temperature
