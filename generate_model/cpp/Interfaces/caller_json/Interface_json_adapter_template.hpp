#pragma once

#include "Interfaces/{{F_NAME}}/{{NAME}}.hpp"

{%if PARENT%}
#include "Interfaces/{{PARENT.F_NAME}}/{{PARENT.NAME}}_caller_json.hpp"
{%else%}
#include "Interfaces/Caller_json.hpp"
#include <string>

{%endif%}


{% include "helper/namespace_open.hpp" with context%}

class {{NAME}}_caller_json : public {%if PARENT%}{{PARENT.D_NAME}}_caller_json{%else%}CompoMe::Caller_json{%endif%}
{
 private:
 {{D_NAME}}& comp;

 public:

 {{NAME}}_caller_json({{D_NAME}}& pcomp);

 bool call(CompoMe::Function_json_recv&,
           CompoMe::Return_json_send&) override;

 void introspection(std::ostream& ss) override;

 protected:
 bool call(std::string &name_function,
           CompoMe::Function_json_recv&,
           CompoMe::Return_json_send&) override;
 private:

 {% for func in FUNCTION %}
 bool {{ func.NAME }}(CompoMe::Function_json_recv& msg, CompoMe::Return_json_send& reply);
 {% endfor %}

 {% for d in DATA %}
 bool get_{{ d.NAME }}(CompoMe::Function_json_recv& msg, CompoMe::Return_json_send& reply);
 bool set_{{ d.NAME }}(CompoMe::Function_json_recv& msg, CompoMe::Return_json_send& reply);
 {% endfor %}
};

{% include "helper/namespace_close.hpp" with context%}
