#pragma once

#include "Data/Types.hpp"

#include "Interfaces/Log_i/Log_i.hpp"

namespace Serial_logger_c {

class Serial_logger_c;

class Log_i_log : public ::Log_i {
public:
  Serial_logger_c *composant;

  //! Default constructor
  Log_i_log(Serial_logger_c *comp);

  //! Destructor
  virtual ~Log_i_log() noexcept;

  Log_i_log() = delete;
  //! Copy constructor
  Log_i_log(const Log_i_log &other) = delete;
  //! Move constructor
  Log_i_log(Log_i_log &&other) = delete;
  // //! Copy assignment operator
  // Log_i& operator=(const Log_i &other)=delete;
  // //! Move assignment operator
  // Log_i& operator=(Log_i &&other) noexcept;
  virtual void info(String mess);
  virtual void debug(String mess);
  virtual void warning(String mess);
  virtual void error(String mess);
  virtual void log(Log_s mess);

protected:
private:
};

}; // namespace Serial_logger_c