#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/temperature_sensors.hpp"

// STRUCT

// INTERFACES

#include "Components/Computer_temperature/Computer_temperature_Temperature_i_cpu_temp.hpp"

#include "Components/Computer_temperature/Computer_temperature_Temperature_i_gpu_temp.hpp"

#include "Interfaces/Temperature_report_i/Temperature_report_i.hpp"

namespace Computer_temperature {

class Computer_temperature : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  Temperature_i_cpu_temp cpu_temp;

  Temperature_i_gpu_temp gpu_temp;

  // Facette

  Temperature_report_i *report;

  // c++ 11 def
  //! construction
  Computer_temperature();

  //! Copy constructor
  Computer_temperature(const Computer_temperature &other) = delete;

  //! Move constructor
  Computer_temperature(Computer_temperature &&other) = delete;

  //! Destructor
  virtual ~Computer_temperature() noexcept;

  //! Copy assignment operator
  Computer_temperature &operator=(const Computer_temperature &other) = delete;

  //! Move assignment operator
  Computer_temperature &
  operator=(Computer_temperature &&other) noexcept = delete;

  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET

  int get_freq() const { return freq; }

  void set_freq(const int freq) { this->freq = freq; }

  // function

private:
  int freq;

protected:
};
}