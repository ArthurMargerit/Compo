
#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace org {

namespace mpris {

namespace MediaPlayer2 {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Ctl_caller_stream::Ctl_caller_stream(Ctl &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Ctl_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool Ctl_caller_stream::call(std::string &name_function,
                             CompoMe::Function_stream_recv &is,
                             CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("Quit"):
    result = this->Quit(is, os);
    break;

  case str2int("Raise"):
    result = this->Raise(is, os);
    break;
  };

  return result;
}

bool Ctl_caller_stream::Quit(CompoMe::Function_stream_recv &is,
                             CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.Quit();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Ctl_caller_stream::Raise(CompoMe::Function_stream_recv &is,
                              CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.Raise();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
