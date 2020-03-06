/* {{NAME}}.i */
%include <std_string.i>

%rename(steam_me_in) operator>>;
%rename(stream_me_out) operator<<;
%rename(__str__) to_string;

%module Struct_{{NAME}}
%{
#include "Data/Struct.hpp"
#include "Data/Struct_{{NAME}}.hpp"
%}

%include "Data/Struct_{{NAME}}.hpp"
