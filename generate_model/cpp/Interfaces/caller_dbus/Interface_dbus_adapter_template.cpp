
#include "Interfaces/{{F_NAME}}//{{NAME}}_caller_dbus.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_dbus_recv.hpp"
#include "Interfaces/Return_dbus_send.hpp"

{% include "helper/namespace_open.hpp" with context%}
constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

{{NAME}}_caller_dbus::{{NAME}}_caller_dbus({{D_NAME}}& pcomp)
:{%if PARENT -%}
{{PARENT.D_NAME}}_caller_dbus(pcomp)
{%- else -%}
CompoMe::Caller_dbus()
{%- endif%},comp(pcomp){}

void {{NAME}}_caller_dbus::introspection(std::ostream& ss){

  {% if PARENT %}
  {{PARENT.D_NAME}}_caller_dbus::introspection(ss);
  {% endif %}

  {% for func in FUNCTION %}
  ss << "<method name=\"{{func.NAME}}\">"
  {% for arg in func.SIGNATURE %}
  {% if Function.model_test.is_struct(arg.TYPE.D_NAME,MAIN) %}
  << "<arg type=\"a{sv}\" name=\"{{arg.NAME}}\" direction=\"in\"/>"
  {%else%}
  << "<arg type=\"{{arg.TYPE.DBUS}}\" name=\"{{arg.NAME}}\" direction=\"in\"/>"
  {%endif%}

  {% endfor %}

  {% if func.RETURN.NAME != "void" %}
     {% if Function.model_test.is_struct(func.RETURN.D_NAME,MAIN) %}
    << "<arg type=\"a{sv}\" name=\"ret\" direction=\"out\"/>"
     {%else%}
    << "<arg type=\"{{func.RETURN.DBUS}}\" name=\"ret\" direction=\"out\"/>"
     {%endif%}
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


bool {{NAME}}_caller_dbus::call(CompoMe::Function_dbus_recv& msg, CompoMe::Return_dbus_send& reply) {

  std::string name_function = msg.get_function();
  bool b = this->call(name_function,msg,reply);
  return b;
}



bool {{NAME}}_caller_dbus::call(std::string &name_function, CompoMe::Function_dbus_recv& msg, CompoMe::Return_dbus_send& reply) {
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
    return {{PARENT.D_NAME}}_caller_dbus::call(name_function, msg, reply);
    break;
    {%endif%}
  };

  return result;
}

 {% for func in FUNCTION %}
bool {{NAME}}_caller_dbus::{{ func.NAME }}(CompoMe::Function_dbus_recv& msg, CompoMe::Return_dbus_send& reply){

    {% for arg in func.SIGNATURE %}
    {{arg.TYPE.D_NAME}} l_{{arg.NAME}};
    {%if Function.model_test.is_struct(arg.TYPE.D_NAME, MAIN) %}
    import_struct(msg, l_{{arg.NAME}});
    {%else%}
    msg >> l_{{arg.NAME}};
    {%endif%}
    {% endfor %}

    try {
      {% if func.RETURN.NAME == "void" %}
      this->comp.{{ func.NAME }}(
        {% for arg in func.SIGNATURE -%}
    l_{{arg.NAME}} {%- if not loop.last %},{% endif %}
      {%- endfor %});
  {%else%}
    auto rep = this->comp.{{ func.NAME }}({% for arg in func.SIGNATURE -%}
    l_{{arg.NAME}}
      {%- if not loop.last %}, {% endif %}
    {%- endfor %});

    {%if Function.model_test.is_struct(func.RETURN.D_NAME, MAIN) %}
    export_struct(reply, rep);
    {%else%}
    reply << rep;
    {%endif%}

  {% endif %}

    } catch (const CompoMe::Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}
{% endfor %}

{% for d in DATA %}
bool {{NAME}}_caller_dbus::get_{{ d.NAME }}(CompoMe::Function_dbus_recv& msg, CompoMe::Return_dbus_send& reply){
 try {
   auto rep = this->comp.get_{{d.NAME}}();
   {%if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
   export_struct(reply, rep);
   {%else%}
   reply << rep;
   {%endif%}


 } catch (const CompoMe::Error &e) {
   std::stringstream ss;
   ss << "!" << &e;
   reply << ss.str();
 }

 return true;
}

bool {{NAME}}_caller_dbus::set_{{ d.NAME }}(CompoMe::Function_dbus_recv& msg, CompoMe::Return_dbus_send& reply){
  {{d.TYPE.D_NAME}} set_val;
  {%if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
  import_struct(msg, set_val);
  {%else%}
  msg >> set_val;
  {%endif%}

  try {
    this->comp.set_{{d.NAME}}(set_val);
  } catch (const CompoMe::Error &e) {
     std::stringstream ss;
     ss << "!" << &e;
     reply << ss.str();
  }

  return true;
}
{% endfor %}
{% include "helper/namespace_open.hpp" with context%}
