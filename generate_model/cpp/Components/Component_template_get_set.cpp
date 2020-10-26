#include "Components/{{F_NAME}}.hpp"

{% include "helper/namespace_open.hpp" with context %}
  /////////////////////////////////////////////////////////////////////////////
  //                                   PROVIDE                               //
  /////////////////////////////////////////////////////////////////////////////
  {% for pro in PROVIDE %}
  {{NAME}}_{{ pro.INTERFACE.NAME }}_{{pro.NAME}}&  {{NAME}}::get_{{ pro.NAME }}() {
    return this->{{ pro.NAME }};
  }
  {% endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                                   DATA                                  //
  /////////////////////////////////////////////////////////////////////////////
  {% for v in DATA %}
  // {{v.NAME}}
  {{v.TYPE.D_NAME}} {{NAME}}::get_{{v.NAME}}() const {
    return this->{{v.NAME}};
  }

  void  {{NAME}}::set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}}) {
    this->{{v.NAME}} = {{v.NAME}};
  }
  {% endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                            SUB COMPONENT                                //
  /////////////////////////////////////////////////////////////////////////////
  {% for sc in COMPONENT_INSTANCE %}
  {{sc.COMPONENT.D_NAME}}& {{NAME}}::get_sc_{{ sc.NAME }}() {
    return this->{{ sc.NAME }};
  }
  {% endfor %}

  {% for sc in CONNECTOR_INSTANCE %}
  {{sc.CONNECTOR.NAME}}
  & {{NAME}}::get_sc_{{ sc.NAME }}() {
    return this->{{ sc.NAME }};
  }
  {% endfor %}

{% include "helper/namespace_close.hpp" with context %}
