/* /\* HttpV2_server_in.i *\/ */

%module HttpV2_server_in;
%include <std_string.i>

%include "Interfaces/Interface.i"


%include "Links/Link.i"






%include "Types/CompoMe/String.i"



%include "Types/i32.i"



%include "Types/ui32.i"




%module HttpV2_server_in
%{
#include "Links/CompoMe/Posix/HttpV2_server_in/HttpV2_server_in.hpp"
%}

%include "Links/CompoMe/Posix/HttpV2_server_in/HttpV2_server_in.hpp"