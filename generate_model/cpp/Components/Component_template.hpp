#pragma once

{%if PARENT %}
#include "Components/{{PARENT.F_NAME}}.hpp"
{%else%}
#include "Components/Component.hpp"
{%endif%}
#include "CompoMe/Log.hpp"
// TYPE
#include "Data/{{FILE.replace('.yaml','')}}.hpp"

// STRUCT
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
#include "Structs/{{d.F_NAME}}.hpp"
{% endfor %}

// INTERFACES
// provide
{% for inter in PROVIDE %}
#include "Components/{{F_NAME}}_{{inter.INTERFACE.NAME}}_{{inter.NAME}}.hpp"
{% endfor %}

{% for rec in RECEIVER %}
#include "Components/{{F_NAME}}_{{rec.BUS.NAME}}_{{rec.NAME}}.hpp"
{% endfor %}

// require
{% for r in REQUIRE %}
#include "Interfaces/{{r.INTERFACE.F_NAME}}/{{r.INTERFACE.NAME}}.hpp"
{% endfor %}
// require multi
{% for rl in REQUIRE_LIST %}
#include "Interfaces/{{rl.INTERFACE.F_NAME}}/{{rl.INTERFACE.NAME}}.hpp"
{% endfor %}

// SUB COMPONENT  ////////////////////////////////////////////////////////////
{% for sc in Function.model_get.get_sub_component_use_by(COMPONENT_INSTANCE).values() -%}
#include "Components/{{sc.F_NAME}}.hpp"
{% endfor %}

// SUB CONNECTOR ////////////////////////////////////////////////////////////
{% for sc in CONNECTOR_INSTANCE %}
#include "connectors/{{sc.CONNECTOR.NAME}}.hpp"
{% endfor %}


{% include "helper/namespace_open.hpp" with context %}
class {{NAME}} : public  {%if PARENT %}{{PARENT.D_NAME}}{%else%}CompoMe::Component{%endif%} {

  public:
  // Contructor / Destructor
  {{NAME}}();
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

  // RECEIVERS
  {% for pro in RECEIVER %}
  {{NAME}}_{{ pro.BUS.NAME }}_{{pro.NAME}}& get_{{ pro.NAME }}(){return this->{{pro.NAME}}; }
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


 private:
  std::ostream& to_stream_data(std::ostream& , CompoMe::Serialization_context_export& ) const;
  std::ostream& to_stream_sc(std::ostream& , CompoMe::Serialization_context_export& ) const;
  std::ostream& to_stream_provide(std::ostream& , CompoMe::Serialization_context_export&) const;

  std::istream& from_stream_data(std::istream& , CompoMe::Serialization_context_import& );
  std::istream& from_stream_sc(std::istream& , CompoMe::Serialization_context_import& );
  std::istream& from_stream_provide(std::istream& , CompoMe::Serialization_context_import&);
  {% if EXTRA %}
  void extra_export(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const;
  void extra_import(std::istream& is, CompoMe::Serialization_context_import& p_ctx);
  {% endif %}
  public:
  std::ostream& to_stream(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const override;
  std::istream& from_stream(std::istream& is, CompoMe::Serialization_context_import& p_ctx) override;

  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  {% for pro in PROVIDE -%}
  {{NAME}}_{{ pro.INTERFACE.NAME }}_{{pro.NAME}} {{ pro.NAME }};
  {% endfor %}

  // RECEIVER
  {% for rec in RECEIVER -%}
  {{NAME}}_{{ rec.BUS.NAME }}_{{rec.NAME}} {{ rec.NAME }};
  {% endfor %}

 public:
  {% for req in REQUIRE %}
  CompoMe::Require_helper_t<{{req.INTERFACE.D_NAME}}> {{req.NAME}};
  {% endfor %}

  // REQUIRE MULTI
  {% for req in REQUIRE_LIST -%}
  CompoMe::Require_helper_multi_t<{{req.INTERFACE.D_NAME}}> {{req.NAME}};
  {% endfor %}

  // EMITTER /////////////////////////////////////////////////////////////////////
  {% for v in EMITTER -%}
  //{{v.BUS.D_NAME}}
  CompoMe::Emit {{v.NAME}};
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
