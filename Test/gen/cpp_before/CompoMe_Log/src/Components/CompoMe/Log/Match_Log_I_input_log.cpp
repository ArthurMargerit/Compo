

#include "Components/CompoMe/Log/Match_Log_I_input_log.hpp"
#include "Components/CompoMe/Log/Match.hpp"

namespace CompoMe {

namespace Log {

Match_Log_I_input_log::Match_Log_I_input_log(Match *comp) : composant(comp) {
  return;
}

//! Destructor
Match_Log_I_input_log::~Match_Log_I_input_log() noexcept { return; }

Match &Match_Log_I_input_log::get_c() const { return *this->composant; }

} // namespace Log

} // namespace CompoMe
