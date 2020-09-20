
#include "Components/{{F_NAME}}.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

{% include "helper/namespace_open.hpp" with context %}

  {{NAME}}::{{NAME}}()
                      {%- if PROVIDE.__len__() != 0  or REQUIRE.__len__() != 0 or DATA.__len__() !=0 or COMPONENT_INSTANCE.__len__() !=0 -%}
  :
  {%- endif -%}
  {%- if PROVIDE.__len__() %}/* PROVIDE */{% endif -%}
  {%- for provide in PROVIDE-%}
  {{provide.NAME}}(this){%- if not loop.last-%},{%- endif -%}
  {%- endfor -%}
  {%- if REQUIRE.__len__() != 0 and PROVIDE.__len__() !=0  -%},{%- endif -%}
  {%- if REQUIRE.__len__() %}/* REQUIRE */{%- endif -%}
  {%- for req in REQUIRE-%}
  {{req.NAME}}(NULL){%- if not loop.last-%},{%- endif -%}
  {%- endfor -%}

  {%- if DATA.__len__() != 0  and (PROVIDE.__len__() != 0  or REQUIRE.__len__() != 0) -%},{%- endif -%}
  {%- if DATA.__len__() %}/* DATA */{%- endif -%}
  {%- for value_data in DATA -%}
  {{value_data.NAME}}({%- with TYPE=value_data.TYPE, def=value_data.DEFAULT, STRUCTS=MAIN.STRUCTS-%}
                         {%- include "helper/lap.cpp" with context -%}
                         {%- endwith -%})
                         {%- if not loop.last -%},{%- endif -%}
  {%- endfor %}
  {%- if COMPONENT_INSTANCE.__len__() != 0  and
                        (DATA.__len__() != 0 or PROVIDE.__len__() != 0  or REQUIRE.__len__() != 0) -%},{%- endif -%}
  {%- if COMPONENT_INSTANCE.__len__() %}
  /* COMPONENT_INSTANCE */
  {%- endif -%}
  {%- for sc in COMPONENT_INSTANCE-%}
  {{sc.NAME}}(){%- if not loop.last-%},{%- endif -%}
  {%- endfor -%}
  {
    C_INFO_TAG("CONST: {{NAME}}","Component,{{NAME}}");
    return;
  }


  //! Destructor
  {{NAME}}::~{{NAME}}() noexcept {
      C_INFO_TAG("DEST: {{NAME}}", "Component,{{NAME}}");
      return;
  }


  /////////////////////////////////////////////////////////////////////////////
  //                           COMPONENT_FUNCTIONS                           //
  /////////////////////////////////////////////////////////////////////////////

  void {{NAME}}::configuration() {
    {%if PARENT -%}
    {{PARENT.D_NAME}}::{{PARENT.NAME}}::configuration();
    {%else-%}
    Component::configuration();
    {%endif-%}
    C_INFO_TAG("CONF: {{NAME}}", "Component,{{NAME}}");

    // configuration: sub_component
    {%-for sc in COMPONENT_INSTANCE%}
    {{sc.NAME}}.configuration();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::connection() {
    // connect: parent
    {%if PARENT -%}
    {{PARENT.D_NAME}}::{{PARENT.NAME}}::connection();
    {%else-%}
    Component::connection();
    {%endif-%}
    C_INFO_TAG("CONNECT: {{NAME}}", "Component,{{NAME}}");

    // connect: intern
    {% for co in CONNECTION %}
    {% if co.LINK == "SC_R_TO_SC_P" %}
    // {{co.FROM.INSTANCE.NAME}}.{{co.FROM.INTERFACE.NAME}} --> {{co.TO.INSTANCE.NAME}}.{{co.TO.INTERFACE.NAME}}
    {%if co.FROM.KIND == "set" %}
    this->get_sc_{{co.FROM.INSTANCE.NAME}}().{{co.FROM.INTERFACE.NAME}}.set(&(this->get_sc_{{co.TO.INSTANCE.NAME}}().get_{{co.TO.INTERFACE.NAME}}()));
    {%else%}
    this->get_sc_{{co.FROM.INSTANCE.NAME}}().{{co.FROM.INTERFACE.NAME}}.{{co.FROM.KIND}}(&(this->get_sc_{{co.TO.INSTANCE.NAME}}().get_{{co.TO.INTERFACE.NAME}}()));
    {%endif%}

    {%endif%}
    {% endfor %}

    // connect: sub component
    {%-for sc in COMPONENT_INSTANCE %}
    {{sc.NAME}}.connection();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::start() {
    // start: parent
    {%if PARENT -%}
    {{PARENT.D_NAME}}::{{PARENT.NAME}}::start();
    {%else-%}
    Component::start();
    {%endif-%}

    C_INFO_TAG("START: {{NAME}}", "Component,{{NAME}}");

    // start: sub component
    {%-for sc in COMPONENT_INSTANCE %}
    {{sc.NAME}}.start();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::step() {
    // step: parent
    {%if PARENT -%}
    {{PARENT.D_NAME}}::{{PARENT.NAME}}::step();
    {%else-%}
    Component::step();
    {%endif-%}
    C_INFO_TAG("STEP: {{NAME}}", "Component,{{NAME}}");

    // step: sub_component
    {%-for sc in COMPONENT_INSTANCE%}
    {{sc.NAME}}.step();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::stop() {
    // stop: parent
    {%if PARENT -%}
    {{PARENT.D_NAME}}::{{PARENT.NAME}}::stop();
    {%else-%}
    Component::stop();
    {%endif-%}

    // stop: sub_component
    C_INFO_TAG("STOP: {{NAME}}", "Component,{{NAME}}");
    {%-for sc in COMPONENT_INSTANCE-%}
    {{sc.NAME}}.stop();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::status() {
    // status: parent
    {%if PARENT -%}
    {{PARENT.D_NAME}}::{{PARENT.NAME}}::status();
    {%else-%}
    Component::status();
    {%endif-%}

    // status: sub_component
    C_INFO_TAG("STATUS: {{NAME}}", "Component,{{NAME}}");

    {%-for sc in COMPONENT_INSTANCE-%}
    {{sc.NAME}}.status();
    {%- endfor -%}
    return;
  }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTIONS                               //
  /////////////////////////////////////////////////////////////////////////////
  {% for f in FUNCTION %}
  {{f.RETURN.D_NAME}} {{NAME}}::{{f.NAME}}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME}}
    {%- if not loop.last%},{% endif -%}
    {%- endfor-%}
    ) {
     {% if "DEFAULT" in f.RETURN%}
     return {{f.RETURN.DEFAULT}};
     {% else %}
     return {{f.RETURN.D_NAME}}();
     {% endif %}
   }
  {% endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                                INTERFACES                               //
  /////////////////////////////////////////////////////////////////////////////

  // PROVIDE //////////////////////////////////////////////////////////////////
  {% for pro in PROVIDE %}
  {{NAME}}_{{ pro.INTERFACE.NAME }}_{{pro.NAME}}&  {{NAME}}::get_{{ pro.NAME }}() {
    return this->{{ pro.NAME }};
  }
  {% endfor %}

  // // REQUIRE_LIST /////////////////////////////////////////////////////////////
  // {% for req in REQUIRE_LIST %}
  // void {{NAME}}::add_{{ req.NAME }}({{req.INTERFACE.NAME }}* r){
  //   this->{{req.NAME}}.push_back(r);
  // }

  // void {{NAME}}::remove_at_{{req.NAME}}(int i){
  //   this->{{req.NAME}}[i] = this->{{req.NAME}}.back();
  //   this->{{req.NAME}}.pop_back();
  // }

  // void {{NAME}}::remove_{{ req.NAME }}({{req.INTERFACE.NAME }}* r ){

  //   this->{{req.NAME}}.erase(std::remove_if(std::begin(this->{{req.NAME}}),
  //                                           std::end(this->{{req.NAME}}),
  //                                           [r]({{req.INTERFACE.NAME }}* v){return r == v;}));
  // }
  // {% endfor %}

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
