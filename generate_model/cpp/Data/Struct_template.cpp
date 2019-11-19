#include "Data/Struct_{{NAME}}.hpp"
#include "Data/Struct_fac_{{NAME}}.hpp"

#include <iostream>
#include <ostream>
#include <istream>
#include <sstream>

{% set d =  Function.model_get.get_all_field(DATA, PARENT, Function.model_get.remove_default) %}
{% if d.__len__() %}
{{NAME}}::{{NAME}}():{{NAME}}({% for i_d in d %}{{Function.model_get.get_data_default(i_d).replace("=","")}}{%if not loop.last %},{%endif%}{%endfor%}){}
{% endif %}


{{NAME}}::{{NAME}}(
  {%- for value_data in Function.model_get.get_all_field(DATA, PARENT) -%}
    {{value_data.TYPE.NAME}} p_{{value_data.NAME}}
    {%- if not loop.last -%}
    ,
    {%- endif -%}
    {%- endfor %})
  :{% if PARENT %}{{PARENT.NAME}}(){%else%}Struct(){%endif%}
  {%- for value_data in DATA %}
     ,{{value_data.NAME}}(p_{{value_data.NAME}})
  {% endfor %} {
}

{{NAME}}::~{{NAME}}(){}

// GET SET ////////////////////////////////////////////////////////////////////
{%- for d in DATA %}
// get/set {{d.NAME}}
{{d.TYPE.NAME}} {{NAME}}::get_{{d.NAME}}() const {
    return this->{{d.NAME}};
}

void {{NAME}}::set_{{d.NAME}}(const {{d.TYPE.NAME}}& p_{{d.NAME}}) {
  this->{{d.NAME}} = p_{{d.NAME}};
}


{%- endfor %}

// FUNCTION ///////////////////////////////////////////////////////////////////
{%- include "Data/struct_function.cpp" with context -%}


// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool {{NAME}}::operator==(const {{NAME}} &other) const {
  return {%if PARENT%}
  {{PARENT.NAME}}::operator==(other) {# ask you parent !!! #}
  {%else%}
  true {# by default #}
  {%endif%}
  {%for l_d in DATA%}
  && this->{{l_d.NAME}} == other.{{l_d.NAME}} {# each args #}
  {%endfor%};
}


bool {{NAME}}::operator!=(const {{NAME}} &other) const {
  return !(*this == other); {# reverse of == #}
}


// STREAM /////////////////////////////////////////////////////////////////////
constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}


void {{NAME}}::to_stream(std::ostream& os) const {
  os << *this;
}


std::string {{NAME}}::to_string() const {
  std::stringstream ss;
  ss << *this;
  return std::string(ss.str());
}


std::ostream& operator<<(std::ostream& os, const {{NAME}}& c) {
  os << "{"
     << "type:"<<"{{NAME}}"
    {%if PARENT or DATA  %}
     << ","
    {%endif%}
    {%-if PARENT -%}
    << "parent:" << ({{PARENT.NAME}}) c << ","
    {%-endif-%}
    {%- for d in DATA %}
     << "{{d.NAME}}:"<< c.{{d.NAME}}
      {%- if not loop.last -%}
     <<","
      {%- endif -%}
    {%- endfor %}
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, {{NAME}}& c) {
  {{NAME}} l_reset;
  c = l_reset;

  char l_c = is.get();
  if(l_c != '{') {
    std::cerr << "Wrong start: '" <<  l_c << "' != '{'";
    throw "Wrong start: '"  "' != '{'";
  }

  std::string type_start;
  std::getline(is, type_start, ':');
  if (type_start != "type") {
    std::cerr << "wrong first args:"
              << "\"type\" != \"" << type_start << "\"" << std::endl;

    throw "Wrong first args: need \"type\" have \""+type_start+"\"";
  }

  auto pair_type = get_word(is, {',','}'});
    if (pair_type.first != "{{NAME}}") {
    std::cerr << "TYPE:"
              << "\"{{NAME}}\" != \"" << pair_type.first << "\"" << std::endl;
    throw "Wrong type: need \"{{NAME}}\" have \""+pair_type.first+"\"";
  }

  char l_c1 = is.get();
  if(l_c1 == '}' ) {
    {%if PARENT -%}
    throw "wrong miss parent";
    {%else%}
    return is;
    {%endif%}
  } else if(l_c1 != ',') {
    throw "Wrong separator: " + std::to_string(l_c1);
  }

  {%if PARENT -%}
  std::string parent;
  std::getline(is, parent, ':');
  if(parent != "parent"){
    std::cerr << "PARENT: no parent data in second position"<< std::endl;
    throw "Wrong type: need \"{{NAME}}\" have \""+pair_type.first+"\"";
  }

  is >> ({{PARENT.NAME}}&) c;

  char l_c2 = is.get();
  if(l_c2 == '}') {
    return is;
  } else if (l_c2 != ',') {
    throw "Wrong separator: " + std::to_string(l_c2);
  }
  {%-endif%}

  {%if DATA %}
  do{
    std::string args;
    std::getline(is, args, ':');
    switch(str2int(args.c_str())) {
      {%- for d in DATA %}
    case str2int("{{d.NAME}}"):
      is >> c.{{d.NAME}};
      break;
      {%endfor%}
    default:
      std::cerr << "wrong attribute: \""<< args <<"\" not in {{NAME}}";
      throw "wrong attribute: \""+ args +"\" not in {{NAME}}";
      break;
    }

    l_c = is.get();
  }while(l_c == ',');

  if(l_c != '}') {
    std::cerr << "Wrong end: '"<< l_c <<"' != '}'" << std::endl;
    throw "Wrong end";
  }
  {%endif%}
  return is;
}
