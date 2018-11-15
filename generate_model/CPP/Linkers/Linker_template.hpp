#pragma once


#include "Linkers/Linker.hpp"
#include "Links/{{LINK.NAME}}.hpp"
#include <map>


class {{NAME}} : public Linker
{

  std::map<std::string, Link*> map_on_link;
public:
  {{NAME}}();

  virtual ~{{NAME}}();

  void link_in_add(std::string dest_name, Interface* i );
  void link_out_name(std::string orig_name, Interface*& i );
  virtual void step();
};
