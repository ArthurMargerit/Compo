#pragma once


#include "Linkers/Linker.hpp"
#include "Links/{{LINK.NAME}}/{{LINK.NAME}}.hpp"
#include <map>


class {{NAME}} : public Linker
{

 private:
  std::map<std::string, Link*> map_on_link;

  // DATA ////////////////////////////////////////////////////////////////////
  {% for data in DATA %}
  {{data.TYPE.NAME}} {{data.NAME}};
  {% endfor%}

public:

  {{NAME}}();

  virtual ~{{NAME}}();

  void link_in_add(std::string dest_name, Interface* i );
  void link_out_name(std::string orig_name, Interface*& i );
  virtual void step();


  // Get and set /////////////////////////////////////////////////////////////
  {% for data in DATA %}
  virtual
  {{data["TYPE"]["NAME"]}} get_{{data["NAME"]}}() const ;

  virtual
    void set_{{data["NAME"]}}(const {{data["TYPE"]["NAME"]}} {{data["NAME"]}});
  {%- endfor %}


};
