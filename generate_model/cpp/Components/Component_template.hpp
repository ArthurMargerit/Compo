#pragma once

{%if PARENT %}
#include "Components/{{PARENT.D_NAME.replace('::','/')}}.hpp"
{%else%}
#include "Components/Component.hpp"
{%endif%}

// TYPE
#include "Data/{{FILE.replace('.yaml','')}}.hpp"

// STRUCT
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
#include "Data/{{d.D_NAME.replace('::','/')}}.hpp"
{% endfor %}

// INTERFACES
// provide
{% for INTERFACE in PROVIDE %}
#include "Components/{{D_NAME.replace('::','/')}}_{{INTERFACE.INTERFACE.NAME}}_{{INTERFACE.NAME}}.hpp"
{% endfor %}

// require
{% for r in REQUIRE %}
#include "Interfaces/{{r.INTERFACE.D_NAME.replace('::','/')}}/{{r.INTERFACE.NAME}}_fake.hpp"
{% endfor %}
// require multi
{% for rl in REQUIRE_LIST %}
#include "Interfaces/{{rl.INTERFACE.D_NAME.replace('::','/')}}/{{rl.INTERFACE.NAME}}_fake.hpp"
{% endfor %}

// SUB COMPONENT  ////////////////////////////////////////////////////////////
{% for sc in Function.model_get.get_sub_component_use_by(COMPONENT_INSTANCE).values() -%}
#include "Components/{{sc.D_NAME.replace('::','/')}}.hpp"
{% endfor %}

// SUB CONNECTOR ////////////////////////////////////////////////////////////
{% for sc in CONNECTOR_INSTANCE %}
#include "connectors/{{sc.CONNECTOR.NAME}}.hpp"
{% endfor %}

#include <iostream>

{% include "helper/namespace_open.hpp" with context %}
  class {{NAME}} : public  {%if PARENT %}{{PARENT.D_NAME}}{%else%}Component{%endif%} {

  public:
  // c++ 11 def
  //! construction
  {{NAME}}();

  //! Destructor
  virtual ~{{NAME}}() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////
  {% for v in DATA -%}
  // {{v.NAME}}
  {{v.TYPE.D_NAME}} get_{{v.NAME}}() const;
  void set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}});
  {% endfor %}

  // PROVIDES
  {% for pro in PROVIDE %}
  {{NAME}}_{{ pro.INTERFACE.NAME }}_{{pro.NAME}}& get_{{ pro.NAME }}();
  {% endfor %}

  // FUNCTIONS
  {% for f in FUNCTION %}
  virtual {{f.RETURN.D_NAME}} {{f.NAME}}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME}}
    {%- if not loop.last%},{% endif -%}
    {%- endfor-%}
    );
  {% endfor %}

  // SUB COMPONENTS
  {% for sc in COMPONENT_INSTANCE %}
  {{ sc.COMPONENT.D_NAME }}& get_sc_{{ sc.NAME }}();
  {% endfor %}

  {% for sc in CONNECTOR_INSTANCE %}
  {{ sc.CONNECTOR.NAME }}& get_sc_{{ sc.NAME }}();
  {% endfor %}

  std::ostream& to_stream(std::ostream& os, Serialization_context_export& p_ctx) const override;
  std::istream& from_stream(std::istream& is, Serialization_context_import& p_ctx) override;
  {% if EXTRA %}
  void extra_export(std::ostream& os, Serialization_context_export& p_ctx) const;
  void extra_import(std::istream& is, Serialization_context_import& p_ctx);
  {% endif %}

 private:

  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  {% for pro in PROVIDE -%}
  {{NAME}}_{{ pro.INTERFACE.NAME }}_{{pro.NAME}} {{ pro.NAME }};
  {% endfor %}

 public:
  {% for req in REQUIRE %}
  Require_helper_t<{{req.INTERFACE.D_NAME}}> {{req.NAME}};
  {% endfor %}

  // REQUIRE MULTI
  {% for req in REQUIRE_LIST -%}
  Require_helper_multi_t<{{req.INTERFACE.D_NAME}}> {{req.NAME}};
  {% endfor %}

  // DATA /////////////////////////////////////////////////////////////////////
  {% for v in DATA -%}
  {{v.TYPE.D_NAME}} {{v.NAME}};
  {% endfor %}

  // SUB COMPONENT ////////////////////////////////////////////////////////////
  {% for sc in COMPONENT_INSTANCE -%}
  {{ sc.COMPONENT.D_NAME }} {{sc.NAME}};
  {% endfor %}

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
  {% for sc in CONNECTOR_INSTANCE %}
  {{ sc.CONNECTOR.D_NAME }} {{sc.NAME}};
  {% endfor %}
};

  std::ostream& operator<<(std::ostream& os, const {{NAME}}& c);
  std::istream& operator>>(std::istream& is, {{NAME}}& c);

{% include "helper/namespace_close.hpp" with context %}
