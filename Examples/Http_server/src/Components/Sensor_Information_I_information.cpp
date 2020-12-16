

#include "Components/Sensor_Information_I_information.hpp"
#include "Components/Sensor.hpp"

Sensor_Information_I_information::Sensor_Information_I_information(Sensor *comp)
    : composant(comp) {
  return;
}

//! Destructor
Sensor_Information_I_information::~Sensor_Information_I_information() noexcept {
  return;
}

Sensor &Sensor_Information_I_information::get_c() const {
  return *this->composant;
}
