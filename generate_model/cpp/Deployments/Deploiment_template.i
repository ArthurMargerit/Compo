%module {{NAME}};
%include <std_string.i>

{%if PARENT%}
#include "Deployments/{{PARENT.D_NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
%include "Deployments/Deployment.i"
{%endif%}

{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, DATA).values() %}
{%if not d.NATIF %}
%include "Types/{{d.F_NAME}}.i"
{%endif%}
{% endfor %}
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
%include "Structs/{{d.F_NAME}}.i"
{% endfor %}
{%for inst in COMPONENT_INSTANCE %}
%include "Components/{{inst.COMPONENT.F_NAME}}.i"
{%endfor%}
{% for i_link in LINK_INSTANCE %}
%include "Links/{{i_link.TYPE.F_NAME}}/{{i_link.TYPE.NAME}}.i"
{% endfor %}


%module {{NAME}}
%{
#include "Deployments/{{D_NAME}}/{{NAME}}.hpp"
%}

%include "Deployments/{{D_NAME}}/{{NAME}}.hpp"
