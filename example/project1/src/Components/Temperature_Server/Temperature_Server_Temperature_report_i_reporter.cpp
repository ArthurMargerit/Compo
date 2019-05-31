
#include "Components/Temperature_Server/Temperature_Server_Temperature_report_i_reporter.hpp"
#include "Components/Temperature_Server/Temperature_Server.hpp"

namespace Temperature_Server {

Temperature_report_i_reporter::Temperature_report_i_reporter(
    Temperature_Server *comp)
    : composant(comp) {
  return;
}

//! Destructor
Temperature_report_i_reporter::~Temperature_report_i_reporter() noexcept {
  return;
}

// //! Move assignment operator
// reporter& reporter::operator=(reporter &&other) noexcept
//                       {

//                       }
void Temperature_report_i_reporter::notify(Temperature_sample ts) { return; }

}; // namespace Temperature_Server
