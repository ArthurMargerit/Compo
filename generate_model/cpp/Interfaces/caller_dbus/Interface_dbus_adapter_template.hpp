#pragma once

#include "Interfaces/{{F_NAME}}//{{NAME}}.hpp"

{%if PARENT%}
#include "Interfaces/{{PARENT.F_NAME}}/{{PARENT.NAME}}_caller_dbus.hpp"
{%else%}
#include "Interfaces/Caller_dbus.hpp"
{%endif%}


{% include "helper/namespace_open.hpp" with context%}

class {{NAME}}_caller_dbus : public {%if PARENT%}{{PARENT.D_NAME}}_caller_dbus{%else%}Caller_dbus{%endif%}
{
 private:
 {{D_NAME}}& comp;

 public:

 {{NAME}}_caller_dbus({{D_NAME}}& pcomp);

 bool call(DBus::CallMessage::pointer msg,
           DBus::ReturnMessage::pointer reply) override;

 void introspection(std::stringstream& ss) override;

 protected:
 bool call(std::string &name_function,
           DBus::CallMessage::pointer msg,
           DBus::ReturnMessage::pointer reply) override;
 private:

 {% for func in FUNCTION %}
 bool {{ func.NAME }}(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 {% endfor %}

 {% for d in DATA %}
 bool get_{{ d.NAME }}(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply);
 bool set_{{ d.NAME }}(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply);
 {% endfor %}
};

{% include "helper/namespace_close.hpp" with context%}
