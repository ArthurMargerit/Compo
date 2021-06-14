#pragma once

#include "Interfaces/Interface.hpp"
#include "Components/Require_helper.hpp"

namespace CompoMe {
  class Port
  {
  private:
    CompoMe::Link* i_link;

  public:
    Port();
    Port(CompoMe::Link& p_link);
    virtual ~Port();

    CompoMe::Link& get_link();
    void set_link(CompoMe::Link&);
  };
}  // CompoMe
