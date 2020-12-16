/* /\* Compute.i *\/ */

%module Compute;
%include <std_string.i>


%include "Components/Component.i"






%module Compute
%{
  

  
#include "Components/Compute_Calc_I_compute.hpp"
  

#include "Components/Compute.hpp"
%}




%include "Interfaces/Calc_I.i"
%include "Components/Compute_Calc_I_compute.hpp"


%include "Components/Compute.hpp"