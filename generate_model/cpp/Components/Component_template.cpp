
#include <iostream>
#include "Components/{{NAME}}/{{NAME}}.hpp"

namespace {{NAME}}{

  {{NAME}}::{{NAME}}()
                      {%- if PROVIDE.__len__() != 0  or REQUIRE.__len__() != 0 or DATA.__len__() !=0 or SUB_COMPONENT.__len__() !=0 -%}
  :
  {%- endif -%}

  {%- if PROVIDE.__len__() %}
  /* PROVIDE */
  {% endif -%}
  {%-for provide in PROVIDE-%}
  {{provide.NAME}}(this){%- if not loop.last-%},{%- endif -%}
  {%- endfor -%}

  {%- if REQUIRE.__len__() != 0 and PROVIDE.__len__() !=0  -%},{%- endif -%}
  {%- if REQUIRE.__len__() %}
  /* REQUIRE */
  {% endif -%}
  {%-for req in REQUIRE-%}
  {{req.NAME}}(NULL){%- if not loop.last-%},{%- endif -%}
  {%- endfor -%}

  {%-if DATA.__len__() != 0  and (PROVIDE.__len__() != 0  or REQUIRE.__len__() != 0) -%},{%- endif -%}
  {%- if DATA.__len__() %}
  /* DATA */
  {% endif -%}
  {%- for value_data in DATA -%}
  {{value_data.NAME}}({%- with TYPE=value_data.TYPE, def=value_data.DEFAULT, STRUCTS=MAIN.STRUCTS-%}
                         {%- include "helper/lap.cpp" with context -%}
                         {%- endwith -%})
                         {%- if not loop.last -%},{%- endif -%}
  {%- endfor %}

  {%-if SUB_COMPONENT.__len__() != 0  and
                        (DATA.__len__() != 0 or PROVIDE.__len__() != 0  or REQUIRE.__len__() != 0) -%},{%- endif -%}
  {%- if SUB_COMPONENT.__len__() %}
  /* SUB_COMPONENT */
  {% endif -%}
  {%-for sc in SUB_COMPONENT-%}
  {{sc.NAME}}(){%- if not loop.last-%},{%- endif -%}
  {%- endfor -%}
  {
    std::cout << "--CONST : {{NAME}}" << std::endl;
    return;
  }


  //! Destructor
  {{NAME}}::~{{NAME}}() noexcept
                       {
                         std::cout << "--DEST  : {{NAME}}" << std::endl;
                         return;
                       }


  /////////////////////////////////////////////////////////////////////////////
  //                           COMPONENT_FUNCTIONS                           //
  /////////////////////////////////////////////////////////////////////////////

  void {{NAME}}::configuration() {
    {%if PARENT -%}
    {{PARENT.NAME}}::configuration();
    {%else-%}
    Component::configuration();
    {%endif-%}
    std::cout << "--CONF  : {{NAME}}" << std::endl;

    // configuration: sub_component
    {%-for sc in SUB_COMPONENT%}
    {{sc.NAME}}.configuration();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::connection() {
    // connect: parent
    {%if PARENT -%}
    {{PARENT.NAME}}::connection();
    {%else-%}
    Component::connection();
    {%endif-%}
    std::cout << "--CONECT: {{NAME}}" << std::endl;

    // connect: intern
    {% for co in CONNECTION %}
    {% if co.LINK == "SC_R_TO_SC_P" %}
    // {{co.FROM.INSTANCE.NAME}}.{{co.FROM.INTERFACE.NAME}} --> {{co.TO.INSTANCE.NAME}}.{{co.TO.INTERFACE.NAME}}
    this->{{co.FROM.INSTANCE.NAME}}.get_{{co.FROM.INTERFACE.NAME}}() = &(this->{{co.TO.INSTANCE.NAME}}.get_{{co.TO.INTERFACE.NAME}}());
    {%endif%}
    {% endfor %}

    // connect: sub component
    {%-for sc in SUB_COMPONENT %}
    {{sc.NAME}}.connection();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::start() {
    // start: parent
    {%if PARENT -%}
    {{PARENT.NAME}}::start();
    {%else-%}
    Component::start();
    {%endif-%}
    std::cout << "--START : {{NAME}}" << std::endl;

    // start: sub component
    {%-for sc in SUB_COMPONENT %}
    {{sc.NAME}}.start();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::step() {
    // step: parent
    {%if PARENT -%}
    {{PARENT.NAME}}::step();
    {%else-%}
    Component::step();
    {%endif-%}
    std::cout << "--STEP  : {{NAME}}" << std::endl;

    // step: sub_component
    {%-for sc in SUB_COMPONENT%}
    {{sc.NAME}}.step();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::stop() {
    // stop: parent
    {%if PARENT -%}
    {{PARENT.NAME}}::stop();
    {%else-%}
    Component::stop();
    {%endif-%}

    // stop: sub_component
    std::cout << "--STOP  : {{NAME}}" << std::endl;
    {%-for sc in SUB_COMPONENT-%}
    {{sc.NAME}}.stop();
    {%- endfor -%}

    return;
  }

  void {{NAME}}::status() {
    // status: parent
    {%if PARENT -%}
    {{PARENT.NAME}}::status();
    {%else-%}
    Component::status();
    {%endif-%}

    // status: sub_component
    std::cout << "--STATUS: {{NAME}}" << std::endl;
    {%-for sc in SUB_COMPONENT-%}
    {{sc.NAME}}.status();
    {%- endfor -%}
    return;
  }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTIONS                               //
  /////////////////////////////////////////////////////////////////////////////
  {% for f in FUNCTION %}
  {{f.RETURN.NAME}} {{NAME}}::{{f.NAME}}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.NAME}} {{a.NAME}}
    {%- if not loop.last%},{% endif -%}
    {%- endfor-%}
    ) {
     {% if "DEFAULT" in f.RETURN%}
     return {{f.RETURN.DEFAULT}};
     {% else %}
     return {{f.RETURN.NAME}}();
     {% endif %}
   }
  {% endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                                INTERFACES                               //
  /////////////////////////////////////////////////////////////////////////////

  // PROVIDE //////////////////////////////////////////////////////////////////
  {% for pro in PROVIDE %}
  {{ pro.INTERFACE.NAME }}_{{pro.NAME}}&  {{NAME}}::get_{{ pro.NAME }}() {
    return this->{{ pro.NAME }};
  }
  {% endfor %}

  // REQUIRE //////////////////////////////////////////////////////////////////
  {% for req in REQUIRE %}
  {{ req.INTERFACE.NAME }}*&  {{NAME}}::get_{{ req.NAME }}() {
    return this->{{ req.NAME }};
  }
  {% endfor %}


  /////////////////////////////////////////////////////////////////////////////
  //                                   DATA                                  //
  /////////////////////////////////////////////////////////////////////////////
  {% for v in DATA %}
  // {{v.NAME}}
  {{v.TYPE.NAME}} {{NAME}}::get_{{v.NAME}}() const {
    return this->{{v.NAME}};
  }

  void  {{NAME}}::set_{{v.NAME}}(const {{v.TYPE.NAME}} {{v.NAME}}) {
    this->{{v.NAME}} = {{v.NAME}};
  }


  {% endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                            SUB COMPONENT                                //
  /////////////////////////////////////////////////////////////////////////////
  {% for sc in SUB_COMPONENT %}
  {{ sc.COMPONENT.NAME }}::{{ sc.COMPONENT.NAME }}& {{NAME}}::get_sc_{{ sc.NAME }}() {
    return this->{{ sc.NAME }};
  }
  {% endfor %}
}
