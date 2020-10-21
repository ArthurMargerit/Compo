#pragma once

#include "Links/Link.hpp"

// TYPES

#include "Types/CompoMe/String.hpp"

#include "Types/i32.hpp"

#include "Types/ui32.hpp"
// STRUCT

namespace CompoMe {
class Function_stream;
class Return_stream;
class Interface;
} // namespace CompoMe

#include "Data/CompoMe_Http.hpp"

#include <functional>

namespace CompoMe {

namespace Posix {

class HttpV2_server_in : public CompoMe::Link,
                         public CompoMe::Link_in,
                         public CompoMe::Link_map_in {
public:
  HttpV2_server_in();
  virtual ~HttpV2_server_in();

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
  virtual ui32 get_max_client() const;
  virtual void set_max_client(const ui32 max_client);
  ui32 &a_max_client();
  virtual ui32 get_max_request_size() const;
  virtual void set_max_request_size(const ui32 max_request_size);
  ui32 &a_max_request_size();

public:
  // Function
  // ///////////////////////////////////////////////////////////////////
private:
  // DATA ////////////////////////////////////////////////////////////////////

  CompoMe::String addr;

  i32 port;

  ui32 max_client;

  ui32 max_request_size;
};

} // namespace Posix

} // namespace CompoMe
