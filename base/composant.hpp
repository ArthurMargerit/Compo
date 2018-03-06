#pragma once

#include "types.hpp"

// INTERFACES
{% for inter in INTERFACES %}
#include "{{inter}}.hpp"
{% endfor %}



class {{NAME}}
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
  {{NAME}}(const {{NAME}} &other);

  //! Move constructor
  {{NAME}}({{NAME}} &&other) noexcept;

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

 private:

  // Facette
  {% for v in VAR %}
  //  {{ v }}
  {% endfor %}

 protected:

};
