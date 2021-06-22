#include "Ports/CompoMe/Stream/map_out.hpp"
#include "CompoMe/Log.hpp"
#include "Links/Link.hpp"

namespace CompoMe {

namespace Stream {

//! Default constructor
map_out::map_out() {}

//! Destructor
map_out::~map_out() {}

// Function OUT ////////////////////////////////////////////////////////////////
bool map_out::connect_require(CompoMe::String interface_key,
                              CompoMe::Require_helper &p_r) {
  C_INFO_TAG("port,stream,require",
             "Connection at interface_key :", interface_key);

  if (&this->get_link() != nullptr) {
    this->get_link().one_connect(p_r, interface_key);
  }

  return CompoMe::Core::map_out::connect_require(interface_key, p_r);
}

bool map_out::is_connected_require(CompoMe::String interface_key) {
  return CompoMe::Core::map_out::is_connected_require(interface_key);
}

bool map_out::is_connected_require(CompoMe::Require_helper &p_r) {
  return CompoMe::Core::map_out::is_connected_require(p_r);
}

bool map_out::disconnect_require(CompoMe::String interface_key) {
  C_INFO_TAG("port,stream,require", "Disconnection at interface_key ",
             interface_key);
  return CompoMe::Core::map_out::disconnect_require(interface_key);
}

bool map_out::disconnect_require(CompoMe::Require_helper &p_r) {
  C_INFO_TAG("port,stream,require", "Disconnection of a interface");
  return CompoMe::Core::map_out::disconnect_require(p_r);
}

CompoMe::Require_helper &map_out::get_require(CompoMe::String interface_key) {
  C_INFO_TAG("port,stream,require", "Get of a interface ", interface_key);
  return CompoMe::Core::map_out::get_require(interface_key);
}

const std::map<std::tuple<CompoMe::String>, CompoMe::Require_helper *> &
map_out::get_require_list() {
  return CompoMe::Core::map_out::get_require_list();
}

} // namespace Stream

} // namespace CompoMe
