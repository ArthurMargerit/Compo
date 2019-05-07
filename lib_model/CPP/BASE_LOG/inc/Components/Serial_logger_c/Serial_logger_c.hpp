#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

#include "Components/Serial_logger_c/Serial_logger_c_Log_i_log.hpp"

namespace Serial_logger_c {

class Serial_logger_c : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  Log_i_log log;

  // Facette

  // c++ 11 def
  //! construction
  Serial_logger_c();

  //! Copy constructor
  Serial_logger_c(const Serial_logger_c &other) = delete;

  //! Move constructor
  Serial_logger_c(Serial_logger_c &&other) = delete;

  //! Destructor
  virtual ~Serial_logger_c() noexcept;

  //! Copy assignment operator
  Serial_logger_c &operator=(const Serial_logger_c &other) = delete;

  //! Move assignment operator
  Serial_logger_c &operator=(Serial_logger_c &&other) noexcept = delete;

  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET

  bool get_color() const { return color; }

  void set_color(const bool color) { this->color = color; }

  Log_print_e get_format() const { return format; }

  void set_format(const Log_print_e format) { this->format = format; }

  // function

private:
  bool color;

  Log_print_e format;

protected:
};
}