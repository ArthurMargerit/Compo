#include "Data/file.hpp"

#include "Data/S1_fac.hpp"
#include "Data/S2_fac.hpp"




void init_file() {

  static bool already_run=false;
  if(already_run) {
    return;
  }
  already_run = true;

  

  
  S1_fac::get_inst();
  S2_fac::get_inst();

  

  

}