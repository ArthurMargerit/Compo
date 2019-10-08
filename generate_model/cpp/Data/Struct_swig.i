/* {{NAME}}.i */

%rename(steam_me_in) operator>>;
%rename(stream_me_out) operator<<;

%module Struct_{{NAME}}
%{
#include "Data/Struct_{{NAME}}.hpp"
%}

%include "Data/Struct.hpp"
%include "Data/Struct_{{NAME}}.hpp"
