#include "Links/S_in_fifo/S_in_fifo.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Return_stream.hpp"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

S_in_fifo::S_in_fifo() : Link() {}

S_in_fifo::~S_in_fifo() {}

void S_in_fifo::step() {
  Link::step();

  int l_r = read(this->fdi, &this->buffer[this->i], 1024 - this->i);

  if (l_r == 0) {
    // std::cout << "No client"
    //           << "\n";
    return;
  }

  if (l_r == -1) {
    // std::cout << "No message"
    //           << "\n";
    return;
  }

  this->i = this->i + l_r;
  if (this->i == 1024) {

  }
  this->buffer[this->i] = '\0';
  if (this->buffer[this->i - 1] != '\n') {
    // std::cout << this->buffer << ":" << this->i << std::endl;
    // std::cout << "not end"
    //           << "\n";
  } else {

    Function_string_stream fss(
        [](std::stringstream &) {},
        [this](std::stringstream &i) { i.str(this->buffer); });

    Return_string_stream rss([](std::stringstream &os) { os.str(); },
                             [this](std::stringstream &os) {
                               write(this->fdo, os.str().c_str(),
                                     os.str().length());
                               write(this->fdo, "\n", 1);
                             });

    this->get_caller().call(fss, rss);
    this->i = 0;
  }
}

void S_in_fifo::connect() {
  Link::connect();
  std::cout << "connect\n";
  if (0 != access(this->get_path_in().c_str(), O_RDONLY)) {
    std::cout << "create fifo in"
              << "\n";
    mkfifo(this->get_path_in().c_str(), S_IRUSR | S_IWUSR);
  }

  if (0 != access(this->get_path_out().c_str(), O_RDONLY)) {
    std::cout << "create fifo out"
              << "\n";
    mkfifo(this->get_path_out().c_str(), S_IRUSR | S_IWUSR);
  }

  this->fdi = open(this->get_path_in().c_str(), O_RDONLY | O_NONBLOCK);
  if (this->fdi == -1) {
    std::cerr << "no in" << strerror(errno)
              << "\n";
  }

  this->fdo = open(this->get_path_out().c_str(), O_WRONLY);
  if (this->fdo == -1) {
    std::cerr << "no out" << strerror(errno)
              << "\n";
  }

  std::cout << "ok"
            << "\n";
}

void S_in_fifo::disconnect() {
  Link::disconnect();
  std::cout << "disconnect\n";
  close(this->fdo);
  close(this->fdi);
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
