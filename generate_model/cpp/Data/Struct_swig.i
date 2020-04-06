/* {{NAME}}.i */
%include <std_string.i>
%rename(stream_me_in) operator >>;
%rename(stream_out) operator <<(std::ostream &,{{NAME}} const &);
%rename(stream_pointer_out) operator <<(std::ostream &,{{NAME}} const *);
%rename(__str__) to_string;
 

%module Struct_{{NAME}}
%{
#include "Data/{{NAMESPACE.replace('::','/')}}/Struct_{{NAME}}.hpp"
%}


{%if PARENT%}
%include "Data/{{PARENT.NAME}}.i"
{%else%}
%include "Data/Struct.i"
{%endif%}

%include "Data/{{NAMESPACE.replace('::','/')}}/Struct_{{NAME}}.hpp"
