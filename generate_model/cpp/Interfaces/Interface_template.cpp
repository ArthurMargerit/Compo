
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}.hpp"
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}_fake_stream.hpp"

#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}_caller_stream.hpp"

{%if OPTION and OPTION.CALLER_DBUS %}
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}_caller_dbus.hpp"
{% endif %}

{% include "helper/namespace_open.hpp" with context %}
{{NAME}}::{{NAME}}():a_caller_stream(nullptr){%if OPTION and OPTION.CALLER_DBUS %},a_caller_dbus(nullptr){% endif %} {}

{{NAME}}::~{{NAME}}() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
  {%if OPTION and OPTION.CALLER_DBUS %}
  if (a_caller_dbus != nullptr) {
      delete a_caller_dbus;
  }
  {%endif%}
}

Caller_stream* {{NAME}}::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

{%if OPTION and OPTION.CALLER_DBUS %}
Caller_dbus* {{NAME}}::get_caller_dbus() {
  if (a_caller_dbus == nullptr) {
    a_caller_dbus = new MyCallerDbus(*this);
  }
  return a_caller_dbus;
}
{% endif %}
{% include "helper/namespace_close.hpp" with context %}
