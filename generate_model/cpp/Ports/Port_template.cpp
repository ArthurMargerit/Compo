#include "Ports/{{F_NAME}}.hpp"

{% include "helper/namespace_open.hpp" with context %}

//! Default constructor
{{NAME}}::{{NAME}}() {}

//! Destructor
{{NAME}}::~{{NAME}}() {}

{%if "FUNCTION_IN" in KIND %}
// Function IN ////////////////////////////////////////////////////////////////
bool {{NAME}}::connect_interface({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}, {%endfor%}CompoMe::Interface& p_i){
  return false;
}

bool {{NAME}}::is_connected_interface({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%}){
  return false;
}

bool {{NAME}}::is_connected_interface(CompoMe::Interface& p_i){
  return false;
}

bool {{NAME}}::disconnect_interface({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%}){
  return false;
}

bool {{NAME}}::disconnect_interface(CompoMe::Interface& p_i){
  return false;
}
{% endif %}

{%if "FUNCTION_OUT" in KIND %}
// Function OUT ////////////////////////////////////////////////////////////////
bool {{NAME}}::connect_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}, {%endfor%}CompoMe::Require_helper& p_r) {
  return false;
}

bool {{NAME}}::is_connected_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%}){
  return false;
}

bool {{NAME}}::is_connected_require(CompoMe::Require_helper& p_i){
  return false;
}

bool {{NAME}}::disconnect_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%}){
  return false;
}

bool {{NAME}}::disconnect_require(CompoMe::Require_helper& p_r){
  return false;
}
{% endif %}

{% include "helper/namespace_close.hpp" with context %}
