
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}.hpp"
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}_fake.hpp"

#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}_caller.hpp"

{%if OPTION and OPTION.DBUS_ADAPTER %}
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}_dbus_adapter.hpp"
{% endif %}

{% include "helper/namespace_open.hpp" with context %}
{{NAME}}::{{NAME}}():c(nullptr){%if OPTION and OPTION.DBUS_ADAPTER %},c_dbus(nullptr){% endif %} {}

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

{%if OPTION and OPTION.DBUS_ADAPTER %}
Dbus_adapter* {{NAME}}::get_dbus_adapter(){
  if (c_dbus == nullptr) {
    c_dbus = new MyDbus_adapter(*this);
  }

  return c_dbus;
}
{% endif %}
{% include "helper/namespace_close.hpp" with context %}
