#include "Links/S_out_fifo/S_out_fifo.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Return_stream.hpp"
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

S_out_fifo::S_out_fifo()
    : Link(), fss(
                  [this](std::stringstream &p_s) {
                    write(this->fdo, p_s.str().c_str(), p_s.str().length());
                    write(this->fdo, "\n", 1);
                  },
                  [this](std::stringstream &p_s) {
                    p_s.str("");
                  }),
      rss(
          [this](std::stringstream &p_s) {
            char l_d[1024];
            int i = read(this->fdi, l_d, 1023);
            l_d[i] = '\0';
            if (i != -1) {
              p_s << l_d;
            } else {
              std::cerr << "no output";
              p_s << 0;
            }
          },
          [this](std::stringstream &p_s) {
          }) {}

S_out_fifo::~S_out_fifo() {}

void S_out_fifo::step() { Link::step(); }

void S_out_fifo::connect() {
  Link::connect();

  if (0 != access(this->get_path_out().c_str(), W_OK)) {
    std::cout << "access: " << this->get_path_out() << " is " << strerror(errno)
              << "\n";
    return;
  }

  if (0 != access(this->get_path_in().c_str(), R_OK)) {
    std::cout << "access: " << this->get_path_in() << " is " << strerror(errno)
              << "\n";
    return;
  }

  this->fdo = open(this->get_path_out().c_str(), O_WRONLY);
  if (this->fdo == -1) {
    std::cout << "open: " << this->get_path_out() << " is " << strerror(errno)
              << "\n";

    return;
  }

  this->fdi = open(this->get_path_in().c_str(), O_RDONLY);
  if (this->fdi == -1) {
    std::cout << "open: " << this->get_path_in() << " is " << strerror(errno)
              << "\n";

    return;
  }

  auto f = this->a_re->fake_it(this->fss,this->rss);

  return;
}

void S_out_fifo::disconnect() { Link::disconnect(); }

// Get and set /////////////////////////////////////////////////////////////

string S_out_fifo::get_path_in() const { return this->path_in; }

void S_out_fifo::set_path_in(const string p_path_in) {
  this->path_in = p_path_in;
}
string S_out_fifo::get_path_out() const { return this->path_out; }

void S_out_fifo::set_path_out(const string p_path_out) {
  this->path_out = p_path_out;
}
