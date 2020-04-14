
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}.hpp"
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}_fake.hpp"
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}_caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Caller.hpp"

{% include "helper/namespace_open.hpp" with context %}
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

// Build_fake_F get_build_fake({{D_NAME}}* t) {
//   return {{D_NAME}}::MyFake::Build_func;
// }
{% include "helper/namespace_close.hpp" with context %}
