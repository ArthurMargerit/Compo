#include "Links/Link.hpp"

Link::Link() {}

Link::~Link() noexcept {}

void Link::step() {}

void Link::connect() {}

void Link::disconnect() {}

void Link_in::set_in(Interface *pto) {}
void Link_out::set_out(Fake *p_f) {}
void Link_array_in::set_in(unsigned int p_id, Interface *pto) {}
void Link_array_out::set_out(unsigned int p_id, Fake *p_f) {}
void Link_map_in::set_in(std::string p_key, Interface *pto) {}
void Link_map_out::set_out(std::string p_key, Fake *p_f) {}

// void pass::set_build_f(Build_fake_F p_build_f) { this->build_f = p_build_f; }