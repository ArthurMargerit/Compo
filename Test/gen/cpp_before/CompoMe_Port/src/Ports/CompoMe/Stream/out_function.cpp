#include "CompoMe/Tools/Call.hpp"
#include "Ports/CompoMe/Stream/out.hpp"

namespace CompoMe {

namespace Stream {

Pair<bool, CompoMe::String> out::call(CompoMe::String cmd) {
  return CompoMe::Tools::call(this->get_require().get_i().get_caller_stream(),
                              cmd);
}

} // namespace Stream

} // namespace CompoMe
