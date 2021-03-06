
#include "Interfaces/{{NAMESPACE.replace('::','/')}}/{{NAME}}/{{NAME}}.hpp"

{% include "helper/namespace_open.hpp" with context %}

{{NAME}}::{{NAME}}():
{%if PARENT %} {{PARENT.D_NAME}}() {% else %} CompoMe::Interface() {% endif %}
{%if OPTIONS.CALLER_STREAM %},a_caller_stream(nullptr){% endif%}
{%if OPTIONS.CALLER_DBUS %},a_caller_dbus(nullptr){% endif %}
{%if OPTIONS.CALLER_JSON %},a_caller_json(nullptr){% endif %} {}

{{NAME}}::~{{NAME}}() noexcept {
  {%if OPTIONS.CALLER_STREAM %}
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
  {%endif%}

  {%if OPTIONS.CALLER_DBUS %}
  if (a_caller_dbus != nullptr) {
      delete a_caller_dbus;
  }
  {%endif%}

  {%if OPTIONS.CALLER_JSON %}
  if (a_caller_json != nullptr) {
    delete a_caller_json;
  }
  {%endif%}
}

{%if OPTIONS.CALLER_STREAM %}
CompoMe::Caller_stream* {{NAME}}::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}
{% endif %}

{%if OPTIONS.CALLER_DBUS %}
CompoMe::Caller_dbus* {{NAME}}::get_caller_dbus() {
  if (this->a_caller_dbus == nullptr) {
    this->a_caller_dbus = new MyCallerDbus(*this);
  }
  return this->a_caller_dbus;
}
{% endif %}

{%if OPTIONS.CALLER_JSON %}
CompoMe::Caller_json* {{NAME}}::get_caller_json() {
  if (this->a_caller_json == nullptr) {
    this->a_caller_json = new MyCallerJson(*this);
  }
  return this->a_caller_json;
}
{% endif %}

{% include "helper/namespace_close.hpp" with context %}
