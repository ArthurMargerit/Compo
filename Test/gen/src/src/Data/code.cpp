#include "Data/code.hpp"

#include "Structs/S/S2_fac.hpp"
#include "Structs/S1_fac.hpp"

#include "Components/C/C1_fac.hpp"
#include <cstdio>

void init_code() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe_Test();
  init_CompoMe();

  S1_fac::get_inst();
  S::S2_fac::get_inst();

  C::C1_fac::get_inst();
}