#include "Links/Link.hpp"

namespace CompoMe {

Link::Link() {}

Link::~Link() noexcept {}

void Link::step() {}

void Link::connect() {}

void Link::configuration() {}

void Link::disconnect() {}

void Link_in::set_in(Interface *pto) { this->a_c = pto->get_caller_stream(); }
bool Link_in::connected() { return a_c != NULL; }
Caller_stream &Link_in::get_caller_stream() { return *a_c; }

void Link_out::set_out(Require_helper &p_re) { this->a_re = &p_re; }

void Link_array_in::set_in(unsigned int p_id, Interface *pto) {
  // this->a_c[p_id] = pto->get_caller();
  this->a_c.push_back(pto->get_caller_stream());
  return;
}

void Link_array_out::set_out(unsigned int p_id, Require_helper &re) {
  this->a_f.push_back(&re);
  return;
}

void Link_map_in::set_in(std::string p_key, Interface *pto) {
  this->a_c[p_key] = pto->get_caller_stream();
  return;
}

void Link_map_out::set_out(std::string p_key, Require_helper &re) {
  this->a_f[p_key] = &re;
  // return;
}

} // namespace CompoMe
