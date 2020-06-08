#pragma once

#include "Links/Link.hpp"

class Function_stream;
class Return_stream;
class Interface;

#include "Data/code.hpp"

#include <functional>

class S_out_fifo : public Link, public Link_out {
public:
  S_out_fifo();
  virtual ~S_out_fifo();

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
};
