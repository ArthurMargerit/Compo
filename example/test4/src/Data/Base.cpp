#include "Data/Base.hpp"

#include "Data/Struct_fac_dt.hpp"
#include "Data/Struct_fac_dT0.hpp"

void init_Base() {
  

  
  dt_fac::get_inst();
  dT0_fac::get_inst();

}