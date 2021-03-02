#include "Data/file.hpp"

#include "Structs/Range_fac.hpp"

void init_file() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe_Tools();
  init_CompoMe();

  Range_fac::get_inst();
}