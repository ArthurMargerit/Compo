#pragma once


#include <istream>
#include <ostream>

#include "Interfaces/{{NAME}}/{{NAME}}.hpp"
#include "Interfaces/Caller.hpp"


class {{NAME}}_caller : public Caller
{
 private:
  {{NAME}}& comp;

 public:

  {{NAME}}_caller({{NAME}}& pcomp);

  bool call(Function_stream& is, Return_stream& os);

 private:

  {% for func in FUNCTION %}
  void {{ func.NAME }}(Function_stream& is, Return_stream& os);
  {% endfor %}

  {% for d in DATA %}
  void get_{{ d.NAME }}(Function_stream& is, Return_stream& os);
  void set_{{ d.NAME }}(Function_stream& is, Return_stream& os);
  {% endfor %}


};

