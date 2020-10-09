%rename(steam_me_in) operator >>;
%rename(stream_me_out) operator<<;

%rename(__str__) to_string;

%include "exception.i"


%module Errors
%{
#include "Errors/Error.hpp"
%}

%include "Serialization_context.i"
%include "Errors/Error.hpp"

