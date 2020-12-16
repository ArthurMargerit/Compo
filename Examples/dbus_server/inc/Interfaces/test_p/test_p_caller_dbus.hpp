#pragma once

#include "Interfaces/test_p//test_p.hpp"

#include "Interfaces/Caller_dbus.hpp"

class test_p_caller_dbus : public CompoMe::Caller_dbus {
private:
  test_p &comp;

public:
  test_p_caller_dbus(test_p &pcomp);

  bool call(CompoMe::Function_dbus_recv &,
            CompoMe::Return_dbus_send &) override;

  void introspection(std::ostream &ss) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_dbus_recv &,
            CompoMe::Return_dbus_send &) override;

private:
  bool f0(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f1(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f2(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f3(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f5(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f6(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);
};
