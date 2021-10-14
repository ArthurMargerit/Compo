#include "Structs/{{F_NAME}}.hpp"
#include "CompoMe/Log.hpp"
#include "Serialization_context.hpp"
#include "json.hpp"
#include <string>

{%include "helper/namespace_open.hpp" with context %}

namespace {
  constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}
} // namespace


void {{NAME}}::to_json(nlohmann::json &os,
            CompoMe::Serialization_context_export &p_ctx) const {
  os["addr"] = (uint64_t)this;
  os["type"] = "{{NAME}}";
  {% if PARENT %}
  {{ PARENT.NAME }}::to_json(os["parent"], p_ctx);
  {% endif %}

  {% for i_d in DATA %}
  {% if Function.model_test.is_struct(i_d.TYPE.D_NAME, MAIN) %}
  this->{{i_d.NAME}}.to_json(os["{{i_d.NAME}}"],p_ctx);
  {% else %}
  os["{{i_d.NAME}}"] = this->{{i_d.NAME}};
    {% endif %}
  {% endfor %}
}

void {{NAME}}::from_json(const nlohmann::json &is,
              CompoMe::Serialization_context_import &p_ctx) {

  for (nlohmann::json::const_iterator it = is.begin(); it != is.end(); ++it) {
    switch(str2int(it.key().c_str())) {
          case str2int("addr"):{
            int64_t t = it.value().get<int64_t>();
            // TODO
            break;
          }

         {% if PARENT %}
          case str2int("parent"):{
            {{PARENT.D_NAME}}::from_json(it.value(), p_ctx);
           break;
         }
         {%endif%}

          case str2int("type"):{
            if(it.value().get<std::string>() != "{{NAME}}") {
              throw "wrong type \"{{NAME}}\" != \"" +
                  it.value().get<std::string>() + "\"";
            }
            break;
          }

          {% for i_d in DATA %}
          case str2int("{{i_d.NAME}}"): {
             {% if Function.model_test.is_struct(i_d.TYPE.D_NAME, MAIN) %}
             this->{{i_d.NAME}}.from_json(it.value(), p_ctx);
             {% else %}
             this->{{i_d.NAME}} = it.value().get<{{i_d.TYPE.D_NAME}}>();
             {% endif %}
             break;
          }
          {% endfor %}

          default: {
            C_ERROR("wrong attribute: \"", it.key() ,"\" not in struct {{NAME}}");
            throw "wrong attribute";
                break;
           }
    }
  }
}

{% include "helper/namespace_close.hpp" with context %}
