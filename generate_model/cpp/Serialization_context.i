%rename(steam_me_in) operator >>;
%rename(stream_me_out) operator<<;

%rename(__str__) to_string;

%module Serialization_context
%{
    #include "Serialization_context.hpp"
%}

%include "Serialization_context.hpp"
