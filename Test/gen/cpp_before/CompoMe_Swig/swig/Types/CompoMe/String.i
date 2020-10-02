%include "std_string.i"

%module String
%{
#include "Types/CompoMe/String.hpp"
#include "Types/CompoMe/String_d.hpp"
%}

%include "Types/CompoMe/String_d.hpp"
%include "Types/CompoMe/String.hpp"
