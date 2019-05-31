#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/temperature_sensors.hpp"

// STRUCT

#include "Data/Struct_Temperature_sample.hpp"

// INTERFACES

#include "Components/Temperature_Server/Temperature_Server_Temperature_report_i_reporter.hpp"

namespace Temperature_Server {

class Temperature_Server : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  Temperature_report_i_reporter reporter;

  // Facette

  // c++ 11 def
  //! construction
  Temperature_Server();

  //! Copy constructor
  Temperature_Server(const Temperature_Server &other) = delete;

  //! Move constructor
  Temperature_Server(Temperature_Server &&other) = delete;

  //! Destructor
  virtual ~Temperature_Server() noexcept;

  //! Copy assignment operator
  Temperature_Server &operator=(const Temperature_Server &other) = delete;

  //! Move assignment operator
  Temperature_Server &operator=(Temperature_Server &&other) noexcept = delete;

  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET

  // function

  virtual int save();

  virtual int display();

  virtual void add(Temperature_sample ts);

private:
protected:
};
}