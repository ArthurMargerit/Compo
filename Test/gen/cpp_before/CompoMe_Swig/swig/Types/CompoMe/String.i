%include "std_string.i"
%rename(__str__)  operator const std::string&;

%module String
%{
#include "Types/CompoMe/String.hpp"
#include "Types/CompoMe/String_d.hpp"
%}

%include "Types/CompoMe/String_d.hpp"
%include "Types/CompoMe/String.hpp"
