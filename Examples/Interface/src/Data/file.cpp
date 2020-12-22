#include "Data/file.hpp"

#include "Structs/Range_fac.hpp"

void init_file() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe();
  init_CompoMe_Tools();

  Range_fac::get_inst();
}