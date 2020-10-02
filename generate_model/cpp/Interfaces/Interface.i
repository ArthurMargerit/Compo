%module Interface
%{
#include "Interfaces/Interface.hpp"
#include "Interfaces/Fake_stream.hpp"
#include "Interfaces/Caller_stream.hpp"
%}

%include "Serialization_context.i"

%include "Interfaces/Interface.hpp"
%include "Interfaces/Fake_stream.hpp"
%include "Interfaces/Caller_stream.hpp"
