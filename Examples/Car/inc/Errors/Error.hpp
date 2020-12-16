#pragma once

#include <string>

#include "Serialization_context.hpp"
#include <exception>

namespace CompoMe {
class Error : public Serializable_Item, public std::exception {
private:
  std::string what_s() const;

protected:
  std::string bs;

public:
  Error();
  virtual ~Error();

  const char *what() const noexcept override { return this->bs.c_str(); }
  virtual void real() = 0;
};
} // namespace CompoMe