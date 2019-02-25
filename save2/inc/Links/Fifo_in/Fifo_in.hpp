#pragma once

#include "Links/Link.hpp"
#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"

#include <fstream>
#include <functional>
#include <thread>
#include <mutex>


class Fifo_in : public Link


,public Link_to


{

public:

  Fifo_in();

  virtual ~Fifo_in();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

// DATA ////////////////////////////////////////////////////////////////////

 string fifo;


// Get and set /////////////////////////////////////////////////////////////

virtual
string get_fifo() const ;

virtual
  void set_fifo(const string fifo);




virtual  void set_to(Interface* to);

private:
  Interface* to;

  std::thread t;
  std::mutex mutex_in;
  std::ofstream ofs;
  std::ifstream ifs;

};
