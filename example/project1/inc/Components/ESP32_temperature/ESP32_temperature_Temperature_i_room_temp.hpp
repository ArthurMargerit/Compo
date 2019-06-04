#pragma once

#include "Data/temperature_sensors.hpp"

#include "Interfaces/Temperature_i/Temperature_i.hpp"

namespace ESP32_temperature {

class ESP32_temperature;

class Temperature_i_room_temp : public ::Temperature_i {
public:
  ESP32_temperature *composant;

  //! Default constructor
  Temperature_i_room_temp(ESP32_temperature *comp);

  //! Destructor
  virtual ~Temperature_i_room_temp() noexcept;

  Temperature_i_room_temp() = delete;
  //! Copy constructor
  Temperature_i_room_temp(const Temperature_i_room_temp &other) = delete;
  //! Move constructor
  Temperature_i_room_temp(Temperature_i_room_temp &&other) = delete;
  // //! Copy assignment operator
  // Temperature_i& operator=(const Temperature_i &other)=delete;
  // //! Move assignment operator
  // Temperature_i& operator=(Temperature_i &&other) noexcept;
  virtual Temperature_sample get();

protected:
private:
};
};