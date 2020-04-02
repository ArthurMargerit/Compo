#include "Links/Link.hpp"

Link::Link() {}

Link::~Link() noexcept {}

void Link::step() {}

void Link::connect() {}

void Link::configuration() {}

void Link::disconnect() {}

void Link_in::set_in(Interface *pto) { this->a_c = pto->get_caller(); }
bool Link_in::connected() { return a_c != NULL; }
Caller &Link_in::get_caller() { return *a_c; }

void Link_out::set_out(Interface ** p_i, Build_fake_F p_f) {
  this->a_i = p_i;
  this->a_f = p_f;
}

void Link_array_in::set_in(unsigned int p_id, Interface *pto) {
  this->a_c[p_id] = pto->get_caller();
  return;
}

void Link_array_out::set_out(unsigned int p_id, Interface** p_i, Build_fake_F p_f) {
  this->a_f[p_id] = std::make_pair(p_i,p_f);
  return;
}

void Link_map_in::set_in(std::string p_key, Interface *pto) {
  this->a_c[p_key] = pto->get_caller();
  return;
}

void Link_map_out::set_out(std::string p_key, Interface** p_i, Build_fake_F p_f) {
  this->a_f[p_key] = std::make_pair(p_i,p_f); // std::make_pair(p_i,p_f);
  // return;
}
