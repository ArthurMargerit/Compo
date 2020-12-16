

#include "Components/Sensor_Thermal_Sensor_I_capteur1.hpp"
#include "Components/Sensor.hpp"

Sensor_Thermal_Sensor_I_capteur1::Sensor_Thermal_Sensor_I_capteur1(Sensor *comp)
    : composant(comp), ofset() {
  return;
}

//! Destructor
Sensor_Thermal_Sensor_I_capteur1::~Sensor_Thermal_Sensor_I_capteur1() noexcept {
  return;
}

Sensor &Sensor_Thermal_Sensor_I_capteur1::get_c() const {
  return *this->composant;
}
