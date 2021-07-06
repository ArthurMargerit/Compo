/* /\* {{NAME}}.i *\/ */

%module {{NAME}};
%include <std_string.i>
%rename(stream_me_in) operator >>;
%rename(stream_out) operator <<(std::ostream &,{{D_NAME}} const &);
%rename(stream_pointer_out) operator <<(std::ostream &,{{D_NAME}} const *);

{%if PARENT%}
%include "Components/{{PARENT.F_NAME}}.i"
{%else%}
%include "Components/Component.i"
{%endif%}

{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
%include "Structs/{{d.F_NAME}}.i"
{% endfor %}

{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, DATA).values() %}
{%if not d.NATIF %}
%include "Types/{{d.F_NAME}}.i"
{%endif%}
{% endfor %}

%module {{NAME}}
%{
  {% for a in REQUIRE %}
#include "Interfaces/{{a.INTERFACE.F_NAME}}/{{a.INTERFACE.NAME}}.hpp"
  {%endfor%}

  {% for a in PROVIDE %}
#include "Components/{{F_NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
  {%endfor%}

#include "Components/{{F_NAME}}.hpp"
%}

{% for a in REQUIRE %}
%template(ri_{{a.INTERFACE.NAME}}) CompoMe::Require_helper_t<{{a.INTERFACE.NAME}}>;
{%endfor%}

{% for a in PROVIDE %}
%include "Interfaces/{{a.INTERFACE.F_NAME}}.i"
%include "Components/{{F_NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
{%endfor%}

%include "Components/{{F_NAME}}.hpp"
