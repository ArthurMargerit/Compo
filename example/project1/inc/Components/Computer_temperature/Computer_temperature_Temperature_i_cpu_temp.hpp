#pragma once

#include "Data/temperature_sensors.hpp"

#include "Interfaces/Temperature_i/Temperature_i.hpp"

namespace Computer_temperature {

class Computer_temperature;

class Temperature_i_cpu_temp : public ::Temperature_i {
public:
  Computer_temperature *composant;

  //! Default constructor
  Temperature_i_cpu_temp(Computer_temperature *comp);

  //! Destructor
  virtual ~Temperature_i_cpu_temp() noexcept;

  Temperature_i_cpu_temp() = delete;
  //! Copy constructor
  Temperature_i_cpu_temp(const Temperature_i_cpu_temp &other) = delete;
  //! Move constructor
  Temperature_i_cpu_temp(Temperature_i_cpu_temp &&other) = delete;
  // //! Copy assignment operator
  // Temperature_i& operator=(const Temperature_i &other)=delete;
  // //! Move assignment operator
  // Temperature_i& operator=(Temperature_i &&other) noexcept;
  virtual Temperature_sample get();

protected:
private:
};
};