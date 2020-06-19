#pragma once

#include <istream>
#include <memory>
#include <ostream>
#include <utility>
#include <vector>

#include "Serialization_context.hpp"

class Struct : public Serializable_Item {
public:
  Struct();
  virtual ~Struct();
};