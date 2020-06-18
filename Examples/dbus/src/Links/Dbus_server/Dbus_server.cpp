#include "Links/Dbus_server/Dbus_server.hpp"

#include "Interfaces/Interface.hpp"

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
    msgc = DBus::CallMessage::create(msg);
    std::cout << msgc->path() << "\n";

    DBus::ReturnMessage::pointer reply;
    reply = msgc->create_reply();
    if (msgc->has_interface("org.freedesktop.DBus.Introspectable")) {
      this->introspection(msgc, reply);
    } // else if (msgc->has_interface("org.freedesktop.DBus.ObjectManager")) {

    //   // std::map<DBus::Path,std::map<std::string, std::map<std::string,
    //   // DBus::Variant<std::string>>>> m;
    //   std::map<
    //       DBus::Path,
    //       std::map<std::string, std::map<std::string,
    //       DBus::Variant<mstring>>>> m;

    //   for (auto &kv : this->a_c) {
    //     auto path = this->get_object_name()+"/"+kv.first;
    //     for (auto &kv2 : kv.second) {
    //       std::cout << kv.first<<" "<<kv2.first  << "\n";
    //       mstring a = mstring(kv2.first);
    //       mstring b = mstring("lldldo");
    //       mstring c = mstring("");
    //       m[path][kv2.first]["UID"] = DBus::Variant<mstring>(a);
    //         m[path][kv2.first]["Data"] = DBus::Variant<mstring>(b);
    //       m[path][kv2.first]["ConnectionStatus"] = DBus::Variant<mstring>(c);
    //     }
    //   }

    //   reply << m;

    // }
    else if (this->connected(msgc->path(), msgc->interface())) {
      this->get_caller(msgc->path(), msgc->interface()).call(msgc, reply);
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

  //   <interface name="org.freedesktop.DBus.Introspectable">
  //     <method name="Introspect">
  //       <arg type="s" name="xml_data" direction="out"/>
  //     </method>
  //   </interface>
  //   // <interface name="org.freedesktop.DBus.Peer">
  //   //   <method name="Ping"/>
  //   //   <method name="GetMachineId">
  //   //     <arg type="s" name="machine_uuid" direction="out"/>
  //   //   </method>
  //   // </interface>
  // </node>

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

  std::cout <<"path:"<< msg->path() << "\n";
    for (auto &kv : this->a_c) {
      if(kv.first == msg->path()) {
        continue;
      }

      int p = kv.first.find(msg->path());
      if(p != std::string::npos) {
        ss << "<node name=\"" << kv.first.substr(msg->path().length()) << "\"/>";
      }
    }
  ss << "</node>";

  reply << ss.str();
}

void Dbus_server::connect() {
  Link::connect();

  // this->conn = DBus::Connection::create(DBus::BUS_SESSION);
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
