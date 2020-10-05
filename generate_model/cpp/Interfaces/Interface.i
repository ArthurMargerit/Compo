%module Interface
%{
#include "Interfaces/Interface.hpp"
#include "Interfaces/Fake_stream.hpp"
#include "Interfaces/Caller_stream.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"
%}

%include "Serialization_context.i"

%include "Interfaces/Interface.hpp"
%include "Interfaces/Fake_stream.hpp"
%include "Interfaces/Caller_stream.hpp"

%include "Interfaces/Function_stream_recv.hpp"
%include "Interfaces/Function_stream_send.hpp"
%include "Interfaces/Return_stream_recv.hpp"
%include "Interfaces/Return_stream_send.hpp"
