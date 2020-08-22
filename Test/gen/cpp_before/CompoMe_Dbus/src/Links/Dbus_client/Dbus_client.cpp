#include "Links/Dbus_client/Dbus_client.hpp"

#include "Interfaces/Function_dbus_send.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Return_dbus_recv.hpp"

class Return_dbus_recv_i : public CompoMe::Return_dbus_recv {
  DBus::MessageIterator si;
  bool r;

public:
  DBus::PendingCall::pointer p;
  DBus::ReturnMessage::pointer rm;

  void pull() override {
    this->p->block();
    auto rm_s = this->p->steal_reply();

    this->rm = DBus::ReturnMessage::create(rm_s);
    this->r = true;
  }

  void end() override {}

  DBus::MessageIterator &get_si() override {
    if (this->r) {
      this->r = false;
      this->si = this->rm->begin();
    }
    return si;
  }
};

class Function_dbus_send_i : public CompoMe::Function_dbus_send {
private:
  DBus::CallMessage::pointer m;
  DBus::Connection::pointer connection;
  DBus::MessageAppendIterator ma;

  bool reset;
  Return_dbus_recv_i rs;

  std::string dest;
  std::string path;
  std::string interface;

public:
  Return_dbus_recv_i &get_rs() { return rs; }

  void set_interface(const std::string interface) {
    this->interface = interface;
  }

  void set_path(const std::string path) { this->path = path; }

  void set_dest(const std::string dest) { this->dest = dest; }

  Function_dbus_send_i(DBus::Connection::pointer p_connection)
      : connection(p_connection), rs() {}

  virtual ~Function_dbus_send_i() {}

  void set_function(std::string str) override { this->m->set_member(str); }

  DBus::MessageAppendIterator &get_so() override {
    if (this->reset) {
      this->ma = m->append();
      this->reset = false;
    }

    return ma;
  }

  void start() override {
    m = DBus::CallMessage::create();
    m->set_destination(this->dest);
    m->set_path(this->path);
    m->set_interface(this->interface);
    this->reset = true;
  }

  void send() override {
    this->rs.p = connection->send_with_reply_async(m, -1);
  }
};

Dbus_client::Dbus_client() : CompoMe::Link() {}

Dbus_client::~Dbus_client() {}

void Dbus_client::step() { Link::step(); }

void Dbus_client::connect() {
  Link::connect();
  if (!this->di) {
    this->di = DBus::Dispatcher::create();
    this->co = this->di->create_connection(DBus::BUS_SESSION);
  }

  for (auto &i_f : this->a_f) {
    if (!i_f.first->connected()) {
      this->connect(*i_f.first);
    }
  }
}

void Dbus_client::disconnect() {
  Link::disconnect();
  this->di = nullptr;
  this->co = nullptr;
  for (auto &i_f : this->function_dbus) {
    i_f.first->disconnect_it();
    free(i_f.second);
    // this->function_dbus.erase(i_f);
  }
}

void Dbus_client::connect(CompoMe::Require_helper &p_i) {
  auto data = this->a_f[&p_i];

  Function_dbus_send_i *fs = new Function_dbus_send_i(this->co);
  fs->set_dest(std::get<0>(data));
  fs->set_path(std::get<1>(data));
  fs->set_interface(std::get<2>(data));

  p_i.fake_dbus_it(*fs, fs->get_rs());
  this->function_dbus[&p_i] = fs;
}

void Dbus_client::disconnect(CompoMe::Require_helper &p_i) {
  p_i.disconnect_it();
  free(this->function_dbus[&p_i]);
  this->function_dbus.erase(&p_i);
}

// Get and set /////////////////////////////////////////////////////////////
CompoMe::String Dbus_client::get_object_name() const {
  return this->object_name;
}

void Dbus_client::set_object_name(const CompoMe::String p_object_name) {
  this->object_name = p_object_name;
}
i32 Dbus_client::get_timeout() const { return this->timeout; }

void Dbus_client::set_timeout(const i32 p_timeout) {
  this->timeout = p_timeout;
}
