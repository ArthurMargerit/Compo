#include "Ports/CompoMe/Core/in.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Core {

//! Default constructor
in::in() : a_interface(nullptr) {}

//! Destructor
in::~in() {}

// Function IN ////////////////////////////////////////////////////////////////
bool in::connect_interface(CompoMe::Interface &p_i) {
  C_INFO("Interface Connected");
  this->a_interface = &p_i;
  return true;
}

bool in::is_connected_interface() { return this->a_interface != nullptr; }

bool in::is_connected_interface(CompoMe::Interface &p_i) {
  return &p_i == this->a_interface;
}

bool in::disconnect_interface() {
  this->a_interface = nullptr;
  return true;
}

bool in::disconnect_interface(CompoMe::Interface &p_i) {
  return this->is_connected_interface(p_i) && this->disconnect_interface();
}

CompoMe::Interface &in::get_interface() { return *this->a_interface; }

} // namespace Core

} // namespace CompoMe
