#pragma once

#include <string>

#include "Serialization_context.hpp"

namespace CompoMe {
class Error : public Serializable_Item {
public:
  Error();
  virtual ~Error();
  virtual std::string what();
  virtual void real() = 0;
};
} // namespace CompoMe