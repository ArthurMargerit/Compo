
#include "Interfaces/Hello_I/Hello_I_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Hello_I_caller_stream::Hello_I_caller_stream(Hello_I &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Hello_I_caller_stream::call(CompoMe::Function_stream_recv &is,
                                 CompoMe::Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool Hello_I_caller_stream::call(std::string &name_function,
                                 CompoMe::Function_stream_recv &is,
                                 CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("hello"):
    result = this->hello(is, os);
    break;
  };

  return result;
}

bool Hello_I_caller_stream::hello(CompoMe::Function_stream_recv &is,
                                  CompoMe::Return_stream_send &os) {

  CompoMe::String l_who;
  is >> l_who;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.hello(l_who);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}
