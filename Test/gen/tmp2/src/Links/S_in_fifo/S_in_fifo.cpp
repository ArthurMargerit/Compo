#include "Links/S_in_fifo/S_in_fifo.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Return_stream.hpp"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

S_in_fifo::S_in_fifo() : Link() {}

S_in_fifo::~S_in_fifo() {}

void S_in_fifo::step() {
  Link::step();

  int l_r = read(this->fdi, &this->buffer[this->i], 1024 - this->i);

  if (l_r == 0) {
    std::cout << "No client"
              << "\n";
    return;
  }

  if (l_r == -1) {
    std::cout << "No message"
              << "\n";
    return;
  }

  this->i = this->i + l_r;
  this->buffer[this->i] = '\0';
  if (this->buffer[this->i - 1] != '\n') {
    std::cout << this->buffer << ":" << this->i << std::endl;
    std::cout << "not end"
              << "\n";
  } else {

    Function_string_stream fss(
        [](std::stringstream &) {},
        [this](std::stringstream &i) { i.str(this->buffer); });
    Return_string_stream rss([](std::stringstream &) {},
                             [this](std::stringstream &os) {
                               write(this->fdo, os.str().c_str(),
                                     os.str().length());
                             });
    std::cout << this->buffer << ":" << this->i << std::endl;
    std::cout << "call: " << this->get_caller().call(fss, rss) << "\n";
    this->i = 0;
  }
}

void S_in_fifo::connect() {
  Link::connect();
  std::cout << "connect\n";
  if (access(this->get_path_in().c_str(), S_IRUSR | S_IWUSR)) {
    std::cout << "a"
              << "\n";
    mkfifo(this->get_path_in().c_str(), S_IRUSR | S_IWUSR);
  }

  if (access(this->get_path_out().c_str(), S_IRUSR | S_IWUSR)) {
    std::cout << "b"
              << "\n";
    mkfifo(this->get_path_out().c_str(), S_IRUSR | S_IWUSR);
  }

  this->fdo = open(this->get_path_out().c_str(), O_WRONLY | O_NONBLOCK);
  this->fdi = open(this->get_path_in().c_str(), O_RDONLY | O_NONBLOCK);
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
