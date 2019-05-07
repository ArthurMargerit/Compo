#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

#include "Components/Empty_logger_c/Empty_logger_c_Log_i_log.hpp"

namespace Empty_logger_c {

class Empty_logger_c : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  Log_i_log log;

  // Facette

  // c++ 11 def
  //! construction
  Empty_logger_c();

  //! Copy constructor
  Empty_logger_c(const Empty_logger_c &other) = delete;

  //! Move constructor
  Empty_logger_c(Empty_logger_c &&other) = delete;

  //! Destructor
  virtual ~Empty_logger_c() noexcept;

  //! Copy assignment operator
  Empty_logger_c &operator=(const Empty_logger_c &other) = delete;

  //! Move assignment operator
  Empty_logger_c &operator=(Empty_logger_c &&other) noexcept = delete;

  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET

  // function

private:
protected:
};
}