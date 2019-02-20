#pragma once

#include "Links/Link.hpp"
#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"

class Http_client : public Link

  ,public Link_from



{

public:

  Http_client();

  virtual ~Http_client();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

// DATA ////////////////////////////////////////////////////////////////////

 string addr;


// Get and set /////////////////////////////////////////////////////////////

virtual
string get_addr() const ;

virtual
  void set_addr(const string addr);





virtual  void set_from(Interface** from);



};