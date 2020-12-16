#include "Data/esp32.hpp"

#include "Structs/S1_fac.hpp"

void init_esp32() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe();

  S1_fac::get_inst();
}