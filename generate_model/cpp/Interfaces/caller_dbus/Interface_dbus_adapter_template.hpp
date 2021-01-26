#pragma once

#include "Interfaces/{{F_NAME}}/{{NAME}}.hpp"

{%if PARENT%}
#include "Interfaces/{{PARENT.F_NAME}}/{{PARENT.NAME}}_caller_dbus.hpp"
{%else%}
#include "Interfaces/Caller_dbus.hpp"
{%endif%}


{% include "helper/namespace_open.hpp" with context%}

class {{NAME}}_caller_dbus : public {%if PARENT%}{{PARENT.D_NAME}}_caller_dbus{%else%}CompoMe::Caller_dbus{%endif%}
{
 private:
 {{D_NAME}}& comp;

 public:

 {{NAME}}_caller_dbus({{D_NAME}}& pcomp);

 bool call(CompoMe::Function_dbus_recv&,
           CompoMe::Return_dbus_send&) override;

 void introspection(std::ostream& ss) override;

 protected:
 bool call(std::string &name_function,
           CompoMe::Function_dbus_recv&,
           CompoMe::Return_dbus_send&) override;
 private:

 {% for func in FUNCTION %}
 bool {{ func.NAME }}(CompoMe::Function_dbus_recv& msg, CompoMe::Return_dbus_send& reply);
 {% endfor %}

 {% for d in DATA %}
 bool get_{{ d.NAME }}(CompoMe::Function_dbus_recv& msg, CompoMe::Return_dbus_send& reply);
 bool set_{{ d.NAME }}(CompoMe::Function_dbus_recv& msg, CompoMe::Return_dbus_send& reply);
 {% endfor %}
};

{% include "helper/namespace_close.hpp" with context%}
