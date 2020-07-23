/* /\* {{NAME}}.i *\/ */

%module {{NAME}};
%include <std_string.i>

{%if PARENT%}
%include "Components/{{F_NAME}}.i"
{%else%}
%include "Components/Component.i"
{%endif%}

/* namespace {{NAME}} { */
/*    %rename(steam_me_in) operator >>(std::istream &,{{NAME}} &); */
/*    %rename(stream_me_in_p) operator >>(std::istream &,{{NAME}}*&); */
/*    %rename(stream_me_out) operator <<(std::ostream &,{{NAME}} const &); */
/*    %rename(stream_me_out_p) operator <<(std::ostream &,{{NAME}} const *); */
/* } */


%module {{NAME}}
%{
  {% for a in PROVIDE %}
#include "Interfaces/{{a.INTERFACE.NAME}}/{{a.INTERFACE.NAME}}.hpp"
  {%endfor%}
  {% for a in REQUIRE %}
#include "Interfaces/{{a.INTERFACE.NAME}}/{{a.INTERFACE.NAME}}.hpp"
  {%endfor%}

  {% for a in PROVIDE %}
#include "Components/{{F_NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
  {%endfor%}

#include "Components/{{F_NAME}}.hpp"
%}

%include "Interfaces/Interface.hpp"

{% for a in PROVIDE %}
%include "Components/{{F_NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
{%endfor%}

%include "Components/{{F_NAME}}.hpp"
