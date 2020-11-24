

#include "Components/CompoMe/Log/Filter_Log_I_input_log.hpp"
#include "Components/CompoMe/Log/Filter.hpp"

namespace CompoMe {

namespace Log {

Filter_Log_I_input_log::Filter_Log_I_input_log(Filter *comp) : composant(comp) {
  return;
}

//! Destructor
Filter_Log_I_input_log::~Filter_Log_I_input_log() noexcept { return; }

Filter &Filter_Log_I_input_log::get_c() const { return *this->composant; }

} // namespace Log

} // namespace CompoMe
