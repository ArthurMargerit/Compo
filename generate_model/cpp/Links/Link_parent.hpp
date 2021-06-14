#pragma once

#include "Types/CompoMe/String.hpp"


namespace CompoMe {
  class Require_helper;
  class Interface;

class Link {
public:
  virtual void step();
  virtual void configuration();

  virtual void main_connect();
  virtual void main_disconnect();

  virtual void one_connect(CompoMe::Require_helper&, CompoMe::String)=0;
  virtual void one_disconnect(CompoMe::Require_helper &, CompoMe::String)=0;

  virtual void one_connect(CompoMe::Interface&, CompoMe::String)=0;
  virtual void one_disconnect(CompoMe::Interface&, CompoMe::String)=0;

public:
  Link();
  virtual ~Link() noexcept;
};

} // namespace CompoMe
