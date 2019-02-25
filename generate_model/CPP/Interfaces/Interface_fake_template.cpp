#include "Interfaces/{{NAME}}/{{NAME}}_fake.hpp"


 {{NAME}}_fake::{{NAME}}_fake(std::ostream& out, std::istream& in):o(out),i(in)
 {

 }


 {{NAME}}_fake::~{{NAME}}_fake() noexcept{}


  {%- for f in FUNCTION %}
  {{ f["RETURN"]["NAME"] }} {{ NAME }}_fake::{{ f["NAME"] }}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )
  {
    o << "{{f["NAME"]}}("
      {% for a in f["SIGNATURE"] %}
    << {{a["NAME"] }}
    {%- if not loop.last%}
    << ","
         {% endif %}
    {%endfor%}
    << ")"
         << std::endl;

    {% if f["RETURN"]["NAME"] != "void" %}
    {{f["RETURN"]["NAME"]}} ri;
    i >> ri;
    return ri;
    {% endif %}
  }
  {%- endfor %}


  {%- for v in DATA %}
  {{v["TYPE"]["NAME"]}} {{NAME}}_fake::get_{{v["NAME"]}}() const {
    o << "get_{{v["NAME"]}}()" << std::endl;

    {{v["TYPE"]["NAME"]}} ret;
    i >> ret;

    return ret;
                                         }

void
{{ NAME }}_fake::set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}}) {
  this->{{v["NAME"]}} = {{v["NAME"]}};

  o << "set_{{v["NAME"]}}("
    << {{v["NAME"]}}
  << ")"
       << std::endl;

  std::string empty;
  std::getline(i, empty);
  return;
                      }
  {%- endfor %}
