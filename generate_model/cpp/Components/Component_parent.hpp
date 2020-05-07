#pragma once
#include "Components/Require_helper.hpp"
#include "Components/Require_helper_multi.hpp"

class Serialization_context_export;
class Serialization_context_import;

class Component {
public:
  Component();
  virtual ~Component();

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void step();
  virtual void stop();
  virtual void status();

  virtual std::ostream& to_stream(std::ostream& os, Serialization_context_export& p_ctx) const =0;
  virtual std::istream& from_stream(std::istream& is, Serialization_context_import& p_ctx) =0;
};
