#include "Data/file.hpp"

#include "Data/File_fac.hpp"
#include "Data/User_fac.hpp"




void init_file() {

  static bool already_run=false;
  if(already_run) {
    return;
  }
  already_run = true;

  

  
  File_fac::get_inst();
  User_fac::get_inst();

  

  

}