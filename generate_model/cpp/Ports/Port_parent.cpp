#include "Ports/Port.hpp"

namespace CompoMe {
  Port::Port():i_link(nullptr){}

  Port::Port(CompoMe::Link& p_link):i_link(&p_link) {}

  Port::~Port() {}

  CompoMe::Link& Port::get_link() {
    return *this->i_link;
  }

  void Port::set_link(CompoMe::Link& p_link) {
    this->i_link = &p_link;
  }
}  // CompoMe
