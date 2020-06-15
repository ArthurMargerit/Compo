#include "Data/file.hpp"

#include "Data/Range_fac.hpp"




void init_file() {

  static bool already_run=false;
  if(already_run) {
    return;
  }
  already_run = true;

  

  
  Range_fac::get_inst();

  

  

}