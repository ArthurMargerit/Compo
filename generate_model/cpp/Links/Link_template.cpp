#include "Links/{{NAME}}/{{NAME}}.hpp"


{{NAME}}::{{NAME}}()
{

}

{{NAME}}::~{{NAME}}()
{


}

{%if S.IN  == True %}
void {{NAME}}::set_to(Interface* pto)
{

}
{% endif %}
{%if S.OUT  == True %}
void {{NAME}}::set_from(Interface** pfrom)
{

}
{% endif %}
{%if S.DIRECT  == True %}
void {{NAME}}::set_from_to(Interface** pfrom, Interface* pto)
{

}
{% endif %}

void {{NAME}}::set_build_f(std::function<Interface*(Function_stream& , Return_stream&)> p_build_f) {
  this->build_f = p_build_f;
}

void {{NAME}}::step()
{

}

void {{NAME}}::connect()
{

}

void {{NAME}}::disconnect()
{

}

// Get and set /////////////////////////////////////////////////////////////
{% for data in DATA %}
  {{data["TYPE"]["NAME"]}} {{NAME}}::get_{{data["NAME"]}}() const {
    return {{data["NAME"]}};
   }

void {{NAME}}::set_{{data["NAME"]}}(const {{data["TYPE"]["NAME"]}} {{data["NAME"]}}) {
  this->{{data["NAME"]}} = {{data["NAME"]}};
  }
  {%- endfor %}

