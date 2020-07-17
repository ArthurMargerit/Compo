#pragma once

#include "Components/Require_helper.hpp"
#include "Components/Require_helper_multi.hpp"

#include "Serialization_context.hpp"

namespace CompoMe {
class Component : public Serializable_Item {
public:
  Component();
  virtual ~Component();

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void step();
  virtual void stop();
  virtual void status();
};
} // namespace CompoMe