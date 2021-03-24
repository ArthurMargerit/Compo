#pragma once

#include "Links/Link.hpp"

// TYPES

#include "Types/CompoMe/String.hpp"

#include "Types/i32.hpp"

// STRUCT

namespace CompoMe {
class Function_stream;
class Return_stream;
class Interface;
} // namespace CompoMe

#include "Data/CompoMe_WebSocket.hpp"

namespace CompoMe {

namespace WebSocket {

class Server : public CompoMe::Link,
               public CompoMe::Link_map_out,
               public CompoMe::Link_map_in {
public:
  Server();
  virtual ~Server();

  void step() override;
  void connect() override;
  void disconnect() override;

  // Get and set /////////////////////////////////////////////////////////////

  virtual CompoMe::String get_addr() const;
  virtual void set_addr(const CompoMe::String addr);
  CompoMe::String &a_addr();
  virtual i32 get_port() const;
  virtual void set_port(const i32 port);
  i32 &a_port();
  virtual i32 get_maxConnection() const;
  virtual void set_maxConnection(const i32 maxConnection);
  i32 &a_maxConnection();
  virtual i32 get_Timeout() const;
  virtual void set_Timeout(const i32 Timeout);
  i32 &a_Timeout();
  virtual bool get_ping_auto() const;
  virtual void set_ping_auto(const bool ping_auto);
  bool &a_ping_auto();
  virtual i32 get_ping_interval() const;
  virtual void set_ping_interval(const i32 ping_interval);
  i32 &a_ping_interval();
  virtual bool get_ssl() const;
  virtual void set_ssl(const bool ssl);
  bool &a_ssl();
  virtual CompoMe::String get_to() const;
  virtual void set_to(const CompoMe::String to);
  CompoMe::String &a_to();
  virtual CompoMe::String get_ca_cert_file() const;
  virtual void set_ca_cert_file(const CompoMe::String ca_cert_file);
  CompoMe::String &a_ca_cert_file();

public:
  // Function
  // ///////////////////////////////////////////////////////////////////
protected:
  void connect(CompoMe::Require_helper &p_i) override;
  void disconnect(CompoMe::Require_helper &p_i) override;
private:
  // DATA ////////////////////////////////////////////////////////////////////

  CompoMe::String addr;

  i32 port;

  i32 maxConnection;

  i32 Timeout;

  bool ping_auto;

  i32 ping_interval;

  bool ssl;

  CompoMe::String to;

  CompoMe::String ca_cert_file;
};

} // namespace WebSocket

} // namespace CompoMe
