#include "Components/Sensor.hpp"
#include "Components/Sensor_Thermal_Sensor_I_capteur1.hpp"

// Thermal_Sensor_I
// ///////////////////////////////////////////////////////////////////
// get/set ofset
double Sensor_Thermal_Sensor_I_capteur1::get_ofset() const {

  return this->ofset;
}

void Sensor_Thermal_Sensor_I_capteur1::set_ofset(const double &ofset) {

  this->ofset = ofset;
}
