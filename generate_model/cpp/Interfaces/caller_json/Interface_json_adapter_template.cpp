#include "Interfaces/{{F_NAME}}//{{NAME}}_caller_json.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_json_recv.hpp"
#include "Interfaces/Return_json_send.hpp"

#include <regex>
#include <string>

{% include "helper/namespace_open.hpp" with context%}
constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

{{NAME}}_caller_json::{{NAME}}_caller_json({{D_NAME}}& pcomp)
:{%if PARENT -%}
{{PARENT.D_NAME}}_caller_json(pcomp)
{%- else -%}
CompoMe::Caller_json()
{%- endif%},comp(pcomp){}

void {{NAME}}_caller_json::introspection(std::ostream& ss) {

  nlohmann::json j;
  j["functions"] = nlohmann::json::array();
  j["data"] = nlohmann::json::array();

  {% for f in FUNCTION %}
  { // function {{f.NAME}}
    nlohmann::json j_func;
    j_func["type"] = "{{f.RETURN.NAME}}";
    j_func["name"] = "{{f.NAME}}";
    j_func["params"] = nlohmann::json::array();

    {% for fp in f.SIGNATURE  %}
    {
       nlohmann::json j_func_params;
       j_func_params["type"] =  "{{fp.TYPE.D_NAME}}";
       j_func_params["name"] =  "{{fp.NAME}}";
       j_func["params"].push_back(j_func_params);
    }
    {% endfor %}
    j["functions"].push_back(j_func);
  }
  {% endfor %}
  
  {% for d in DATA %}
   { // set {{d.NAME}}
    nlohmann::json j_f_set;
    j_f_set["return"] = "void";
    j_f_set["name"] = "set_{{d.NAME}}";
    j_f_set["params"] = nlohmann::json::array();
    j_f_set["params"][0]["type"] = "{{d.TYPE.NAME}}";
    j_f_set["params"][0]["name"] = "p_{{d.NAME}}";
    j["functions"].push_back(j_f_set);
  }
  { // get {{d.NAME}}
    nlohmann::json j_f_get;
    j_f_get["return"] = "{{d.TYPE.NAME}}";
    j_f_get["name"] = "get_{{d.NAME}}";
    j_f_get["params"] = nlohmann::json::array();
    j["functions"].push_back(j_f_get);
  }
  { // data 
    nlohmann::json j_data;
    j_data["type"] = "{{d.TYPE.NAME}}";
    j_data["name"] = "{{d.NAME}}";
    j["data"].push_back(j_data);
  }
  {% endfor %}

  ss << j;

  return;
}


bool {{NAME}}_caller_json::call(CompoMe::Function_json_recv& msg, CompoMe::Return_json_send& reply) {
  std::string name_function = msg.get_function();
  bool b = this->call(name_function, msg,reply);
  return b;
}



bool {{NAME}}_caller_json::call(std::string &name_function, CompoMe::Function_json_recv& msg, CompoMe::Return_json_send& reply) {
  bool result = false;

  switch(str2int(name_function.c_str())) {
    // Function
    {% for func in FUNCTION%}
    case str2int("{{func.NAME}}"):
       result = this->{{func.NAME}}(msg, reply);
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
       return {{PARENT.D_NAME}}_caller_json::call(name_function, msg, reply);
    break;
    {%endif%}
  };

  return result;
}

 {% for func in FUNCTION %}
bool {{NAME}}_caller_json::{{ func.NAME }}(CompoMe::Function_json_recv& msg, CompoMe::Return_json_send& reply){
    auto msg_params = msg.get_params();

    {% for arg in func.SIGNATURE -%}
    {{arg.TYPE.D_NAME}} l_{{arg.NAME}};
    {% endfor %}

    if(msg_params.is_object()) {
    {% for arg in func.SIGNATURE -%}
    {%if Function.model_test.is_struct(arg.TYPE.D_NAME, MAIN) -%}
    l_{{arg.NAME}}.from_json(msg_params["{{arg.NAME}}"], msg.get_ctx());
    {%else -%}
    l_{{arg.NAME}} = msg_params["{{arg.NAME}}"];
    {%endif -%}
    {% endfor %}
    } else if (msg_params.is_array()) {
    if( msg_params.size() == {{func.SIGNATURE.__len__()}}) {
    {% for arg in func.SIGNATURE -%}
    {%if Function.model_test.is_struct(arg.TYPE.D_NAME, MAIN) -%}
    l_{{arg.NAME}}.from_json(msg_params[{{func.SIGNATURE.index(arg)}}], msg.get_ctx());
    {%else -%}
    l_{{arg.NAME}} = msg_params[{{func.SIGNATURE.index(arg)}}];
    {%endif -%}
    {% endfor %}
    }
    } else {
    }

    try {
      {% if func.RETURN.NAME == "void" %}
      this->comp.{{ func.NAME }}(
        {% for arg in func.SIGNATURE -%}
        l_{{arg.NAME}} {%- if not loop.last %},{% endif %}
        {%- endfor %});
      {%else%}
        auto rep = this->comp.{{ func.NAME }}({% for arg in func.SIGNATURE -%}
        l_{{arg.NAME}}{%- if not loop.last %}, {% endif %}
        {%- endfor %});

        {%if Function.model_test.is_struct(func.RETURN.D_NAME, MAIN) %}
        rep.to_json(reply.get_data()["result"],reply.get_ctx());
        {%else%}
        reply.get_data()["result"] = rep;
        {%endif%}

      {% endif %}
    } catch (const CompoMe::Error &e) {
      e.to_json(reply.get_data()["error"], reply.get_ctx());
  }

  return true;
}
{% endfor %}

{% for d in DATA %}
bool {{NAME}}_caller_json::get_{{ d.NAME }}(CompoMe::Function_json_recv& msg, CompoMe::Return_json_send& reply){
 try {
   auto rep = this->comp.get_{{d.NAME}}();
   {%if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
   rep.to_json(reply.get_data()["params"],reply.get_ctx());
   {%else%}
   reply.get_data()["result"]=rep;
   {%endif%}

 } catch (const CompoMe::Error &e) {
   e.to_json(reply.get_data()["error"], reply.get_ctx());
 }

 return true;
}

bool {{NAME}}_caller_json::set_{{ d.NAME }}(CompoMe::Function_json_recv& msg, CompoMe::Return_json_send& reply){

  auto msg_params = msg.get_params();

  {{d.TYPE.D_NAME}} set_val;
  if(msg_params.is_object()) {
  {%if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
  set_val.from_json(msg_params["p_{{d.NAME}}"], msg.get_ctx());
  {%else%}
  msg_params["p_{{d.NAME}}"].get_to(set_val);
  {%endif%}
  } else if (msg_params.is_array()) {
  {%if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
  set_val.from_json(msg_params[0], msg.get_ctx());
  {%else%}
  msg_params[0].get_to(set_val);
  {%endif%}
  } else {

  }

  try {
    this->comp.set_{{d.NAME}}(set_val);
  } catch (const CompoMe::Error &e) {
    e.to_json(reply.get_data()["error"],reply.get_ctx());
  }

  return true;
}
{% endfor %}

{% include "helper/namespace_close.hpp" with context%}
