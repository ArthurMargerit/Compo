#pragma once

#include "Components/Temperature_Server/Temperature_Server.hpp"

// TYPE
#include "Data/temperature_sensors.hpp"

// STRUCT

// INTERFACES

namespace Temperature_Server_csv {

class Temperature_Server_csv : public Temperature_Server::Temperature_Server {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  // Facette

  // c++ 11 def
  //! construction
  Temperature_Server_csv();

  //! Copy constructor
  Temperature_Server_csv(const Temperature_Server_csv &other) = delete;

  //! Move constructor
  Temperature_Server_csv(Temperature_Server_csv &&other) = delete;

  //! Destructor
  virtual ~Temperature_Server_csv() noexcept;

  //! Copy assignment operator
  Temperature_Server_csv &
  operator=(const Temperature_Server_csv &other) = delete;

  //! Move assignment operator
  Temperature_Server_csv &
  operator=(Temperature_Server_csv &&other) noexcept = delete;

  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET

  String get_save_path() const { return save_path; }

  void set_save_path(const String save_path) { this->save_path = save_path; }

  // function

private:
  String save_path;

protected:
};
}