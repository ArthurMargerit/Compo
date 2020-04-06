/* {{NAME}}.i */
%rename(steam_me_in) operator>>;
%rename(stream_me_out) operator<<;

%module {{NAME}}
%{
#include "Components/Component.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Caller.hpp"

#include "Components/{{NAME}}/{{NAME}}.hpp"

  {% for a in PROVIDE %}
#include "Components/{{NAME}}/{{NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
#include "Interfaces/{{a.INTERFACE.D_NAME.replace('::','/')}}/{{a.INTERFACE.NAME}}.hpp"
  {%endfor%}

{% for a in REQUIRE %}
#include "Interfaces/{{a.INTERFACE.D_NAME.replace('::','/')}}/{{a.INTERFACE.NAME}}_fake.hpp"
#include "Interfaces/{{a.INTERFACE.D_NAME.replace('::','/')}}/{{a.INTERFACE.NAME}}.hpp"
{%endfor%}

%}


{% for a in PROVIDE %}
%include "Components/{{NAME}}/{{NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
{%endfor%}

%include "Components/{{NAME}}/{{NAME}}.hpp"

