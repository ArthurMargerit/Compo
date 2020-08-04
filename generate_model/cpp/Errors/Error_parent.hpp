#pragma once

#include <string>

#include "Serialization_context.hpp"
#include <exception>

namespace CompoMe {
  class Error : public std::exception,public Serializable_Item {
public:
  Error();
  virtual ~Error();
  virtual std::string what();
  virtual void real() = 0;
};
} // namespace CompoMe
