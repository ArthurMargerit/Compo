
#include "Components/Empty_logger_c/Empty_logger_c_Log_i_log.hpp"
#include "Components/Empty_logger_c/Empty_logger_c.hpp"

namespace Empty_logger_c {

Log_i_log::Log_i_log(Empty_logger_c *comp) : composant(comp) { return; }

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

}; // namespace Empty_logger_c
