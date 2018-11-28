#pragma once

#include "Data/Types.hpp"
#include "Interfaces/{{NAME}}/{{NAME}}.hpp"
#include "Interfaces/Fake.hpp"

#include <ostream>
#include <istream>

class {{NAME}}_fake : public {{NAME}}, public Fake
{
public:
  //! Default constructor
  {{NAME}}_fake(std::ostream& out, std::istream& in):o(out),i(in)
            {

            }

  static
  Fake* Build_func(std::ostream& os, std::istream& is)
  {
    return new {{NAME}}_fake(os,is);
  }

  //! Destructor
  virtual ~{{NAME}}_fake() noexcept{}

  {%- for f in FUNCTION %}
  virtual
  {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
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

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for v in DATA %}
  virtual
  {{v["TYPE"]["NAME"]}} get_{{v["NAME"]}}() const {
    o << "get_{{v["NAME"]}}()" << std::endl;

    {{v["TYPE"]["NAME"]}} ret;
    i >> ret;

    return ret;
  }

  virtual
  void set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}}) {
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


protected:

private:
    std::ostream& o;
  std::istream& i;

  {%- for v in DATA %}
  {{v["TYPE"]["NAME"]}} {{v["NAME"]}};
  {%- endfor %}
};


