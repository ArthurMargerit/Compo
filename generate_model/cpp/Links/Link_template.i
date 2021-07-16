/* /\* {{NAME}}.i *\/ */

%module {{NAME}};
%include <std_string.i>

%include "Interfaces/Interface.i"

{%if PARENT%}
%include "Links/{{PARENT.F_NAME}}.i"
{%else%}
%include "Links/Link.i"
{%endif%}



{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, DATA).values() %}
{%if not d.NATIF %}
%include "Types/{{d.F_NAME}}.i"
{%endif%}
{% endfor %}

{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
%include "Structs/{{d.F_NAME}}.i"
{% endfor %}

{% for d in PORT %}
%include "Ports/{{d.TYPE.F_NAME}}.i"
{% endfor %}

%module {{NAME}}
%{
#include "Links/{{F_NAME}}/{{NAME}}.hpp"
%}

%include "Links/{{F_NAME}}/{{NAME}}.hpp"
