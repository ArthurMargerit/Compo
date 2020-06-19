
#include "Interfaces/{{F_NAME}}//{{NAME}}_dbus_adapter.hpp"
#include "Errors/Error.hpp"


{% include "helper/namespace_open.hpp" with context%}
constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

{{NAME}}_Dbus_adapter::{{NAME}}_Dbus_adapter({{D_NAME}}& pcomp):{%if PARENT%}{{PARENT.D_NAME}}_Dbus_adapter(pcomp){%else%}Dbus_adapter(){%endif%},comp(pcomp){}

void {{NAME}}_Dbus_adapter::introspection(std::stringstream& ss){

  {% if PARENT %}
  {{PARENT.D_NAME}}_Dbus_adapter::introspection(ss);
  {% endif %}

  {% for func in FUNCTION %}
  ss << "<method name=\"{{func.NAME}}\">"
  {% for arg in func.SIGNATURE %}
    {{ Function.model_test.is_dbus_export(arg.TYPE)}}
    << "<arg type=\"{{arg.TYPE.DBUS}}\" name=\"{{arg.NAME}}\" direction=\"in\"/>"
  {% endfor %}

  {% if func.RETURN.NAME != "void" %}
    << "<arg type=\"{{func.RETURN.DBUS}}\" name=\"ret\" direction=\"out\"/>"
  {% endif%}

    << "</method>";
  {% endfor %}

  {% for d in DATA %}
  ss << "<method name=\"get_{{d.NAME}}\">"
     << "<arg type=\"{{d.TYPE.DBUS}}\" name=\"ret\" direction=\"out\"/>"
     << "</method>";

  ss << "<method name=\"set_{{d.NAME}}\">"
     << "<arg type=\"{{d.TYPE.DBUS}}\" name=\"set\" direction=\"in\"/>"
     << "</method>";

  ss << "<property type=\"{{d.TYPE.DBUS}}\" name=\"{{d.NAME}}\" access=\"readwrite\"/>";
  {% endfor %}
}


bool {{NAME}}_Dbus_adapter::call(DBus::CallMessage::pointer msg,
                                 DBus::ReturnMessage::pointer reply) {

  std::string name_function = msg->member();
  bool b = this->call(name_function,msg,reply);
  return b;
}



bool {{NAME}}_Dbus_adapter::call(std::string &name_function, DBus::CallMessage::pointer msg,
                                 DBus::ReturnMessage::pointer reply) {
  bool result = false;

  switch(str2int(name_function.c_str())) {
    // Function
    {% for func in FUNCTION%}
  case str2int("{{func.NAME}}"):
    result= this->{{func.NAME}}(msg, reply);
    break;
    {% endfor %}

    // Get/Set
    {% for d in DATA%}
  case str2int("get_{{d.NAME}}"):
    result = this->get_{{d.NAME}}(msg, reply);
    break;
  case str2int("set_{{d.NAME}}"):
    result = this->set_{{d.NAME}}(msg, reply);
    break;

    {% endfor %}

    {%if PARENT %}
  default:
    return {{PARENT.D_NAME}}_Dbus_adapter::call(name_function, msg, reply);
    break;
    {%endif%}
  };

  return result;
}

 {% for func in FUNCTION %}
bool {{NAME}}_Dbus_adapter::{{ func.NAME }}(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    {% for arg in func.SIGNATURE %}
    {%if loop.first%}
    auto i = msg->begin();
    {%endif%}

    {{arg.TYPE.D_NAME}} l_{{arg.NAME}};
    i = i >> l_{{arg.NAME}};
    {% endfor %}

    try {
      {% if func.RETURN.NAME == "void" %}
      this->comp.{{ func.NAME }}({% for arg in func.SIGNATURE -%}
    l_{{arg.NAME}}
      {%- if not loop.last %}, {% endif %}
    {%- endfor %});
  {%else%}
  reply << this->comp.{{ func.NAME }}({% for arg in func.SIGNATURE -%}
    l_{{arg.NAME}}
      {%- if not loop.last %}, {% endif %}
    {%- endfor %});
  {% endif %}

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}
{% endfor %}

{% for d in DATA %}
bool {{NAME}}_Dbus_adapter::get_{{ d.NAME }}(DBus::CallMessage::pointer msg,
                                             DBus::ReturnMessage::pointer reply){
 try {
   reply << this->comp.get_{{d.NAME}}();
 } catch (const Error &e) {
   std::stringstream ss;
   ss << "!" << &e;
   reply << ss.str();
 }

 return true;
}

bool {{NAME}}_Dbus_adapter::set_{{ d.NAME }}(DBus::CallMessage::pointer msg,
                                             DBus::ReturnMessage::pointer reply){
  {{d.TYPE.D_NAME}} set_val;
  msg >> set_val;

  try {
    this->comp.set_{{d.NAME}}(set_val);
  } catch (const Error &e) {
     std::stringstream ss;
     ss << "!" << &e;
     reply << ss.str();
  }

  return true;
}
{% endfor %}
{% include "helper/namespace_open.hpp" with context%}
