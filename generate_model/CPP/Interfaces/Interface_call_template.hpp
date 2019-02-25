#pragma once


#include <istream>
#include <ostream>

#include "Interfaces/{{NAME}}/{{NAME}}.hpp"
#include "Interfaces/Caller.hpp"


class {{NAME}}_caller : public Caller
{
 private:
  {{NAME}}& comp;

 public:

  {{NAME}}_caller({{NAME}}& pcomp);

  bool call(std::istream& is, std::ostream& os);

 private:

  {% for func in FUNCTION %}
  void {{ func.NAME }}(std::istream& is, std::ostream& os);
  {% endfor %}

  {% for d in DATA %}
  void get_{{ d.NAME }}(std::istream& is, std::ostream& os);
  void set_{{ d.NAME }}(std::istream& is, std::ostream& os);
  {% endfor %}


};

