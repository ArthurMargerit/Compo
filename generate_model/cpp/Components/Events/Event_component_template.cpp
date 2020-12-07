#include "Components/{{COMPONENT.F_NAME}}_{{BUS.NAME}}_{{NAME}}.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}
//! Default constructor
    {{COMPONENT.NAME}}_{{BUS.NAME}}_{{NAME}}::{{COMPONENT.NAME}}_{{BUS.NAME}}_{{NAME}}({{COMPONENT.NAME}}* p_comp):a_c(p_comp){

                                                                                                  }

    {{COMPONENT.NAME}}_{{BUS.NAME}}_{{NAME}}::~{{COMPONENT.NAME}}_{{BUS.NAME}}_{{NAME}}() noexcept{

                                                                                                   }


    {{COMPONENT.NAME}}& {{COMPONENT.NAME}}_{{BUS.NAME}}_{{NAME}}::get_c() const {
      return *this->a_c;}

{% include "helper/namespace_close.hpp" with context %}
