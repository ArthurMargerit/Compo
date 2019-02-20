#pragma once

#include "Links/Link.hpp"
#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"

class Udp_client : public Link

  ,public Link_from



{

public:

  Udp_client();

  virtual ~Udp_client();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

// DATA ////////////////////////////////////////////////////////////////////

 string addr;

 uint port;


// Get and set /////////////////////////////////////////////////////////////

virtual
string get_addr() const ;

virtual
  void set_addr(const string addr);
virtual
uint get_port() const ;

virtual
  void set_port(const uint port);





virtual  void set_from(Interface** from);



};