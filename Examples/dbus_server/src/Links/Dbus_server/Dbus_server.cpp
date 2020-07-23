#include "Links/Dbus_server/Dbus_server.hpp"

#include "Interfaces/Function_dbus_recv.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Return_dbus_send.hpp"

class Function_dbus_recv_i : public CompoMe::Function_dbus_recv {

  CompoMe::Serialization_context_import ctx;
  DBus::CallMessage::pointer mc;
  DBus::MessageIterator _it;
  bool r;

public:
  Function_dbus_recv_i(DBus::CallMessage::pointer msg) : mc(msg), r(true) {}
  void pull() override {}
  void end() override {}

  std::string get_function() override { return this->mc->member(); }

  DBus::MessageIterator &get_si() override {
    if (this->r == true) {
      this->_it = this->mc->begin();
      this->r = false;
    }

    return _it;
  }

  CompoMe::Serialization_context_import &get_ctx() override { return this->ctx; }

  void reset() {
    this->mc = DBus::CallMessage::create();
    this->r = true;
  }
};

class Return_dbus_send_i : public CompoMe::Return_dbus_send {
  CompoMe::Serialization_context_export ctx;
  DBus::ReturnMessage::pointer ret;
  DBus::MessageAppendIterator _a_it;

  bool r;
public:
  Return_dbus_send_i(DBus::ReturnMessage::pointer p_r) : ret(p_r),r(true) {}

  void start() override {}
  void send() override {}

  DBus::MessageAppendIterator &get_so() override {
    if (this->r) {
      this->_a_it = this->ret->append();
      this->r = false;
    }

    return _a_it;
  }

  CompoMe::Serialization_context_export &get_ctx() override { return ctx; }
};

Dbus_server::Dbus_server() : Link() {
  static bool f = true;
  if (f == true) {
    DBus::init();
    f = false;
  }
}

class mstring : public std::string {

public:
  mstring() : std::string("") {}
  mstring(std::string s) : std::string(s) {}
  mstring &operator=(int a) {
    std::string("");
    return *this;
  }
};

Dbus_server::~Dbus_server() {}

void Dbus_server::step() {
  Link::step();
  DBus::Message::pointer msg;

  Link::step();

  conn->read_write(0);
  msg = conn->pop_message();

  if (not msg) {
    return;
  }

  if (msg->type() == DBus::CALL_MESSAGE) {
    DBus::CallMessage::pointer msgc;
    DBus::ReturnMessage::pointer reply;

    msgc = DBus::CallMessage::create(msg);
    reply = msgc->create_reply();

    if (msgc->has_interface("org.freedesktop.DBus.Introspectable")) {
      this->introspection(msgc, reply);
    } else if (this->connected(msgc->path(), msgc->interface())) {
      auto f_msg_r = Function_dbus_recv_i(msgc);
      auto r_ret_s = Return_dbus_send_i(reply);
      this->get_caller(msgc->path(), msgc->interface()).call(f_msg_r, r_ret_s);

      std::cout << ">>" << reply->signature() << "<<\n";
    } else {
      std::cerr << "Not connected in the link..." << msgc->path() << ":"
                << msgc->interface() << "." << msgc->member();
    }

    conn << reply;
    conn->flush();
  }
}

void Dbus_server::introspection(DBus::CallMessage::pointer msg,
                                DBus::ReturnMessage::pointer reply) {

  std::stringstream ss;
  ss << "<node>";
  ss << "<interface name=\"org.freedesktop.DBus.Introspectable\"><method "
        "name=\"Introspect\"><arg type=\"s\" name=\"xml_data\" "
        "direction=\"out\"/></method></interface>";
  for (auto &kv2 : this->a_c[msg->path()]) {
    ss << "\t<interface name=\"" << kv2.first << "\">";
    kv2.second->introspection(ss);
    ss << "</interface>\n";
  }

  std::cout << "path:" << msg->path() << "\n";
  for (auto &kv : this->a_c) {
    if (kv.first == msg->path()) {
      continue;
    }

    int p = kv.first.find(msg->path());
    if (p != std::string::npos) {
      ss << "<node name=\"" << kv.first.substr(msg->path().length()) << "\"/>";
    }
  }
  ss << "</node>";

  reply << ss.str();
}

void Dbus_server::connect() {
  Link::connect();

  this->conn = DBus::Connection::create(DBus::BUS_SESSION, false);

  // request a name on the bus
  int ret = conn->request_name(this->get_object_name(),
                               DBUS_NAME_FLAG_REPLACE_EXISTING);

  if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != ret) {
    return;
  }
}

void Dbus_server::disconnect() { Link::disconnect(); }

// Get and set /////////////////////////////////////////////////////////////
string Dbus_server::get_object_name() const { return this->object_name; }

void Dbus_server::set_object_name(const string p_object_name) {
  this->object_name = p_object_name;
}
