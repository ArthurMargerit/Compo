#pragma once

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

// basic String convertion ////////////////////////////////////////////////////
class Function_string_stream_send : public Function_stream_send {
public:
  std::ostream &_os;
  Function_string_stream_send(std::ostream &os) : _os(os) {}
  void start() override {}
  void send() override {}
  std::ostream &get_so() override { return this->_os; }
};

class Return_string_stream_recv : public Return_stream_recv {
public:
  std::istream &_is;
  Return_string_stream_recv(std::istream &is) : _is(is) {}
  void pull() override {}
  void end() override {}
  std::istream &get_si() override { return this->_is; }
};

class Return_string_stream_send : public Return_stream_send {
public:
  std::ostream &_os;
  Return_string_stream_send(std::ostream &os) : _os(os) {}
  void start() override {}
  void send() override {}
  std::ostream &get_so() override { return this->_os; }
};

class Function_string_stream_recv : public Function_stream_recv {
public:
  std::istream &_is;
  Function_string_stream_recv(std::istream &is) : _is(is) {}
  void pull() override {}
  void end() override {}
  std::istream &get_si() override { return this->_is; }
};
