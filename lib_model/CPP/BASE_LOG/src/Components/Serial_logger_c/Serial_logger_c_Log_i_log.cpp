
#include "Components/Serial_logger_c/Serial_logger_c_Log_i_log.hpp"
#include "Components/Serial_logger_c/Serial_logger_c.hpp"

namespace Serial_logger_c {

Log_i_log::Log_i_log(Serial_logger_c *comp) : composant(comp) { return; }

//! Destructor
Log_i_log::~Log_i_log() noexcept { return; }

// //! Move assignment operator
// log& log::operator=(log &&other) noexcept
//                       {

//                       }
void Log_i_log::info(String mess) { return; }
void Log_i_log::debug(String mess) { return; }
void Log_i_log::warning(String mess) { return; }
void Log_i_log::error(String mess) { return; }
void Log_i_log::log(Log_s mess) { return; }

}; // namespace Serial_logger_c
