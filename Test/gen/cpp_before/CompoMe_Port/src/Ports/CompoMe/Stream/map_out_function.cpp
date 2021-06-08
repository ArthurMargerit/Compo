#include "Ports/CompoMe/Stream/map_out.hpp"

namespace CompoMe {

namespace Stream {

Pair<bool, CompoMe::String> map_out::call(CompoMe::String cmd) {
  return Pair<bool, CompoMe::String>();
}
Pair<bool, CompoMe::String>
map_out::call_on_interface(CompoMe::String interface, CompoMe::String cmd) {
  return Pair<bool, CompoMe::String>();
}

} // namespace Stream

} // namespace CompoMe
