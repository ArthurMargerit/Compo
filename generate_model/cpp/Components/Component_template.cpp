
#include "Components/{{F_NAME}}.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

{% include "helper/namespace_open.hpp" with context %}

  {{NAME}}::{{NAME}}():{%if PARENT %}{{PARENT.D_NAME}}(){%else%}CompoMe::Component(){%endif%}
  {%- if PROVIDE.__len__() %}/* PROVIDE */{% endif -%}
  {%- for provide in PROVIDE-%}
                               ,{{provide.NAME}}(this)
  {%- endfor -%}
  {%- if RECEIVER.__len__() %}/* RECEIVER */{% endif -%}
  {%- for rec in RECEIVER-%}
                                ,{{rec.NAME}}(this)
  {%- endfor -%}
  {%- if REQUIRE.__len__() %}/* REQUIRE */{%- endif -%}
  {%- for req in REQUIRE-%}
                               ,{{req.NAME}}(NULL)
  {%- endfor -%}
  {%- if DATA.__len__() %}/* DATA */{%- endif -%}
  {%- for value_data in DATA -%}
                            ,{{value_data.NAME}}({%- with TYPE=value_data.TYPE, def=value_data.DEFAULT, STRUCTS=MAIN.STRUCTS-%}
                         {%- include "helper/lap.cpp" with context -%}
                         {%- endwith -%})

  {%- endfor %}
  {%- if COMPONENT_INSTANCE.__len__() %}/* COMPONENT_INSTANCE */{%- endif -%}
  {%- for sc in COMPONENT_INSTANCE-%}
                                          ,{{sc.NAME}}()
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

    {% if co.LINK == "SC_E_TO_SC_R" %}
    // {{co.FROM.INSTANCE.NAME}}.{{co.FROM.BUS.NAME}} ==> {{co.TO.INSTANCE.NAME}}.{{co.TO.BUS.NAME}}
    this->get_sc_{{co.FROM.INSTANCE.NAME}}().{{co.FROM.BUS.NAME}}.inscribe(&(this->get_sc_{{co.TO.INSTANCE.NAME}}().get_{{co.TO.BUS.NAME}}()));
    {%endif%}
    {% if co.LINK == "C_R_TO_SC_R" %}
    // this.{{co.FROM.NAME}} |=> {{co.TO.INSTANCE.NAME}}.{{co.TO.TYPE.NAME}}
    this->{{co.FROM.NAME}}.inscribe(&(this->get_sc_{{co.TO.INSTANCE.NAME}}().get_{{co.TO.TYPE.NAME}}()));
    {%endif%}
    {% if co.LINK == "SC_E_TO_C_E" %}
    // {{co.FROM.INSTANCE.NAME}}.{{co.FROM.TYPE.NAME}} >=| this.{{co.TO.NAME}}
    this->get_sc_{{co.FROM.INSTANCE.NAME}}().{{co.FROM.TYPE.NAME}}.inscribe(&this->{{co.TO.NAME}});
    {%endif%}
    {% if co.LINK == "C_R_TO_C_E" %}
    // this.{{co.FROM.NAME}} >=| this.{{co.TO.NAME}}
    this->{{co.FROM.NAME}}.inscribe(&this->{{co.TO.NAME}});
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

    // step: receiver process
    {%- for rec in RECEIVER %}
    this->{{rec.NAME}}.process();
    {%- endfor -%}

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
  //                                INTERFACES                               //
  /////////////////////////////////////////////////////////////////////////////

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

{% include "helper/namespace_close.hpp" with context %}
