#pragma once

#include "Interfaces/{{NAME}}/{{NAME}}.hpp"
{%if PARENT%}
#include "Interfaces/{{PARENT.NAME}}/{{PARENT.NAME}}_caller.hpp"
{%else%}
#include "Interfaces/Caller.hpp"
{%endif%}

#include <string>

class {{NAME}}_caller : public {%if PARENT%}{{PARENT.NAME}}_caller{%else%}Caller{%endif%}
{
 private:
  {{NAME}}& comp;

 public:

  {{NAME}}_caller({{NAME}}& pcomp);

  bool call(Function_stream& is, Return_stream& os);
  virtual
  bool call(std::string& name_function, Function_stream& is, Return_stream& os);

 private:

  {% for func in FUNCTION %}
  void {{ func.NAME }}(Function_stream& is, Return_stream& os);
  {% endfor %}

  {% for d in DATA %}
  void get_{{ d.NAME }}(Function_stream& is, Return_stream& os);
  void set_{{ d.NAME }}(Function_stream& is, Return_stream& os);
  {% endfor %}


};

