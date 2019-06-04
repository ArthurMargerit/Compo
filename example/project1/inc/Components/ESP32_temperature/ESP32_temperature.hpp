#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/temperature_sensors.hpp"

// STRUCT

// INTERFACES

#include "Components/ESP32_temperature/ESP32_temperature_Temperature_i_room_temp.hpp"

#include "Interfaces/Temperature_report_i/Temperature_report_i.hpp"

namespace ESP32_temperature {

class ESP32_temperature : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  Temperature_i_room_temp room_temp;

  // Facette

  Temperature_report_i *out;

  // c++ 11 def
  //! construction
  ESP32_temperature();

  //! Copy constructor
  ESP32_temperature(const ESP32_temperature &other) = delete;

  //! Move constructor
  ESP32_temperature(ESP32_temperature &&other) = delete;

  //! Destructor
  virtual ~ESP32_temperature() noexcept;

  //! Copy assignment operator
  ESP32_temperature &operator=(const ESP32_temperature &other) = delete;

  //! Move assignment operator
  ESP32_temperature &operator=(ESP32_temperature &&other) noexcept = delete;

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

  String get_room() const { return room; }

  void set_room(const String room) { this->room = room; }

  // function

private:
  int freq;

  String room;

protected:
};
}