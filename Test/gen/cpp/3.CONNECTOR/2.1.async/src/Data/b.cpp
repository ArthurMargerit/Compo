#include "Data/b.hpp"

#include "Components/C2_fac.hpp"

void init_b() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_code();

  C2_fac::get_inst();
}