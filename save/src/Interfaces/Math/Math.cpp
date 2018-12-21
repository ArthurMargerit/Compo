
#include "Interfaces/Math/Math.hpp"
#include "Interfaces/Math/Math_fake.hpp"
#include "Interfaces/Math/Math_call.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Caller.hpp"

#include <istream>
#include <ostream>

Math::Math():c(nullptr)
{}


Math::~Math() noexcept
{
  if (c != nullptr) {
    delete c;
  }
}


Caller* Math::get_caller()
{
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

std::function<Interface*(std::ostream&,std::istream&)> build_fake(Math* t)
{
  std::function<Interface*(std::ostream&,std::istream&)> f= Math::MyFake::Build_func;
  return f;
}

