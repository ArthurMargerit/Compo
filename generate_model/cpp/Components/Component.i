%module Component;

%rename(steam_me_in) operator >>;
%rename(stream_me_out) operator<<;

%include "Interfaces/Interface.i"
%include "Components/Require_helper.i"

%module Component
%{
#include "Components/Component.hpp"
%}

%include "Serialization_context.i"
%include "Components/Component.hpp"
