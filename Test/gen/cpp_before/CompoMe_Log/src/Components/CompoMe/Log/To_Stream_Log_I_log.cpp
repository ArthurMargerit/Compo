

#include "Components/CompoMe/Log/To_Stream_Log_I_log.hpp"
#include "Components/CompoMe/Log/To_Stream.hpp"

namespace CompoMe {

namespace Log {

To_Stream_Log_I_log::To_Stream_Log_I_log(To_Stream *comp) : composant(comp) {
  return;
}

//! Destructor
To_Stream_Log_I_log::~To_Stream_Log_I_log() noexcept { return; }

To_Stream &To_Stream_Log_I_log::get_c() const { return *this->composant; }

} // namespace Log

} // namespace CompoMe
