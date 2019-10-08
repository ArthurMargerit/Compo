/* {{NAME}}.i */

%rename(steam_me_in) operator>>;
%rename(stream_me_out) operator<<;

%module {{NAME}}
%{
#include "Components/Component.hpp"
#include "Components/{{NAME}}/{{NAME}}.hpp"
  {% for a in PROVIDE %}
#include "Components/{{NAME}}/{{NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
  {%endfor%}
  {{"%}"}}

  {% for a in PROVIDE %}
%include "Components/{{NAME}}/{{NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
  {%endfor%}
%include "Components/{{NAME}}/{{NAME}}.hpp"

