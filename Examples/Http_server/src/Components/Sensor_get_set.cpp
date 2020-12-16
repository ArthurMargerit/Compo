#include "Components/Sensor.hpp"

/////////////////////////////////////////////////////////////////////////////
//                                   PROVIDE                               //
/////////////////////////////////////////////////////////////////////////////

Sensor_Information_I_information &Sensor::get_information() {
  return this->information;
}

Sensor_Thermal_Sensor_I_capteur1 &Sensor::get_capteur1() {
  return this->capteur1;
}

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// name
CompoMe::String Sensor::get_name() const { return this->name; }

void Sensor::set_name(const CompoMe::String &name) { this->name = name; }

// type
CompoMe::String Sensor::get_type() const { return this->type; }

void Sensor::set_type(const CompoMe::String &type) { this->type = type; }

// location
CompoMe::String Sensor::get_location() const { return this->location; }

void Sensor::set_location(const CompoMe::String &location) {
  this->location = location;
}

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////
