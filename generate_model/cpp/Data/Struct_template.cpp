#include "Data/Struct_{{NAME}}.hpp"
#include "Data/Struct_fac_{{NAME}}.hpp"

#include <iostream>
#include <ostream>
#include <istream>
#include <sstream>


constexpr unsigned int str2int(const char* str, int h = 0)
{
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}



std::ostream& operator<<(std::ostream& os, const {{NAME}}& c)
{
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
    throw "Wrong separator: " + l_c1;
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
  }else if (l_c2 != ','){
    throw "Wrong separator: " + l_c2;
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

{% if DATA.__len__() != 0 %}
  {{NAME}}::{{NAME}}(
    {%- for value_data in DATA -%}
    {{value_data.TYPE.NAME}} p_{{value_data.NAME}}
    {%- if not loop.last -%}
    ,
    {%- endif -%}
    {%- endfor %})
  :
  {%- for value_data in DATA %}
    {{value_data.NAME}}(p_{{value_data.NAME}})
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
    {{value_data.NAME}}(
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
{{value_data.TYPE.NAME}}
{{NAME}}::get_{{value_data.NAME}}() const {
    return this->{{value_data.NAME}};
 }

void
{{NAME}}::set_{{value_data.NAME}}(const {{value_data.TYPE.NAME}} value) {
  this->{{value_data.NAME}} = value;
}
  {%- endfor %}

{%- with NAME=NAME, FUNCTION=FUNCTION, PARENT=PARENT, FIRST_PARENT=PARENT -%}
{%- include "helper/struct_function.cpp" with context -%}
{%- endwith -%}

void {{NAME}}::to_stream(std::ostream& os) const {
  os << *this;
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
