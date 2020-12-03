#pragma once

#include "CompoMe/Events/Event.hpp"

namespace CompoMe {
  class Bus
  {
  protected:
    CompoMe::Emit internal_emit;

  public:
    void inscribe(CompoMe::Bus *e) {
      this->internal_emit.inscribe(e);
    }

    Bus(){}
    virtual ~Bus(){}
    void process() = 0;
    void m(CompoMe::Event*) = 0;
  };
}  // CompoMe
