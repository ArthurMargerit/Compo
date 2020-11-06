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

#include "Data/CompoMe_Https.hpp"

namespace CompoMe {

namespace Posix {

class Https_client_out : public CompoMe::Link, public CompoMe::Link_out {
public:
  Https_client_out();
  virtual ~Https_client_out();

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
  virtual CompoMe::String get_to_component() const;
  virtual void set_to_component(const CompoMe::String to_component);
  CompoMe::String &a_to_component();
  virtual CompoMe::String get_to_interface() const;
  virtual void set_to_interface(const CompoMe::String to_interface);
  CompoMe::String &a_to_interface();
  virtual CompoMe::String get_trust_cert() const;
  virtual void set_trust_cert(const CompoMe::String trust_cert);
  CompoMe::String &a_trust_cert();

public:
  // Function
  // ///////////////////////////////////////////////////////////////////
private:
  // DATA ////////////////////////////////////////////////////////////////////

  CompoMe::String addr;

  i32 port;

  CompoMe::String to_component;

  CompoMe::String to_interface;

  CompoMe::String trust_cert;
};

} // namespace Posix

} // namespace CompoMe
