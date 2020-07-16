
#include "Interfaces/Calculator//Calculator_caller_dbus.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_dbus_recv.hpp"
#include "Interfaces/Return_dbus_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Calculator_caller_dbus::Calculator_caller_dbus(Calculator &pcomp)
    : CompoMe::Caller_dbus(), comp(pcomp) {}

void Calculator_caller_dbus::introspection(std::ostream &ss) {

  ss << "<method name=\"add\">"

     << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"

     << "<arg type=\"d\" name=\"b\" direction=\"in\"/>"

     << "<arg type=\"d\" name=\"ret\" direction=\"out\"/>"

     << "</method>";

  ss << "<method name=\"sub\">"

     << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"

     << "<arg type=\"d\" name=\"b\" direction=\"in\"/>"

     << "<arg type=\"d\" name=\"ret\" direction=\"out\"/>"

     << "</method>";

  ss << "<method name=\"time\">"

     << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"

     << "<arg type=\"d\" name=\"b\" direction=\"in\"/>"

     << "<arg type=\"d\" name=\"ret\" direction=\"out\"/>"

     << "</method>";

  ss << "<method name=\"div\">"

     << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"

     << "<arg type=\"d\" name=\"b\" direction=\"in\"/>"

     << "<arg type=\"d\" name=\"ret\" direction=\"out\"/>"

     << "</method>";
}

bool Calculator_caller_dbus::call(CompoMe::Function_dbus_recv &msg,
                                  CompoMe::Return_dbus_send &reply) {

  std::string name_function = msg.get_function();
  bool b = this->call(name_function, msg, reply);
  return b;
}

bool Calculator_caller_dbus::call(std::string &name_function,
                                  CompoMe::Function_dbus_recv &msg,
                                  CompoMe::Return_dbus_send &reply) {
  bool result = false;

  switch (str2int(name_function.c_str())) {
    // Function

  case str2int("add"):
    result = this->add(msg, reply);
    break;

  case str2int("sub"):
    result = this->sub(msg, reply);
    break;

  case str2int("time"):
    result = this->time(msg, reply);
    break;

  case str2int("div"):
    result = this->div(msg, reply);
    break;

    // Get/Set
  };

  return result;
}

bool Calculator_caller_dbus::add(CompoMe::Function_dbus_recv &msg,
                                 CompoMe::Return_dbus_send &reply) {

  double l_a;

  msg >> l_a;

  double l_b;

  msg >> l_b;

  try {

    auto rep = this->comp.add(l_a, l_b);

    reply << rep;

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool Calculator_caller_dbus::sub(CompoMe::Function_dbus_recv &msg,
                                 CompoMe::Return_dbus_send &reply) {

  double l_a;

  msg >> l_a;

  double l_b;

  msg >> l_b;

  try {

    auto rep = this->comp.sub(l_a, l_b);

    reply << rep;

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool Calculator_caller_dbus::time(CompoMe::Function_dbus_recv &msg,
                                  CompoMe::Return_dbus_send &reply) {

  double l_a;

  msg >> l_a;

  double l_b;

  msg >> l_b;

  try {

    auto rep = this->comp.time(l_a, l_b);

    reply << rep;

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool Calculator_caller_dbus::div(CompoMe::Function_dbus_recv &msg,
                                 CompoMe::Return_dbus_send &reply) {

  double l_a;

  msg >> l_a;

  double l_b;

  msg >> l_b;

  try {

    auto rep = this->comp.div(l_a, l_b);

    reply << rep;

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}
