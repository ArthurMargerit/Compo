#include "Interfaces/Return_json_recv.hpp"
#include "Serialization_context.hpp"

namespace CompoMe {
  Return_json_recv &operator>>(Return_json_recv &s, Struct &e) { return s; }
  nlohmann::json &Return_json_recv::get_data(){return this->data;}
  Serialization_context_import &Return_json_recv::get_ctx() { return ctx; };
} // namespace CompoMe
