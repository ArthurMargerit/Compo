#include "Ports/CompoMe/Core/DCI_map_out.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Core {

//! Default constructor
DCI_map_out::DCI_map_out() : map_dest_compo_inter_require() {}

//! Destructor
DCI_map_out::~DCI_map_out() {}

// Function OUT ////////////////////////////////////////////////////////////////
bool DCI_map_out::connect_require(CompoMe::String dest_key,
                                  CompoMe::String component_key,
                                  CompoMe::String interface_key,
                                  CompoMe::Require_helper &p_r) {
  if (this->is_connected_require(dest_key, component_key, interface_key)) {
    C_WARNING_TAG("port", "A Interface is already connected to ", dest,
                  component_key, "/", interface_key);
  }

  this->map_dest_compo_inter_require[std::make_tuple(dest_key, component_key,
                                                     interface_key)] = &p_r;
  return true;
}

bool DCI_map_out::is_connected_require(CompoMe::String dest_key,
                                       CompoMe::String component_key,
                                       CompoMe::String interface_key) {
  auto l_res = this->map_dest_compo_inter_require.find(
      std::make_tuple(dest_key, component_key, interface_key));
  return l_res != this->map_dest_compo_inter_require.end();
}

bool DCI_map_out::is_connected_require(CompoMe::Require_helper &p_r) {
  for (auto it = this->map_dest_compo_inter_require.begin();
       it != this->map_dest_compo_inter_require.end(); it++) {
    if (it->second == &p_r) {
      return true;
    }
  }
  return false;
}

bool DCI_map_out::disconnect_require(CompoMe::String dest_key,
                                     CompoMe::String component_key,
                                     CompoMe::String interface_key) {
  auto l_element = this->map_dest_compo_inter_require.find(
      std::make_tuple(dest_key, component_key, interface_key));
  if (l_element == this->map_dest_compo_inter_require.end()) {
    return false;
  }

  this->map_dest_compo_inter_require.erase(l_element);
  return true;
}

bool DCI_map_out::disconnect_require(CompoMe::Require_helper &p_r) {
  for (auto it = this->map_dest_compo_inter_require.begin();
       it != this->map_dest_compo_inter_require.end(); it++) {
    if (it->second == &p_r) {
      this->map_dest_compo_inter_require.erase(it);
      return true;
    }
  }
  return false;
}

CompoMe::Require_helper &
DCI_map_out::get_require(CompoMe::String dest_key,
                         CompoMe::String component_key,
                         CompoMe::String interface_key) {
  return *this->map_dest_compo_inter_require[std::make_tuple(
      dest_key, component_key, interface_key)];
}

std::map<std::tuple<CompoMe::String, CompoMe::String, CompoMe::String>,
         CompoMe::Require_helper *>
DCI_map_out::get_require_list() {
  return this->map_dest_compo_inter_require;
}

} // namespace Core

} // namespace CompoMe
