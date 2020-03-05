/* {{NAME}}.i */

%include <std_string.i>
%feature("python:slot", "tp_str", functype="reprfunc") {{NAME}}::to_string;

%rename(steam_me_in) operator>>;
%rename(__str__) to_string;
%rename(stream_me_out) operator<<;

%module Struct_{{NAME}}
%{
#include "Data/Struct.hpp"
#include "Data/Struct_{{NAME}}.hpp"
#include "Serialization_context.hpp"
%}

%include "Data/Struct_{{NAME}}.hpp"
