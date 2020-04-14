#include "Links/S_out_fifo/S_out_fifo.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Return_stream.hpp"

S_out_fifo::S_out_fifo() : Link() {}

S_out_fifo::~S_out_fifo() {}

void S_out_fifo::step() { Link::step(); }

void S_out_fifo::connect() { Link::connect(); }

void S_out_fifo::disconnect() { Link::disconnect(); }

// Get and set /////////////////////////////////////////////////////////////

string S_out_fifo::get_path_in() const { return this->path_in; }

void S_out_fifo::set_path_in(const string p_path_in) {
  this->path_in = p_path_in;
}
string S_out_fifo::get_path_out() const { return this->path_out; }

void S_out_fifo::set_path_out(const string p_path_out) {
  this->path_out = p_path_out;
}
