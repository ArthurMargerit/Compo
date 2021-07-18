#include "Ports/CompoMe/Stream/in.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Stream {

//! Default constructor
in::in() {}

//! Destructor
in::~in() {}

// Function IN ////////////////////////////////////////////////////////////////
bool in::connect_interface(CompoMe::Interface &p_i) {
  if (p_i.get_caller_stream() == nullptr) {
    C_WARNING_TAG("port,stream",
                  "CallerStream is not available for this interface");
    return false;
  }

  return CompoMe::Core::c_in::connect_interface(p_i);
}

bool in::is_connected_interface() {
  return CompoMe::Core::c_in::is_connected_interface();
}

bool in::is_connected_interface(CompoMe::Interface &p_i) {
  return CompoMe::Core::c_in::is_connected_interface(p_i);
}

bool in::disconnect_interface() {
  return CompoMe::Core::c_in::disconnect_interface();
}

bool in::disconnect_interface(CompoMe::Interface &p_i) {
  return CompoMe::Core::c_in::disconnect_interface(p_i);
}

CompoMe::Interface &in::get_interface() {
  return CompoMe::Core::c_in::get_interface();
}

} // namespace Stream

} // namespace CompoMe
