
#include "Interfaces/Log_i/Log_i.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Log_i/Log_i_caller.hpp"
#include "Interfaces/Log_i/Log_i_fake.hpp"

Log_i::Log_i() : c(nullptr) {}

Log_i::~Log_i() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Log_i::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(Log_i *t) {
  std::function<Fake *(Function_stream &, Return_stream &)> f =
      Log_i::MyFake::Build_func;
  return f;
}

// Fake* Log_i::get_fake(std::ostream& os, std::istream& is)
// {
//   return new  MyFake(os, is);
// }