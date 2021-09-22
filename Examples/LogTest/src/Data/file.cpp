#include "Data/file.hpp"

void init_file() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe_Udp();
  init_CompoMe_Json();
  init_CompoMe_Log();
  init_CompoMe();
}