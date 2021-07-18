#include "Ports/CompoMe/Core/c_in.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Core {

//! Default constructor
c_in::c_in() : a_interface(nullptr) {}

//! Destructor
c_in::~c_in() {}

// Function IN ////////////////////////////////////////////////////////////////
bool c_in::connect_interface(CompoMe::Interface &p_i) {
  C_INFO("Interface Connected");
  this->a_interface = &p_i;
  return true;
}

bool c_in::is_connected_interface() { return this->a_interface != nullptr; }

bool c_in::is_connected_interface(CompoMe::Interface &p_i) {
  return &p_i == this->a_interface;
}

bool c_in::disconnect_interface() {
  this->a_interface = nullptr;
  return true;
}

bool c_in::disconnect_interface(CompoMe::Interface &p_i) {
  return this->is_connected_interface(p_i) && this->disconnect_interface();
}

CompoMe::Interface &c_in::get_interface() { return *this->a_interface; }

} // namespace Core

} // namespace CompoMe
