
#include "Interfaces/{{NAME}}/{{NAME}}.hpp"
#include "Interfaces/{{NAME}}/{{NAME}}_fake.hpp"
#include "Interfaces/{{NAME}}/{{NAME}}_caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Caller.hpp"


{{NAME}}::{{NAME}}():c(nullptr)
{}


{{NAME}}::~{{NAME}}() noexcept
{
  if (c != nullptr) {
    delete c;
  }
}


Caller* {{NAME}}::get_caller()
{
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}


std::function<Fake*(Function_stream&, Return_stream&)> build_fake({{NAME}}* t)
{
  std::function<Fake*(Function_stream&, Return_stream&)> f= {{NAME}}::MyFake::Build_func;
  return f;
}



// Fake* {{NAME}}::get_fake(std::ostream& os, std::istream& is)
// {
//   return new  MyFake(os, is);
// }
