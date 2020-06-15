#include "Data/file.hpp"



#include "Components/Car/Gates/controller_fac.hpp"


void init_file() {

  static bool already_run=false;
  if(already_run) {
    return;
  }
  already_run = true;

  

  

  

  
  Car::Gates::controller_fac::get_inst();

}