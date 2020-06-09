#include "Links/S_out_fifo/S_out_fifo.hpp"

#include "Interfaces/Interface.hpp"

S_out_fifo::S_out_fifo() : Link(), rsr(*this) {}

S_out_fifo::~S_out_fifo() {}

void S_out_fifo::step() { Link::step(); }

void S_out_fifo::connect() {
  Link::connect();

  ofd = open(this->get_path_out().c_str(), O_WRONLY | O_NONBLOCK);
  if (ofd == -1) {
    std::cout << "No server " << this->get_path_out() << " err:" << errno << "("
              << strerror(errno) << ")"
              << "\n";
    return;
  }

  this->fss.set_fd(this->ofd);

  // have to be free
  this->f = this->a_re->fake_it(fss, rsr);
}

void S_out_fifo::disconnect() {
  Link::disconnect();
  this->a_re->disconnect_it();

  if (this->ofd == -1) {
    return;
  }

  close(this->ofd);
  this->ofd = -1;
  this->fss.set_fd(-1);

  delete this->f;
}

// Get and set /////////////////////////////////////////////////////////////

string S_out_fifo::get_path_in() const { return this->path_in; }

void S_out_fifo::set_path_in(const string p_path_in) {
  this->path_in = p_path_in;
}
string S_out_fifo::get_path_out() const { return this->path_out; }

void S_out_fifo::set_path_out(const string p_path_out) {
  this->path_out = p_path_out;
}

Return_stream_recv_fifo::Return_stream_recv_fifo(S_out_fifo &p_link)
    : is(-1), link(p_link) {}

void Return_stream_recv_fifo::pull() {
  fd = open(this->link.get_path_in().c_str(), O_RDONLY);
  this->is = std::fdistream(this->fd);
}

void Return_stream_recv_fifo::end() {
  close(fd);
}
