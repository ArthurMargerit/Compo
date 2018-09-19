#pragma once

#include "Data/Types.hpp"
#include "Components/Component.hpp"

// INTERFACES
{% for INTERFACE in PROVIDE %}
#include "Components/{{NAME}}/{{NAME}}_{{INTERFACE["INTERFACE"]["NAME"]}}_{{INTERFACE["NAME"]}}.hpp"
{% endfor %}

{% for INTERFACE in REQUIRE %}
#include "Interfaces/{{INTERFACE["INTERFACE"]["NAME"]}}.hpp"
{% endfor %}


namespace {{NAME}} {

  class {{NAME}} : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  {% for pro in PROVIDE %}
  {{ pro["INTERFACE"]["NAME"] }} {{ pro["NAME"] }};
  {% endfor %}

  // Facette
  {% for req in REQUIRE %}
  {{ req["INTERFACE"]["NAME"] }}* {{ req["NAME"] }};
  {% endfor %}

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
  {{NAME}}& operator=(const {{NAME}} &other);

  //! Move assignment operator
  {{NAME}}& operator=({{NAME}} &&other) noexcept;


  // composant initialisation
  void configuration();

  void connection();

  void start();

  void stop();

  void status();

  {% for v in DATA %}

  {{v["TYPE"]["NAME"]}} get_{{v["NAME"]}}() const {
    return {{v["NAME"]}};
  }

  void set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}}) {
    this->{{v["NAME"]}} = {{v["NAME"]}};
  }
  {% endfor %}

  {% for f in FUNCTION %}
  {{f["RETURN"]["NAME"]}} {{f["NAME"]}}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"]}}
    {%- if not loop.last%},{% endif -%}
    {%- endfor-%}
    );
  {% endfor %}

 private:

  {% for v in DATA %}
  {{v["TYPE"]["NAME"]}} {{v["NAME"]}};
  {% endfor %}

 protected:

};
}
