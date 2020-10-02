/* /\* I1_1.i *\/ */

%module I1_i;
%include <std_string.i>

%include "Interfaces/I1.i"

%module I1_i
%{
#include "I1_i.hpp"
%}

%include "I1_i.hpp"
