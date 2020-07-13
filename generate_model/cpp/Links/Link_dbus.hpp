#pragma once

#include "Interfaces/Caller_dbus.hpp"
#include "Interfaces/Interface.hpp"

#include "Components/Require_helper.hpp"

#include <map>
#include <string>

class Link_dbus_in {
protected:
  std::map<std::string, std::map<std::string, Caller_dbus *>> a_c;

  virtual void connect(Require_helper &p_i) = 0;
  virtual void disconnect(Require_helper &p_i) = 0;

public:
  Caller_dbus &get_caller(std::string p_node, std::string p_interface);
  bool connected(std::string p_node, std::string p_interface);
  virtual void set_in(std::string p_node, std::string p_interface,
                      Interface *to);
};

class Link_dbus_out {
protected:
  using T_DPI = std::tuple<std::string, std::string, std::string>;

  std::map<Require_helper *, T_DPI> a_f;

  virtual void connect(Require_helper &p_i) = 0;
  virtual void disconnect(Require_helper &p_i) = 0;

public:
  virtual void set_out(std::string p_dest, std::string p_path,
                       std::string p_interface, Require_helper &p_req);
};
