
#include "Interfaces/Temperature_i/Temperature_i.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Temperature_i/Temperature_i_caller.hpp"
#include "Interfaces/Temperature_i/Temperature_i_fake.hpp"

Temperature_i::Temperature_i() : c(nullptr) {}

Temperature_i::~Temperature_i() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Temperature_i::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

std::function<Fake *(Function_stream &, Return_stream &)>
build_fake(Temperature_i *t) {
  std::function<Fake *(Function_stream &, Return_stream &)> f =
      Temperature_i::MyFake::Build_func;
  return f;
}

// Fake* Temperature_i::get_fake(std::ostream& os, std::istream& is)
// {
//   return new  MyFake(os, is);
// }