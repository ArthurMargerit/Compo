#pragma once

#include "Interfaces/Calculator//Calculator.hpp"

#include "Interfaces/Caller_dbus.hpp"

class Calculator_caller_dbus : public CompoMe::Caller_dbus {
private:
  Calculator &comp;

public:
  Calculator_caller_dbus(Calculator &pcomp);

  bool call(CompoMe::Function_dbus_recv &,
            CompoMe::Return_dbus_send &) override;

  void introspection(std::ostream &ss) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_dbus_recv &,
            CompoMe::Return_dbus_send &) override;

private:
  bool add(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool sub(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool time(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);

  bool div(CompoMe::Function_dbus_recv &msg, CompoMe::Return_dbus_send &reply);
};
