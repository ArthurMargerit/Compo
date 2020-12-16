#include "Data/CompoMe_esp32.hpp"

#include "Events/Embded/IO/Pin_change_fac.hpp"

#include "Components/Embded/IO/esp32/Control_input_fac.hpp"
#include "Components/Embded/IO/esp32/Control_output_fac.hpp"

void init_CompoMe_esp32() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe();

  Embded::IO::Pin_change_fac::get_inst();

  Embded::IO::esp32::Control_output_fac::get_inst();
  Embded::IO::esp32::Control_input_fac::get_inst();
}