/* /\* Calc_I.i *\/ */

%module Calc_I;
%include <std_string.i>


%include "Interfaces/Interface.i"



%module Calc_I
%{
#include "Interfaces/Calc_I/Calc_I.hpp"
#include "Interfaces/Calc_I/Calc_I_caller_stream.hpp"
#include "Interfaces/Calc_I/Calc_I_fake_stream.hpp"
%}







%include "Interfaces/Calc_I/Calc_I.hpp"
%include "Interfaces/Calc_I/Calc_I_fake_stream.hpp"
%include "Interfaces/Calc_I/Calc_I_caller_stream.hpp"

%include "Components/Require_helper.i"
%template(require_Calc_I) CompoMe::Require_helper_t<Calc_I>;