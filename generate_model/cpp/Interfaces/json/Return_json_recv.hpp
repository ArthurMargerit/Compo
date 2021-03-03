#pragma once

#include <json.hpp>
#include "Serialization_context.hpp"
namespace CompoMe {

class Struct;

class Return_json_recv {
  nlohmann::json data;
  Serialization_context_import ctx;
public :
  nlohmann::json &get_data();
  Serialization_context_import &get_ctx();

  virtual void pull() = 0;
  virtual void end() = 0;
};

} // namespace CompoMe
