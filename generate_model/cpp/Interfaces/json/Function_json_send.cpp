#include "Interfaces/Function_json_send.hpp"

namespace CompoMe {

Serialization_context_export &
Function_json_send::get_ctx() {
  return ctx;
};
  nlohmann::json &Function_json_send::get_data() { return this->data; }
  void Function_json_send::set_function(std::string str){
    this->get_data()["function"] = str;
  }
}  // CompoMe
