
#include "Interfaces/test_p//test_p_caller_dbus.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_dbus_recv.hpp"
#include "Interfaces/Return_dbus_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

test_p_caller_dbus::test_p_caller_dbus(test_p &pcomp)
    : CompoMe::Caller_dbus(), comp(pcomp) {}

void test_p_caller_dbus::introspection(std::ostream &ss) {

  ss << "<method name=\"f0\">"

     << "</method>";

  ss << "<method name=\"f1\">"

     << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"

     << "</method>";

  ss << "<method name=\"f2\">"

     << "<arg type=\"y\" name=\"a\" direction=\"in\"/>"

     << "</method>";

  ss << "<method name=\"f3\">"

     << "<arg type=\"n\" name=\"a\" direction=\"in\"/>"

     << "</method>";

  ss << "<method name=\"f5\">"

     << "<arg type=\"i\" name=\"a\" direction=\"in\"/>"

     << "</method>";

  ss << "<method name=\"f6\">"

     << "<arg type=\"x\" name=\"a\" direction=\"in\"/>"

     << "</method>";
}

bool test_p_caller_dbus::call(CompoMe::Function_dbus_recv &msg,
                              CompoMe::Return_dbus_send &reply) {

  std::string name_function = msg.get_function();
  bool b = this->call(name_function, msg, reply);
  return b;
}

bool test_p_caller_dbus::call(std::string &name_function,
                              CompoMe::Function_dbus_recv &msg,
                              CompoMe::Return_dbus_send &reply) {
  bool result = false;

  switch (str2int(name_function.c_str())) {
    // Function

  case str2int("f0"):
    result = this->f0(msg, reply);
    break;

  case str2int("f1"):
    result = this->f1(msg, reply);
    break;

  case str2int("f2"):
    result = this->f2(msg, reply);
    break;

  case str2int("f3"):
    result = this->f3(msg, reply);
    break;

  case str2int("f5"):
    result = this->f5(msg, reply);
    break;

  case str2int("f6"):
    result = this->f6(msg, reply);
    break;

    // Get/Set
  };

  return result;
}

bool test_p_caller_dbus::f0(CompoMe::Function_dbus_recv &msg,
                            CompoMe::Return_dbus_send &reply) {

  try {

    this->comp.f0();

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_p_caller_dbus::f1(CompoMe::Function_dbus_recv &msg,
                            CompoMe::Return_dbus_send &reply) {

  double l_a;

  msg >> l_a;

  try {

    this->comp.f1(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_p_caller_dbus::f2(CompoMe::Function_dbus_recv &msg,
                            CompoMe::Return_dbus_send &reply) {

  i8 l_a;

  msg >> l_a;

  try {

    this->comp.f2(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_p_caller_dbus::f3(CompoMe::Function_dbus_recv &msg,
                            CompoMe::Return_dbus_send &reply) {

  i16 l_a;

  msg >> l_a;

  try {

    this->comp.f3(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_p_caller_dbus::f5(CompoMe::Function_dbus_recv &msg,
                            CompoMe::Return_dbus_send &reply) {

  i32 l_a;

  msg >> l_a;

  try {

    this->comp.f5(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_p_caller_dbus::f6(CompoMe::Function_dbus_recv &msg,
                            CompoMe::Return_dbus_send &reply) {

  i64 l_a;

  msg >> l_a;

  try {

    this->comp.f6(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}
