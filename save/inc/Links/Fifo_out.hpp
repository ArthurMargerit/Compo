#pragma once

#include "Links/Link.hpp"
#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"

#include <functional>
#include <fstream>

class Fifo_out : public Link

  ,public Link_from



{

public:

  Fifo_out();

  virtual ~Fifo_out();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

// DATA ////////////////////////////////////////////////////////////////////


  string req;
  std::ifstream ifs;
  std::function<Interface*(std::ostream&,std::istream&)> build_f;

  string res;
  std::ofstream ofs;

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





virtual  void set_from(Interface** from);

private:
  Interface** from;
};
