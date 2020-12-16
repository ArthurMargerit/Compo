#include "Data/file.hpp"

#include "Structs/S1_fac.hpp"
#include "Structs/S2_fac.hpp"

void init_file() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe();
  init_CompoMe_Dbus();

  S1_fac::get_inst();
  S2_fac::get_inst();
}