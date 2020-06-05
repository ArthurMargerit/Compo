%rename(steam_me_in) operator >>;
%rename(stream_me_out) operator<<;

%rename(__str__) to_string;

%module Struct
%{
#include "Data//Struct.hpp"
%}

%include "Serialization_context.i"

%include "Data//Struct.hpp"
