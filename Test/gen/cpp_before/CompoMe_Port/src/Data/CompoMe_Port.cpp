#include "Data/CompoMe_Port.hpp"

void init_CompoMe_Port() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe();
}