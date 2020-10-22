#pragma once

#include "Links/Link.hpp"

namespace CompoMe {
class Function_stream;
class Return_stream;
class Interface;
} // namespace CompoMe

#include "Data/CompoMe_Tcp.hpp"

#include <functional>

namespace CompoMe {

namespace Posix {
class Http_client_out;
namespace Http_client_out_ns {
class Function_string_stream_send : public CompoMe::Function_stream_send {
private:
  std::stringstream a_ss;
  Http_client_out &a_l;

public:
  Function_string_stream_send(Http_client_out &p_l);
  void start() final;
  void send() final;
  std::ostream &get_so() override { return this->a_ss; }
};

class Return_string_stream_recv : public CompoMe::Return_stream_recv {
private:
  std::stringstream a_ss;
  Http_client_out &a_l;

public:
  Return_string_stream_recv(Http_client_out &p_l);
  void pull() final;
  void end() final;
  std::istream &get_si() override { return this->a_ss; }
};
} // namespace Http_client_out_ns

class Http_client_out : public CompoMe::Link, public CompoMe::Link_out {
public:
  Http_client_out();
  virtual ~Http_client_out();

  void step() override;
  void connect() override;
  void disconnect() override;

  // Get and set /////////////////////////////////////////////////////////////

  virtual CompoMe::String get_addr() const;
  virtual void set_addr(const CompoMe::String addr);
  virtual i32 get_port() const;
  virtual void set_port(const i32 port);
  virtual CompoMe::String get_to_component() const;
  virtual void set_to_component(const CompoMe::String to_component);
  virtual CompoMe::String get_to_interface() const;
  virtual void set_to_interface(const CompoMe::String to_interface);

public:
  int get_sock() { return this->sock; }
  // Function
  // ///////////////////////////////////////////////////////////////////
private:
  int sock;
  CompoMe::Fake_stream *f;
  Http_client_out_ns::Function_string_stream_send fss;
  Http_client_out_ns::Return_string_stream_recv rsr;

  // DATA ////////////////////////////////////////////////////////////////////

  CompoMe::String addr;

  i32 port;

  CompoMe::String to_component;

  CompoMe::String to_interface;
};

} // namespace Posix

} // namespace CompoMe