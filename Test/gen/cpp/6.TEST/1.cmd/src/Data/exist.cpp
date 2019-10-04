#include "Data/exist.hpp"




void init_exist() {

  static bool already_run=false;
  if(already_run) {
    return;
  }
  already_run = true;

  init_code();
  

  

  

}