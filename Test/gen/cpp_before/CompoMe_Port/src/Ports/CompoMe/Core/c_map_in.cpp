#include "Ports/CompoMe/Core/c_map_in.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Core {

//! Default constructor
c_map_in::c_map_in() : c_map_interface() {}

//! Destructor
c_map_in::~c_map_in() {}

// Function IN ////////////////////////////////////////////////////////////////
bool c_map_in::connect_interface(CompoMe::String interface_key,
                               CompoMe::Interface &p_i) {
  if (this->is_connected_interface(interface_key)) {
    C_WARNING_TAG("port", "A Interface is already connected to ",
                  interface_key);
  }

  this->c_map_interface[std::make_tuple(interface_key)] = &p_i;
  return true;
}

bool c_map_in::is_connected_interface(CompoMe::String interface_key) {
  auto l_res = this->c_map_interface.find(std::make_tuple(interface_key));
  return l_res != this->c_map_interface.end();
}

bool c_map_in::is_connected_interface(CompoMe::Interface &p_i) {
  for (auto it = this->c_map_interface.begin(); it != this->c_map_interface.end();
       it++) {
    if (it->second == &p_i) {
      return true;
    }
  }
  return false;
}

bool c_map_in::disconnect_interface(CompoMe::String interface_key) {
  auto l_element = this->c_map_interface.find(std::make_tuple(interface_key));
  if (l_element == this->c_map_interface.end()) {
    return false;
  }

  this->c_map_interface.erase(l_element);
  return true;
}

bool c_map_in::disconnect_interface(CompoMe::Interface &p_i) {

  for (auto it = this->c_map_interface.begin(); it != this->c_map_interface.end();
       it++) {
    if (it->second == &p_i) {
      this->c_map_interface.erase(it);
      return true;
    }
  }
  return false;
}

CompoMe::Interface &c_map_in::get_interface(CompoMe::String interface_key) {
  return *this->c_map_interface[std::make_tuple(interface_key)];
}

const std::map<std::tuple<CompoMe::String>, CompoMe::Interface *> &
c_map_in::get_interfaces_list() {
  return this->c_map_interface;
}

} // namespace Core

} // namespace CompoMe
