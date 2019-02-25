#pragma once

#include "Links/Link.hpp"
#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"

class Mem_client : public Link

  ,public Link_from



{

public:

  Mem_client();

  virtual ~Mem_client();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

// DATA ////////////////////////////////////////////////////////////////////

 string file;


// Get and set /////////////////////////////////////////////////////////////

virtual
string get_file() const ;

virtual
  void set_file(const string file);





virtual  void set_from(Interface** from);



};