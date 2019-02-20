#pragma once

#include "Links/Link.hpp"
#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"

class Mem_zone : public Link


,public Link_to


{

public:

  Mem_zone();

  virtual ~Mem_zone();

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




virtual  void set_to(Interface* to);




};