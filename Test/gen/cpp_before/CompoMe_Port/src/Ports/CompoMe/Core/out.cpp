#include "Ports/CompoMe/Core/out.hpp"

namespace CompoMe {

namespace Core {

//! Default constructor
out::out() : a_re(nullptr) {}

//! Destructor
out::~out() {}

// Function OUT ////////////////////////////////////////////////////////////////
bool out::connect_require(CompoMe::Require_helper &p_r) {
  this->a_re = &p_r;
  return true;
}

bool out::is_connected_require() { return this->a_re != nullptr; }

bool out::is_connected_require(CompoMe::Require_helper &p_i) {
  return this->a_re == &p_i;
}

bool out::disconnect_require() {
  this->a_re = nullptr;
  return true;
}

bool out::disconnect_require(CompoMe::Require_helper &p_r) {
  return is_connected_require(p_r) && disconnect_require();
}

CompoMe::Require_helper &out::get_require() { return *this->a_re; }

} // namespace Core

} // namespace CompoMe
