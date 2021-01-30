%module {{NAME}};

%rename(stream_out) operator <<;
%rename(stream_in) operator >>;

%module {{NAME}}
%{
#include "Types/{{F_NAME}}.hpp"
%}


%include "Types/{{F_NAME}}.hpp"
