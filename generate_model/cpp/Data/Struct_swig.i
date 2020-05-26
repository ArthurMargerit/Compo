/* {{NAME}}.i */
%include <std_string.i>
%rename(stream_me_in) operator >>;

%rename(stream_out) operator <<(std::ostream &,{{NAME}} const &);
%rename(stream_pointer_out) operator <<(std::ostream &,{{NAME}} const *);

%rename(__str__) to_string;

%module {{NAME}}
%{
#include "Data/{{D_NAME.replace('::','/')}}.hpp"
%}

{% if PARENT %}
%include "Data/{{PARENT.D_NAME.replace('::','/')}}.i"
{% else %}
%include "Data/Struct.i"
{% endif %}

%include "Data/{{D_NAME.replace('::','/')}}.hpp"
