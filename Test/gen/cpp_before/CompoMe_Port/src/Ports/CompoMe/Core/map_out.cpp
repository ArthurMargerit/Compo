#include "Ports/CompoMe/Core/map_out.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Core {

//! Default constructor
map_out::map_out() : map_require() {}

//! Destructor
map_out::~map_out() {}

// Function OUT ////////////////////////////////////////////////////////////////
bool map_out::connect_require(CompoMe::String interface_key,
                              CompoMe::Require_helper &p_r) {
  if (this->is_connected_require(interface_key)) {
    C_WARNING_TAG("port", "A Interface is already connected to ",
                  interface_key);
  }

  this->map_require[std::make_tuple(interface_key)] = &p_r;
  return true;
}

bool map_out::is_connected_require(CompoMe::String interface_key) {
  auto l_res = this->map_require.find(std::make_tuple(interface_key));
  return l_res != this->map_require.end();
}

bool map_out::is_connected_require(CompoMe::Require_helper &p_r) {
  for (auto it = this->map_require.begin(); it != this->map_require.end();
       it++) {
    if (it->second == &p_r) {
      return true;
    }
  }
  return false;
}

bool map_out::disconnect_require(CompoMe::String interface_key) {
  auto l_element = this->map_require.find(std::make_tuple(interface_key));
  if (l_element == this->map_require.end()) {
    return false;
  }

  this->map_require.erase(l_element);
  return true;
}

bool map_out::disconnect_require(CompoMe::Require_helper &p_r) {
  for (auto it = this->map_require.begin(); it != this->map_require.end();
       it++) {
    if (it->second == &p_r) {
      this->map_require.erase(it);
      return true;
    }
  }
  return false;
}

CompoMe::Require_helper &map_out::get_require(CompoMe::String interface_key) {
  return *this->map_require[std::make_tuple(interface_key)];
}

const std::map<std::tuple<CompoMe::String>, CompoMe::Require_helper *> &
map_out::get_require_list() {
  return this->map_require;
}

} // namespace Core

} // namespace CompoMe
