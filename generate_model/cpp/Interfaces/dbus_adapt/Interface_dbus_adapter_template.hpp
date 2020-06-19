#pragma once

#include "Interfaces/{{F_NAME}}//{{NAME}}.hpp"

{%if PARENT%}
#include "Interfaces/{{PARENT.F_NAME}}/{{PARENT.NAME}}_dbus_adapter.hpp"
{%else%}
#include "Interfaces/Dbus_adapter.hpp"
{%endif%}


{% include "helper/namespace_open.hpp" with context%}

class {{NAME}}_Dbus_adapter : public {%if PARENT%}{{PARENT.D_NAME}}_Dbus_adapter{%else%}Dbus_adapter{%endif%}
{
 private:
 {{D_NAME}}& comp;

 public:

 {{NAME}}_Dbus_adapter({{D_NAME}}& pcomp);

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
