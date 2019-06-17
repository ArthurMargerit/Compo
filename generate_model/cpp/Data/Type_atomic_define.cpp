#include "Data/Type_{{NAME}}.hpp"

{% if ENUM %}
#include <string>

constexpr unsigned int str2int(const char* str, int h = 0)
{
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

std::ostream &operator<<(std::ostream &os, const {{NAME}} & c) {
  switch (c) {
    {% for k in ENUM %}
  case {{NAME | upper }}_{{k}}:
  os << "{{NAME | upper }}_{{k}}";
    break;
    {% endfor %}
  default:
    os << "error";
  }

  return os;
}

std::istream &operator>>(std::istream &is, {{NAME}} & c) {
  std::string str;
  is>>str;

  switch (str2int(str.c_str())) {
    {%for k in ENUM %}
  case str2int("{{NAME | upper }}_{{k}}"):
    c = {{NAME | upper }}_{{k}};
    break;
    {%endfor%}
  default:
    c = ({{NAME}}) -1;
  }
  return is;
}
{% endif %}

{%if TOSTRING and not DYNAMIC %}
std::ostream& operator<<(std::ostream& os, const {{NAME}}& pt){
  return os;
}

std::istream& operator>>(std::istream& is, {{NAME}}& pt){

  return is;
}
{%endif%}

