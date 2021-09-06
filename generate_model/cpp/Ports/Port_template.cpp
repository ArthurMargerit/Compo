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

{% if KEY %}

CompoMe::Interface& {{NAME}}::get_interface({%for k in KEY %}{{k.TYPE.D_NAME}} {{k.NAME}} {%if not loop.last%},{%endif%}{%endfor%}) {  
  return *this->interfaces_list[std::make_tuple({%for k in KEY %} {{k.NAME}} {%if not loop.last%},{%endif%}{%endfor%})];
}

std::map<std::tuple<{%for k in KEY %}{{k.TYPE.D_NAME}}{%if not loop.last%},{%endif%}{%endfor%}>,CompoMe::Interface*>&
{{NAME}}::get_interfaces_list() {
  return  this->interfaces_list;
}
{% else %}

CompoMe::Interface& {{NAME}}::get_interface() {
  return *this->inter;
}
{% endif %}

{% endif %}

{%if "FUNCTION_OUT" in KIND %}
// Function OUT ////////////////////////////////////////////////////////////////
bool {{NAME}}::connect_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}, {%endfor%}CompoMe::Require_helper& p_r) {
  return false;
}

bool {{NAME}}::is_connected_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%}){
  return false;
}

bool {{NAME}}::is_connected_require(CompoMe::Require_helper& p_r){
  return false;
}

bool {{NAME}}::disconnect_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%}){
  return false;
}

bool {{NAME}}::disconnect_require(CompoMe::Require_helper& p_r){
  return false;
}

{% if KEY %}

std::map<std::tuple<{%for k in KEY %}{{k.TYPE.D_NAME}}{%if not loop.last%},{%endif%}{%endfor%}>,CompoMe::Require_helper*>&
{{NAME}}::get_require_list() {
  return this->requires_list;
}

CompoMe::Require_helper& {{NAME}}::get_require({%for k in KEY %}{{k.TYPE.D_NAME}} {{k.NAME}} {%if not loop.last%},{%endif%}{%endfor%}) {
  return *this->requires_list[std::make_tuple({%for k in KEY %} {{k.NAME}} {%if not loop.last%},{%endif%}{%endfor%})];
}
{% else %}

CompoMe::Require_helper& {{NAME}}::get_require() {
  return *this->req;;
}
{% endif %}

{% endif %}

{% include "helper/namespace_close.hpp" with context %}
