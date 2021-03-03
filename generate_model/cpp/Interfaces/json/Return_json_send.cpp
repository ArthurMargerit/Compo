#include "Interfaces/Return_json_send.hpp"
#include "Structs/Struct.hpp"

namespace CompoMe {
void export_struct(Return_json_send &s, Struct &e) {
  //  e.to_stream(s.get_so(), s.get_ctx());
}
  nlohmann::json &Return_json_send::get_data() {
    return this->data;
  }

  Serialization_context_export &Return_json_send::get_ctx() {
    return this->ctx;
  }

} // namespace CompoMe
