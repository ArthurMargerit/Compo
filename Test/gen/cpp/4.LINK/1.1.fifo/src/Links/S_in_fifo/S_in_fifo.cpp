#include "Links/S_in_fifo/S_in_fifo.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Return_stream_send.hpp"
#include "Links/fdstream.hpp"

#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

S_in_fifo::S_in_fifo() : Link() {}

S_in_fifo::~S_in_fifo() {}

class Function_stream_recv_str : public Function_stream_recv {
  std::fdistream is;

public:
  Function_stream_recv_str(int fd) : is(fd) {}

  void pull() override {}
  void end() override {}

  std::istream &get_si() override { return this->is; }
};

class Return_stream_send_str : public Return_stream_send {
  std::fdostream os;

public:
  Return_stream_send_str(int fd) : os(fd) {}

  void start() override {}
  void send() override {}

  std::ostream &get_so() override { return this->os; }
};

void S_in_fifo::step() {
  Link::step();

  if (!this->connected()) {
    return;
  }

  // if someone wait a respond
  if (this->fo == -1) {
    this->fifo_open_out();
    if (this->fo == -1) {
      return;
    }
  } else {
    // err
    std::cerr << "wrong state";
  }

  // respond
  Function_stream_recv_str is(this->fi);
  Return_stream_send_str os(this->fo);
  this->get_caller().call(is, os);

  close(this->fo);
  this->fo = -1;
}

void S_in_fifo::fifo_open_in() {
  this->fi = open(this->get_path_in().c_str(), O_RDONLY | O_NONBLOCK);
  if (this->fi == -1) {
    std::cerr << "Error: in file open " << this->get_path_in() << "\n";
    throw "FIFO open read";
  } else {
    std::cout << "Connection Open " << this->get_path_in() << "\n";
  }
}

void S_in_fifo::fifo_open_out() {
  this->fo = open(this->get_path_out().c_str(), O_WRONLY | O_NONBLOCK);
  if (this->fo == -1) {
    std::cout << "Wait Client ... " << this->get_path_out() << "\n";
  } else {
    std::cout << "Client Connected " << this->get_path_out() << "\n";
  }
}

void S_in_fifo::connect() {
  Link::connect();

  if (access(this->get_path_in().c_str(), F_OK) == -1) {
    std::cerr << "file access " << this->get_path_in() << "\n";
    mkfifo(this->get_path_in().c_str(), 0600);
  }

  if (access(this->get_path_out().c_str(), F_OK) == -1) {
    std::cerr << "file access " << this->get_path_out() << "\n";
    mkfifo(this->get_path_out().c_str(), 0600);
  }

  fifo_open_out();
  fifo_open_in();
}

void S_in_fifo::disconnect() {
  Link::disconnect();

  if (this->fi != -1) {
    close(this->fi);
  }

  if (this->fo != -1) {
    close(this->fo);
  }
}

// Get and set /////////////////////////////////////////////////////////////

string S_in_fifo::get_path_in() const { return this->path_in; }

void S_in_fifo::set_path_in(const string p_path_in) {
  this->path_in = p_path_in;
}
string S_in_fifo::get_path_out() const { return this->path_out; }

void S_in_fifo::set_path_out(const string p_path_out) {
  this->path_out = p_path_out;
}
