

#include "Components/CompoMe/Log/Log_buffer_Log_I_log.hpp"
#include "Components/CompoMe/Log/Log_buffer.hpp"

namespace CompoMe {

namespace Log {

Log_buffer_Log_I_log::Log_buffer_Log_I_log(Log_buffer *comp) : composant(comp) {
  return;
}

//! Destructor
Log_buffer_Log_I_log::~Log_buffer_Log_I_log() noexcept { return; }

Log_buffer &Log_buffer_Log_I_log::get_c() const { return *this->composant; }

} // namespace Log

} // namespace CompoMe
