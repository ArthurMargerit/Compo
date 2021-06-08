#include "Ports/CompoMe/Core/DCI_map_in.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Core {

//! Default constructor
DCI_map_in::DCI_map_in() : map_dest_compo_inter() {}

//! Destructor
DCI_map_in::~DCI_map_in() {}

// Function IN ////////////////////////////////////////////////////////////////
bool DCI_map_in::connect_interface(CompoMe::String dest_key,
                                   CompoMe::String component_key,
                                   CompoMe::String interface_key,
                                   CompoMe::Interface &p_i) {
  if (this->is_connected_interface(dest_key, component_key, interface_key)) {
    C_WARNING_TAG("port", "A Interface is already connected to ", dest_key, "/",
                  component_key, "/", interface_key);
  }

  this->map_dest_compo_inter[std::make_tuple(dest_key, component_key,
                                             interface_key)] = &p_i;
  return true;
}

bool DCI_map_in::is_connected_interface(CompoMe::String dest_key,
                                        CompoMe::String component_key,
                                        CompoMe::String interface_key) {
  auto l_res = this->map_dest_compo_inter.find(
      std::make_tuple(dest_key, component_key, interface_key));
  return l_res != this->map_dest_compo_inter.end();
}

bool DCI_map_in::is_connected_interface(CompoMe::Interface &p_i) {
  for (auto it = this->map_dest_compo_inter.begin();
       it != this->map_dest_compo_inter.end(); it++) {
    if (it->second == &p_i) {
      return true;
    }
  }
  return false;
}

bool DCI_map_in::disconnect_interface(CompoMe::String dest_key,
                                      CompoMe::String component_key,
                                      CompoMe::String interface_key) {
  auto l_element = this->map_dest_compo_inter.find(
      std::make_tuple(dest_key, component_key, interface_key));
  if (l_element == this->map_dest_compo_inter.end()) {
    return false;
  }

  this->map_dest_compo_inter.erase(l_element);
  return true;
}

bool DCI_map_in::disconnect_interface(CompoMe::Interface &p_i) {
  for (auto it = this->map_dest_compo_inter.begin();
       it != this->map_dest_compo_inter.end(); it++) {
    if (it->second == &p_i) {
      this->map_dest_compo_inter.erase(it);
      return true;
    }
  }
  return false;
}

CompoMe::Interface &DCI_map_in::get_interface(CompoMe::String dest_key,
                                              CompoMe::String component_key,
                                              CompoMe::String interface_key) {
  return *this->map_dest_compo_inter[std::make_tuple(dest_key, component_key,
                                                     interface_key)];
}

std::map<std::tuple<CompoMe::String, CompoMe::String, CompoMe::String>,
         CompoMe::Interface *>
DCI_map_in::get_interfaces_list() {
  return this->map_dest_compo_inter;
}

} // namespace Core

} // namespace CompoMe
