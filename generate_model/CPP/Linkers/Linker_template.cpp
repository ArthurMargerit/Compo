

#include "Linkers/{{NAME}}/{{NAME}}.hpp"

{{NAME}}::{{NAME}}(): Linker()
{

}


{{NAME}}::~{{NAME}}()
{


}

void {{NAME}}::link_in_add(std::string dest_name, Interface * i )
{

}

void {{NAME}}::link_out_name(std::string orig_name, Interface*& i )
{

}


void {{NAME}}::step()
{

}

  {% for data in DATA %}
  {{data["TYPE"]["NAME"]}} {{NAME}}::get_{{data["NAME"]}}() const {
    return {{data["NAME"]}};
  }

  void {{NAME}}::set_{{data["NAME"]}}(const {{data["TYPE"]["NAME"]}} {{data["NAME"]}}) {
    this->{{data["NAME"]}} = {{data["NAME"]}};
  }
  {%- endfor %}
