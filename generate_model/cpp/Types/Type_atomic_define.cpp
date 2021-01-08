#include "Types/{{F_NAME}}.hpp"

{% if ENUM %}
#include "Serialization_context.hpp"
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
  str = CompoMe::get_word(is, {',', ')'}).first;
  switch (str2int(str.c_str())) {

  {%for k in ENUM %}
  case str2int("{{ENUM[k]}}"): //value
  case str2int("{{k}}"): // no namespace and typename space
  case str2int("{{NAME | upper }}_{{k}}"): // no namespace space
  case str2int("{{NAMESPACE}}::{{NAME | upper }}_{{k}}"): // namespace
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



