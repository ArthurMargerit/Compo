#include "Ports/CompoMe/Core/c_out.hpp"

namespace CompoMe {

namespace Core {

//! Default constructor
c_out::c_out() : a_re(nullptr) {}

//! Destructor
c_out::~c_out() {}

// Function OUT ////////////////////////////////////////////////////////////////
bool c_out::connect_require(CompoMe::Require_helper &p_r) {
  this->a_re = &p_r;
  return true;
}

bool c_out::is_connected_require() { return this->a_re != nullptr; }

bool c_out::is_connected_require(CompoMe::Require_helper &p_i) {
  return this->a_re == &p_i;
}

bool c_out::disconnect_require() {
  this->a_re = nullptr;
  return true;
}

bool c_out::disconnect_require(CompoMe::Require_helper &p_r) {
  return is_connected_require(p_r) && disconnect_require();
}

CompoMe::Require_helper &c_out::get_require() { return *this->a_re; }

} // namespace Core

} // namespace CompoMe
