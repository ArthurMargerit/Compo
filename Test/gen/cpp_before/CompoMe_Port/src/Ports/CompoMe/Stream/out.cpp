#include "Ports/CompoMe/Stream/out.hpp"
#include "Links/Link.hpp"

namespace CompoMe {

namespace Stream {

//! Default constructor
out::out() : CompoMe::Core::c_out() {}

//! Destructor
out::~out() {}

// Function OUT ////////////////////////////////////////////////////////////////
bool out::connect_require(CompoMe::Require_helper &p_r) {
  if (&this->get_link() != nullptr) {
    this->get_link().one_connect(p_r, CompoMe::String(""));
  }

  return CompoMe::Core::c_out::connect_require(p_r);
}

bool out::is_connected_require() {
  return CompoMe::Core::c_out::is_connected_require();
}

bool out::is_connected_require(CompoMe::Require_helper &p_r) {
  return CompoMe::Core::c_out::is_connected_require(p_r);
}

bool out::disconnect_require() {
  if (&this->get_link() != nullptr) {
    this->get_link().one_disconnect(this->get_require(), CompoMe::String(""));
  }

  return CompoMe::Core::c_out::disconnect_require();
}

bool out::disconnect_require(CompoMe::Require_helper &p_r) {

  if (&this->get_link() != nullptr) {
    this->get_link().one_disconnect(p_r, CompoMe::String(""));
  }

  return CompoMe::Core::c_out::disconnect_require(p_r);
}

CompoMe::Require_helper &out::get_require() {
  return CompoMe::Core::c_out::get_require();
}

} // namespace Stream

} // namespace CompoMe
