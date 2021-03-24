/* /\* Server.i *\/ */

%module Server;
%include <std_string.i>

%include "Interfaces/Interface.i"


%include "Links/Link.i"






%include "Types/CompoMe/String.i"



%include "Types/i32.i"






%module Server
%{
#include "Links/CompoMe/WebSocket/Server/Server.hpp"
%}

%include "Links/CompoMe/WebSocket/Server/Server.hpp"