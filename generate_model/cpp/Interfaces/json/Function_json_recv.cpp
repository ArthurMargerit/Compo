#include "Interfaces/Function_json_recv.hpp"
#include "Structs/Struct.hpp"

namespace CompoMe {
void import_struct(CompoMe::Function_json_recv &s, Struct &e) {
  //  e.from_stream(s.get_si(), s.get_ctx());
}

  nlohmann::json& Function_json_recv::get_data(){
    return this->data;
  }

  void Function_json_recv::set_data(nlohmann::json &p_data ) {
     this->data = p_data;
   }

  std::string Function_json_recv::get_function(){
    return this->data["function"];
  }

  nlohmann::json &Function_json_recv::get_params() {
    return this->data["params"];
  }

  Serialization_context_import &Function_json_recv::get_ctx(){
    return this->ctx;
  }

} // namespace CompoMe
