#pragma once

{%if PARENT %}
#include "Components/{{PARENT.NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Components/Component.hpp"
{%endif%}

// TYPE
#include "Data/{{options.project.name}}.hpp"

// STRUCT
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).keys() %}
#include "Data/Struct_{{d}}.hpp"
{% endfor %}


// INTERFACES
{% for INTERFACE in PROVIDE %}
#include "Components/{{NAME}}/{{NAME}}_{{INTERFACE["INTERFACE"]["NAME"]}}_{{INTERFACE["NAME"]}}.hpp"
{% endfor %}

{% for INTERFACE in REQUIRE %}
#include "Interfaces/{{INTERFACE["INTERFACE"]["NAME"]}}/{{INTERFACE["INTERFACE"]["NAME"]}}.hpp"
{% endfor %}


namespace {{NAME}} {

  class {{NAME}} : public  {%if PARENT %}{{PARENT.NAME}}::{{PARENT.NAME}}{%else%}Component{%endif%} {

  public:
  // c++ 11 def
  //! construction
  {{NAME}}();

  //! Copy constructor
  {{NAME}}(const {{NAME}} &other) = delete;

  //! Move constructor
  {{NAME}}({{NAME}} &&other) = delete;

  //! Destructor
  virtual ~{{NAME}}() noexcept;

  //! Copy assignment operator
  {{NAME}}& operator=(const {{NAME}} &other) = delete;

  //! Move assignment operator
  {{NAME}}& operator=({{NAME}} &&other) noexcept = delete;


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

  // DATA /////////////////////////////////////////////////////////////////////
  {% for v in DATA -%}
  // {{v.NAME}}
  {{v.TYPE.NAME}} get_{{v.NAME}}() const;
  void set_{{v.NAME}}(const {{v.TYPE.NAME}} {{v.NAME}});

  {% endfor %}

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE
  {% for pro in PROVIDE %}
  {{ pro.INTERFACE.NAME }}_{{pro.NAME}}& get_{{ pro.NAME }}();
  {% endfor %}

  // PROVIDE
  {% for req in REQUIRE %}
  {{ req.INTERFACE.NAME }}*& get_{{ req.NAME }}();
  {% endfor %}

  // FUNCTIONS
  {% for f in FUNCTION %}
  virtual {{f.RETURN.NAME}} {{f.NAME}}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.NAME}} {{a.NAME}}
    {%- if not loop.last%},{% endif -%}
    {%- endfor-%}
    );
  {% endfor %}

 private:
  // DATA /////////////////////////////////////////////////////////////////////
  {% for v in DATA -%}
  {{v.TYPE.NAME}} {{v.NAME}};
  {% endfor %}

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE
  {% for pro in PROVIDE -%}
  {{ pro.INTERFACE.NAME }}_{{pro.NAME}} {{ pro.NAME }};
  {% endfor %}

  // PROVIDE
  {% for req in REQUIRE -%}
  {{ req.INTERFACE.NAME }}* {{ req.NAME }};
  {% endfor %}

};
}
