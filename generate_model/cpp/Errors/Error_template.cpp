#include "Errors/{{F_NAME}}.hpp"

#include <istream>
#include <ostream>
#include <sstream>
#include <string>

{%include "helper/namespace_open.hpp" with context%}

{{NAME}}::~{{NAME}}() {}

{{NAME}}::{{NAME}}()
  {%if DATA.__len__() != 0 %}:{% endif %}
  {%- for value_data in DATA %}
    {{value_data.NAME}}(
                           {%- with TYPE=value_data.TYPE,
                                    def=value_data.DEFAULT-%}
                           {%- include "helper/lap.cpp" with context -%}
                           {%- endwith -%}
                           )
    {%- if not loop.last -%},{%- endif -%}
    {% endfor %} {
      bs += what_s();
  }


bool {{NAME}}::operator==(const {{NAME}} &other) const {

  bool p = {%if PARENT%}
    {{PARENT.NAME}}::operator==(other);
  {%else%}
  true
    {%endif%};

  {%if DATA.__len__ != 0 %}
  return p {%for l_d in DATA%} &&
  this->{{l_d.NAME}} == other.{{l_d.NAME}}
  {%endfor%};
  {%else%}
  return true;
  {%endif%}
}

bool {{NAME}}::operator!=(const {{NAME}} &other) const
{
  return !(*this == other);
}


std::string {{NAME}}::what_s() const {
  std::stringstream is;
  is <<  "-> {{NAME}}\n";

  {%for s in DATA%}
  is <<  "\t{{s.NAME}} ({{s.TYPE.NAME}}) => " <<  this->get_{{s.NAME}}() << "\n";
  {%endfor%}

  return is.str();
}

void {{NAME}}::real() {
  throw *this;
}

{%include "helper/namespace_close.hpp" with context%}


