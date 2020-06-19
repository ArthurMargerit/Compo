#include "Links/Dbus_server/Dbus_server.hpp"

#include "Interfaces/Interface.hpp"

Dbus_server::Dbus_server() : Link() { DBus::init(); }

Dbus_server::~Dbus_server() {}

void Dbus_server::step() {
  DBus::Message::pointer msg;

  Link::step();
  conn->read_write(0);
  msg = conn->pop_message();
  if (not msg) {
    return;
  }

  if (msg->type() == DBus::CALL_MESSAGE) {
    DBus::CallMessage::create(msg);

    DBus::CallMessage::pointer msgc;
    msgc = DBus::CallMessage::create(msg);

    DBus::ReturnMessage::pointer reply;
    reply = msg->create_reply();
    this->adapter->call(msgc, reply);
    conn << reply;
    conn->flush();
  }
}

void Dbus_server::connect() {
  Link::connect();
  this->conn = DBus::Connection::create(DBus::BUS_SESSION);

  // request a name on the bus
  int ret = conn->request_name("dbuscxx.example.calculator.server",
                               DBUS_NAME_FLAG_REPLACE_EXISTING);

  if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != ret) {
    return;
  }
}

void Dbus_server::disconnect() { Link::disconnect(); }

// Get and set /////////////////////////////////////////////////////////////
