#pragma once

#include "Data/temperature_sensors.hpp"

#include "Interfaces/Temperature_report_i/Temperature_report_i.hpp"

namespace Temperature_Server {

class Temperature_Server;

class Temperature_report_i_reporter : public ::Temperature_report_i {
public:
  Temperature_Server *composant;

  //! Default constructor
  Temperature_report_i_reporter(Temperature_Server *comp);

  //! Destructor
  virtual ~Temperature_report_i_reporter() noexcept;

  Temperature_report_i_reporter() = delete;
  //! Copy constructor
  Temperature_report_i_reporter(const Temperature_report_i_reporter &other) =
      delete;
  //! Move constructor
  Temperature_report_i_reporter(Temperature_report_i_reporter &&other) = delete;
  // //! Copy assignment operator
  // Temperature_report_i& operator=(const Temperature_report_i &other)=delete;
  // //! Move assignment operator
  // Temperature_report_i& operator=(Temperature_report_i &&other) noexcept;
  virtual void notify(Temperature_sample ts);

protected:
private:
};
};