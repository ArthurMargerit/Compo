#pragma once

#include "Events/Event.hpp"
#include <regex>
#include <string>

namespace CompoMe {

  class Bus;
  class Emit;
  enum BUS_EMIT {
    RECEIVER = 0,
    EMITTER = 1
  };

  union r_e{
    CompoMe::Bus* bus_r;
    CompoMe::Emit* bus_e;
  };

  struct Bus_match {
    r_e bus;
    BUS_EMIT kind_in_union;
    std::string origin_match;
    std::string destination_match;
  };

  class Emit {
  private:
    std::vector<Bus_match> b;
    std::string name;

  public:
    Emit(std::string p_name= "");
    void inscribe(CompoMe::Bus* p_b, std::string origin_match=".*",std::string destination_match=".*");
    void inscribe(CompoMe::Emit* p_b, std::string origin_match=".*",std::string destination_match=".*");
    void push(CompoMe::Event* e);
  };

  class Bus
  {
  protected:
    CompoMe::Emit internal_emit;

  public:
    Bus();
    virtual ~Bus();
    virtual void process() = 0;
    virtual void m(CompoMe::Event*) = 0;
    virtual void push(CompoMe::Event*) = 0;
    void inscribe(CompoMe::Bus *e);
    void inscribe(CompoMe::Emit *e);
  };

}  // CompoMe
