#pragma once

#include <string>

#include "Serialization_context.hpp"
#include <exception>

namespace CompoMe {
  class Error : public Serializable_Item, public std::exception {
public:
  Error();
  virtual ~Error();
  virtual std::string what_s() const;
  const char *what() const noexcept override { return this->what_s().c_str(); }
  virtual void real() = 0;
};
} // namespace CompoMe
