#include "Data/Struct_{{NAME}}.hpp"
#include <iostream>

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const {{NAME}}* c) {
  os << (Struct*) c;
  return os;
}

std::istream& operator>>(std::istream& is, {{NAME}}*& c) {
  std::string t = get_type(is);
  if(t != "{{NAME}}"
    {% for l in Function.model_get.get_children_rec(STRUCTS, NAME) %}
    && t != "{{l}}"
    {% endfor %}
     ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <{{NAME}}>\n";
    {%if Function.model_test.have_children(STRUCTS,NAME) %}
    std::cerr << "\t" << t << " is not one of child type {{Function.model_get.get_children_rec(STRUCTS,NAME)}}\n";
    {%endif%}
    }
  is >> (Struct*&) c;
  return is;
}


std::ostream& operator<<(std::ostream& os, const {{NAME}}& c)
{
  os << "{"
     << "type:"<<"{{NAME}},"
    {%-if PARENT -%}
  << "parrent:" << ({{PARENT.NAME}}) c << ","
    {%-endif-%}
  {%- for d in DATA %}
     << "{{d["NAME"]}}:"<< c.{{d["NAME"]}}
    {%- if not loop.last -%}
     <<","
    {%- endif -%}
  {%- endfor %}
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, {{NAME}}& c)
{
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type,',');
  if (type != "{{NAME}}") {
    std::cerr << "ERREUR TYPE:"
              << ">{{NAME}}< != >" << type << "<" << std::endl;
  }
  {%if PARENT -%}
  is.ignore(100, ':') >> ({{PARENT.NAME}}&) c;
  {%-endif%}
  {%- for d in DATA %}
  is.ignore(100, ':') >> c.{{d["NAME"]}} ;
  {%- if not loop.last -%}
  is.ignore(1, ',');
  {%- endif -%}
  {%- endfor %}
  is.ignore(1, '}');

  return is;
}

{% if DATA.__len__() != 0 %}
  {{NAME}}::{{NAME}}(
    {%- for value_data in DATA -%}
    {{value_data["TYPE"]["NAME"]}} p_{{value_data["NAME"]}}
    {%- if not loop.last -%}
    ,
    {%- endif -%}
    {%- endfor %})
  :
  {%- for value_data in DATA %}
    {{value_data["NAME"]}}(p_{{value_data["NAME"]}})
    {%- if not loop.last -%}
        ,
    {%- endif -%}
    {% endfor %}
  {

  }
{% endif %}

  {{NAME}}::{{NAME}}()
  {%if DATA.__len__() != 0 %}:{% endif %}
  {%- for value_data in DATA %}
    {{value_data["NAME"]}}(
                           {%- with TYPE=value_data.TYPE,
                                    def=value_data.DEFAULT-%}
                           {%- include "helper/lap.cpp" with context -%}
                           {%- endwith -%}
                           )
    {%- if not loop.last -%}
        ,
    {%- endif -%}
    {% endfor %}
  {
  }

  {%- for value_data in DATA %}
{{value_data["TYPE"]["NAME"]}}
{{NAME}}::get_{{value_data["NAME"]}}() const {
    return this->{{value_data["NAME"]}};
 }

void
{{NAME}}::set_{{value_data["NAME"]}}(const {{value_data["TYPE"]["NAME"]}} value) {
  this->{{value_data["NAME"]}} = value;
}
  {%- endfor %}

{%- with NAME=NAME, FUNCTION=FUNCTION, PARENT=PARENT, FIRST_PARENT=PARENT -%}
{%- include "helper/struct_function.cpp" with context -%}
{%- endwith -%}

void {{NAME}}::to_stream(std::ostream& os) const {
  os << *this;
}
