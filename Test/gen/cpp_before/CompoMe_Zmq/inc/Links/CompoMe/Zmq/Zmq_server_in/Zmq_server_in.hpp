#pragma once

#include "Links/Link.hpp"

namespace CompoMe {
class Function_stream;
class Return_stream;
class Interface;
} // namespace CompoMe

#include "Data/CompoMe_Zmq.hpp"

#include <functional>

namespace CompoMe {

namespace Zmq {

class Zmq_server_in : public CompoMe::Link, public CompoMe::Link_in {
public:
  Zmq_server_in();
  virtual ~Zmq_server_in();

  void step() override;
  void connect() override;
  void disconnect() override;

  // Get and set /////////////////////////////////////////////////////////////

public:
  // Function
  // ///////////////////////////////////////////////////////////////////

  virtual void bind(CompoMe::String addr);

  virtual void unbind(CompoMe::String addr);

private:
  void *a_context;
  void *a_responder;
  CompoMe::String a_addr;

  // DATA ////////////////////////////////////////////////////////////////////
};

} // namespace Zmq

} // namespace CompoMe
