

#include "Components/CompoMe/Log/To_File_Log_I_log.hpp"
#include "Components/CompoMe/Log/To_File.hpp"

namespace CompoMe {

namespace Log {

To_File_Log_I_log::To_File_Log_I_log(To_File *comp) : composant(comp) {
  return;
}

//! Destructor
To_File_Log_I_log::~To_File_Log_I_log() noexcept { return; }

To_File &To_File_Log_I_log::get_c() const { return *this->composant; }

} // namespace Log

} // namespace CompoMe
