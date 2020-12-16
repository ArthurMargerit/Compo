#pragma once

#include "Interfaces/test//test.hpp"

#include "Interfaces/test_p/test_p_caller_dbus.hpp"

class test_caller_dbus : public test_p_caller_dbus {
private:
  test &comp;

public:
  test_caller_dbus(test &pcomp);

  bool call(CompoMe::Function_dbus_recv &,
            CompoMe::Return_dbus_send &) override;

  void introspection(std::ostream &ss) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_dbus_recv &,
            CompoMe::Return_dbus_send &) override;

private:
  bool f7(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f8(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f9(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f10(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f11(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool f12(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool get_a(CompoMe::Function_dbus_recv &msg,
             CompoMe::Return_dbus_send &reply);
  bool set_a(CompoMe::Function_dbus_recv &msg,
             CompoMe::Return_dbus_send &reply);

  bool get_b(CompoMe::Function_dbus_recv &msg,
             CompoMe::Return_dbus_send &reply);
  bool set_b(CompoMe::Function_dbus_recv &msg,
             CompoMe::Return_dbus_send &reply);
};
