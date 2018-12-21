#pragma once

#include "Links/Link.hpp"
#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"


#include <fstream>
#include <thread>
#include <mutex>

class Fifo_in : public Link, public Link_to
{

public:

  Fifo_in();

  virtual ~Fifo_in();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

// DATA ////////////////////////////////////////////////////////////////////


  string req;
  std::ofstream ofs;

  string res;
  std::ifstream ifs;


  std::thread t;
  std::mutex mutex_in;;

// Get and set /////////////////////////////////////////////////////////////

  virtual
  string get_req() const {
    return req;
  }

  virtual
  void set_req(const string req) {
    this->req = req;
  }
  virtual
  string get_res() const {
    return res;
  }

  virtual
  void set_res(const string res) {
    this->res = res;
  }

  virtual  void set_to(Interface* to);

private:
  Interface* to;

};
