#include "Data/code.hpp"



#include "Components/C_p_fac.hpp"
#include "Components/C_r_fac.hpp"


void init_code() {

  static bool already_run=false;
  if(already_run) {
    return;
  }
  already_run = true;

  

  

  

  
  C_p_fac::get_inst();
  C_r_fac::get_inst();

}