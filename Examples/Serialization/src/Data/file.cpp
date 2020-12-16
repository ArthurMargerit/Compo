#include "Data/file.hpp"

#include "Structs/File_fac.hpp"
#include "Structs/User_fac.hpp"

void init_file() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe();

  File_fac::get_inst();
  User_fac::get_inst();
}