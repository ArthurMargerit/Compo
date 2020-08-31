#include "Types/{{F_NAME}}.hpp"

{% if ENUM %}
#include <string>
{% endif %}

{% include "helper/namespace_open.hpp" with context%}

{% include "helper/namespace_close.hpp" with context %}


{% if ENUM %}
namespace std {
  namespace {
  constexpr unsigned int str2int(const char* str, int h = 0)
  {
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
  }
  }

std::ostream &operator<<(std::ostream &os, const {{D_NAME}} & c) {
  switch (c) {

  {% for k in ENUM %}
  case {{NAMESPACE}}::{{NAME | upper }}_{{k| upper}}:
  os << "{{NAMESPACE}}::{{NAME | upper }}_{{k | upper}}";
    break;
  {% endfor %}

  default:
    os << "ERROR";
  }

  return os;
}

std::istream &operator>>(std::istream &is, {{D_NAME}} & c) {
  std::string str;
  is>>str;

  switch (str2int(str.c_str())) {

  {%for k in ENUM %}
  case str2int("{{NAMESPACE}}::{{NAME | upper }}_{{k}}"):
    c = {{NAMESPACE}}::{{NAME | upper }}_{{k| upper}};
    break;
  {%endfor%}

  {% if DEFAULT %}
  default:
    c = {{NAMESPACE}}::{{NAME | upper}};
  {% endif %}
  }
  return is;
}
}
{% elif TOSTRING and not DYNAMIC %}
namespace std {
std::ostream& operator<<(std::ostream& os, const {{D_NAME}}& pt){
  return os;
}

std::istream& operator>>(std::istream& is, {{D_NAME}}& pt){

  return is;
}
} // namespace std
{% endif %}



