#include "CompoMe/Tools/Call.hpp"
#include "Ports/CompoMe/Stream/map_in.hpp"

namespace CompoMe {

namespace Stream {

Pair<bool, CompoMe::String> map_in::call(CompoMe::String cmd) {

  auto pos_key_interface = cmd.str.find(".");
  if (pos_key_interface == std::string::npos) {
    return std::make_pair<bool, CompoMe::String>(false, "NO INTERFACE");
  }

  CompoMe::String interface = cmd.str.substr(0, pos_key_interface);
  cmd.str = cmd.str.substr(pos_key_interface + 1);
  return this->call_on_interface(interface, cmd);
}

Pair<bool, CompoMe::String> map_in::call_on_interface(CompoMe::String interface,
                                                      CompoMe::String cmd) {

  if (!is_connected_interface(interface)) {
    return std::make_pair<bool, CompoMe::String>(
        false, "NO INTERFACE WITH THIS NAME \"" + interface.str + "\"");
  }

  auto& inter = this->get_interface(interface);
  return CompoMe::Tools::call(inter.get_caller_stream(), cmd);
}

} // namespace Stream

} // namespace CompoMe
