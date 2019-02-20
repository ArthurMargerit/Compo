#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

#include <fstream>
#include <functional>

class Fifo_out : public Link,
                 public Link_from

{

public:
  Fifo_out();

  virtual ~Fifo_out();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

  string fifo;

  // Get and set /////////////////////////////////////////////////////////////

  virtual string get_fifo() const;

  virtual void set_fifo(const string fifo);

  virtual void set_from(Interface **from);

  std::function<Interface *(std::ostream &, std::istream &)> build_f;
private:
  std::ofstream ofs;
  std::ifstream ifs;
  Interface **from;

};
