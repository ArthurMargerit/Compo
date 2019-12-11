
#include "Interfaces/{{NAME}}/{{NAME}}.hpp"
#include "Interfaces/{{NAME}}/{{NAME}}_fake.hpp"
#include "Interfaces/{{NAME}}/{{NAME}}_caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Caller.hpp"


{{NAME}}::{{NAME}}():c(nullptr) {}

{{NAME}}::~{{NAME}}() noexcept
{
  if (c != nullptr) {
    delete c;
  }
}

Caller* {{NAME}}::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

// Build_fake_F get_build_fake({{NAME}}* t) {
//   return {{NAME}}::MyFake::Build_func;
// }
