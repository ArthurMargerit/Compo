#pragma once

#include "Links/Link.hpp"

class Function_stream;
class Return_stream;
class Interface;

#include "Data/code.hpp"

#include <functional>

class S_in_fifo : public Link, public Link_in {
public:
  S_in_fifo();
  virtual ~S_in_fifo();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // Get and set /////////////////////////////////////////////////////////////

  virtual string get_path_in() const;
  virtual void set_path_in(const string path_in);
  virtual string get_path_out() const;
  virtual void set_path_out(const string path_out);

private:
  // DATA ////////////////////////////////////////////////////////////////////

  string path_in;
  string path_out;
  int fi;
  int fo;

  void fifo_open_out();
  void fifo_open_in();

};
