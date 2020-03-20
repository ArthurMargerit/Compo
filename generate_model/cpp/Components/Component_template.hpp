#pragma once

{%if PARENT %}
#include "Components/{{PARENT.D_NAME.replace('::','/')}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Components/Component.hpp"
{%endif%}

// TYPE
#include "Data/{{FILE.replace('.yaml','')}}.hpp"

// STRUCT
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
#include "Data/{{d.NAMESPACE.replace('::','/')}}/Struct_{{d.NAME}}.hpp"
{% endfor %}

// INTERFACES
// provide
{% for INTERFACE in PROVIDE %}
#include "Components/{{D_NAME.replace('::','/')}}/{{NAME}}_{{INTERFACE.INTERFACE.NAME}}_{{INTERFACE.NAME}}.hpp"
{% endfor %}

// require
{# TODO: replace include by anonyme #}
{% for r in REQUIRE %}
#include "Interfaces/{{r.INTERFACE.D_NAME.replace('::','/')}}/{{r.INTERFACE.NAME}}.hpp"
{% endfor %}
{% for rl in REQUIRE_LIST %}
#include "Interfaces/{{rl.INTERFACE.D_NAME.replace('::','/')}}/{{rl.INTERFACE.NAME}}.hpp"
{% endfor %}

// SUB COMPONENT  ////////////////////////////////////////////////////////////
{% for sc in Function.model_get.get_sub_component_use_by(COMPONENT_INSTANCE).values() %}
#include "Components/{{sc.D_NAME.replace('::','/')}}/{{sc.NAME}}.hpp"
{% endfor %}

// SUB CONNECTOR ////////////////////////////////////////////////////////////
{% for sc in CONNECTOR_INSTANCE %}
#include "connectors/{{sc.CONNECTOR.NAME}}.hpp"
{% endfor %}

#include <iostream>

{% include "helper/namespace_open.hpp" with context %}
namespace {{NAME}} {

  class {{NAME}} : public  {%if PARENT %}{{PARENT.D_NAME}}::{{PARENT.NAME}}{%else%}Component{%endif%} {

  public:
  // c++ 11 def
  //! construction
  {{NAME}}();

  // //! Copy constructor
  // {{NAME}}(const {{NAME}} &other) = delete;

  // //! Move constructor
  // {{NAME}}({{NAME}} &&other) = delete;

  //! Destructor
  virtual ~{{NAME}}() noexcept;

  // //! Copy assignment operator
  // {{NAME}}& operator=(const {{D_NAME}}::{{NAME}} &other) = delete;

  // //! Move assignment operator
  // {{NAME}}& operator=({{D_NAME}}::{{NAME}} &&other) noexcept = delete;


  // composant initialisation
  {%if PARENT%}
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;
  {%else%}
  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void stop();
  virtual void step();
  virtual void status();
  {%endif%}

  // GET/SET //////////////////////////////////////////////////////////////////
  {% for v in DATA -%}
  // {{v.NAME}}
  {{v.TYPE.D_NAME}} get_{{v.NAME}}() const;
  void set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}});
  {% endfor %}

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRES
  {% for req in REQUIRE %}
  void set_{{ req.NAME }}({{ req.INTERFACE.D_NAME }}*);
  {% endfor %}

  {% for req in REQUIRE %}
  Fake* fake_{{req.NAME}}();
  {% endfor %}

  // REQUIRES LISTS
  {% for req in REQUIRE_LIST %}
  void add_{{ req.NAME }}({{req.INTERFACE.D_NAME }}*);
  void remove_at_{{ req.NAME }}(int);
  void remove_{{ req.NAME }}({{req.INTERFACE.D_NAME }}* r);
  {% endfor %}

  // PROVIDES
  {% for pro in PROVIDE %}
  {{ pro.INTERFACE.NAME }}_{{pro.NAME}}& get_{{ pro.NAME }}();
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
  {{ sc.COMPONENT.D_NAME }}::{{ sc.COMPONENT.NAME }}& get_sc_{{ sc.NAME }}();
  {% endfor %}

  {% for sc in CONNECTOR_INSTANCE %}
  {{ sc.CONNECTOR.NAME }}& get_sc_{{ sc.NAME }}();
  {% endfor %}

  // PACK/UNPACK
  void save(std::ostream& os) const;
  void load(std::istream& is);

 private:

  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  {% for pro in PROVIDE -%}
  {{ pro.INTERFACE.NAME }}_{{pro.NAME}} {{ pro.NAME }};
  {% endfor %}

  // REQUIRE
  {% for req in REQUIRE -%}
  {{ req.INTERFACE.D_NAME }}* {{ req.NAME }};
  {% endfor %}

  // REQUIRE_LIST
  {% for req in REQUIRE_LIST -%}
  std::vector<{{ req.INTERFACE.D_NAME }}*> {{ req.NAME }};
  {% endfor %}

  // DATA /////////////////////////////////////////////////////////////////////
  {% for v in DATA -%}
  {{v.TYPE.D_NAME}} {{v.NAME}};
  {% endfor %}

  // SUB COMPONENT ////////////////////////////////////////////////////////////
  {% for sc in COMPONENT_INSTANCE -%}
  {{ sc.COMPONENT.D_NAME }}::{{ sc.COMPONENT.NAME }} {{sc.NAME}};
  {% endfor %}

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
  {% for sc in CONNECTOR_INSTANCE %}
  {{ sc.CONNECTOR.D_NAME }} {{sc.NAME}};
  {% endfor %}

  // EXTRA ////////////////////////////////////////////////////////////////////
  {% if EXTRA -%}
  void _get_extra(std::ostream& os) const;
  void _set_extra(std::istream& is);
  {%- endif-%}
};
}
{% include "helper/namespace_close.hpp" with context %}
