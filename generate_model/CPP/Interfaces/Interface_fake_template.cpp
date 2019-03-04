#include "Interfaces/{{NAME}}/{{NAME}}_fake.hpp"


 {{NAME}}_fake::{{NAME}}_fake(Function_stream& out, Return_stream& in):o(out),i(in)
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
    o.start();
    o << "{{f["NAME"]}}("
      {% for a in f["SIGNATURE"] %}
    << {{a["NAME"] }}
    {%- if not loop.last%}
    << ","
         {% endif %}
    {%endfor%}
    << ")";
    o.call();

    i.pull();
    {% if f["RETURN"]["NAME"] != "void" %}
    {{f["RETURN"]["NAME"]}} ri;
    i >> ri;
    i.end();
    return ri;
    {% endif %}
  }
  {%- endfor %}


  {%- for v in DATA %}
  {{v["TYPE"]["NAME"]}} {{NAME}}_fake::get_{{v["NAME"]}}() const {
    o.start();
    o << "get_{{v["NAME"]}}()" ;
    o.call();

    i.pull();
    {{v["TYPE"]["NAME"]}} ret;
    i >> ret;
    i.end();

    return ret;
                                         }

void
{{ NAME }}_fake::set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}}) {
  this->{{v["NAME"]}} = {{v["NAME"]}};

  o << "set_{{v["NAME"]}}("
    << {{v["NAME"]}}
  << ")"
       ;

  std::string empty;
  std::getline(i, empty);
  return;
                      }
  {%- endfor %}
