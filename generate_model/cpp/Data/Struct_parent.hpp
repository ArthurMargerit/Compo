#pragma once

#include <istream>
#include <memory>
#include <ostream>
#include <utility>
#include <vector>

#include "Serialization_context.hpp"

struct Struct : public Serializable_Item {
  Struct ();
  virtual ~Struct();
};
