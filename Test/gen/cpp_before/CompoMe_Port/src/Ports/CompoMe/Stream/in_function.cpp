#include "CompoMe/Tools/Call.hpp"
#include "Ports/CompoMe/Stream/in.hpp"

namespace CompoMe {

namespace Stream {

Pair<bool, CompoMe::String> in::call(CompoMe::String cmd) {
  return CompoMe::Tools::call(this->get_interface().get_caller_stream(), cmd);
}

} // namespace Stream

} // namespace CompoMe
