
#include "Interfaces/I2/I2.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I2/I2_caller.hpp"
#include "Interfaces/I2/I2_fake.hpp"

I2::I2() : c(nullptr) {}

I2::~I2() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *I2::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(I2 *t) {
  std::function<Fake *(Function_stream &, Return_stream &)> f =
      I2::MyFake::Build_func;
  return f;
}

// Fake* I2::get_fake(std::ostream& os, std::istream& is)
// {
//   return new  MyFake(os, is);
// }