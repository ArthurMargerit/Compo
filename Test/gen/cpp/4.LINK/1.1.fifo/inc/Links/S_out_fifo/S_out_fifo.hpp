#pragma once

#include "Data/code.hpp"
#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Return_stream_send.hpp"
#include "Links/Link.hpp"
#include "Links/fdstream.hpp"

#include <functional>

#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

class S_out_fifo;

class Function_stream_send_fifo : public Function_stream_send {
  std::fdostream os;

public:
  Function_stream_send_fifo() : os(-1){};

  void start() override {}
  void send() override {}

  std::ostream &get_so() override { return this->os; }

  void set_fd(int ifd) { this->os = std::fdostream(ifd); }
};

class Return_stream_recv_fifo : public Return_stream_recv {
  std::fdistream is;
  int fd = 1;
  S_out_fifo &link;

public:
  Return_stream_recv_fifo(S_out_fifo &p_link);
  void pull() override;
  void end() override;
  std::istream &get_si() override { return this->is; }
};

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

  int ofd;
  int ifd;
  Fake *f;
  Function_stream_send_fifo fss;
  Return_stream_recv_fifo rsr;
};
