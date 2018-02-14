#pragma once

#include "Type.hpp"

class {{Facette_name}}
{
public:
  //! Default constructor
  {{Facette_name}}();

  //! Copy constructor
  {{Facette_name}}(const {{Facette_name}} &other);

  //! Move constructor
  {{Facette_name}}({{Facette_name}} &&other) noexcept;

  //! Destructor
  virtual ~{{Facette_name}}() noexcept;

  //! Copy assignment operator
  {{Facette_name}}& operator=(const {{Facette_name}} &other);

  //! Move assignment operator
  {{Facette_name}}& operator=({{Facette_name}} &&other) noexcept;

  {% for function in functions %}
  {{ function.return_type }} {{ function.name }}({{ function.arg }});
  {% endfor %}

protected:
private:
};
