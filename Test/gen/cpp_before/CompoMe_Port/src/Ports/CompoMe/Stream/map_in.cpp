#include "Ports/CompoMe/Stream/map_in.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Stream {

//! Default constructor
map_in::map_in() {}

//! Destructor
map_in::~map_in() {}

// Function IN ////////////////////////////////////////////////////////////////
bool map_in::connect_interface(CompoMe::String interface_key,
                               CompoMe::Interface &p_i) {
  if (p_i.get_caller_stream() == nullptr) {
    C_INFO_TAG("port,stream",
               "CallerStream is not available for this interface");
    return false;
  }

  return CompoMe::Core::c_map_in::connect_interface(interface_key, p_i);
}

bool map_in::is_connected_interface(CompoMe::String interface_key) {
  return CompoMe::Core::c_map_in::is_connected_interface(interface_key);
}

bool map_in::is_connected_interface(CompoMe::Interface &p_i) {
  return CompoMe::Core::c_map_in::is_connected_interface(p_i);
}

bool map_in::disconnect_interface(CompoMe::String interface) {
  return CompoMe::Core::c_map_in::disconnect_interface(interface);
}

bool map_in::disconnect_interface(CompoMe::Interface &p_i) {
  return CompoMe::Core::c_map_in::disconnect_interface(p_i);
}

CompoMe::Interface &map_in::get_interface(CompoMe::String interface_key) {
  return CompoMe::Core::c_map_in::get_interface(interface_key);
}

const std::map<std::tuple<CompoMe::String>, CompoMe::Interface *> &
map_in::get_interfaces_list() {
  return CompoMe::Core::c_map_in::get_interfaces_list();
}

} // namespace Stream

} // namespace CompoMe
