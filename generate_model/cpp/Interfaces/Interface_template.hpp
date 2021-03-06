#pragma once

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

{%if PARENT -%}
#include "Interfaces/{{PARENT.F_NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Interfaces/Interface.hpp"
{%-endif%}

{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
#include "Structs/{{d.F_NAME}}.hpp"
{% endfor %}

#include <functional>
#include <tuple>

namespace CompoMe {
  class Caller_stream;
  class Fake_stream;

  class Caller_dbus;
  class Fake_dbus;

  class Caller_json;
  class Fake_json;

  class Function_dbus_send;
  class Return_dbus_recv;

  class Function_json_send;
  class Return_json_recv;

  class Function_stream_send;
  class Return_stream_recv;
}  // CompoMe

{% include "helper/namespace_open.hpp" with context %}
{%if OPTIONS.CALLER_STREAM %}
class {{NAME}}_caller_stream;
{% endif %}
{%if OPTIONS.CALLER_DBUS %}
class {{NAME}}_caller_dbus;
{% endif %}
{%if OPTIONS.CALLER_JSON %}
class {{NAME}}_caller_json;
{% endif %}

class {{NAME}}_fake_stream;
class {{NAME}}_fake_dbus;
class {{NAME}}_fake_json;

class {{NAME}} :public {%if PARENT %}{{PARENT.D_NAME}}{%else%}CompoMe::Interface{%endif%}
{
public:

  using T_p_stream = std::tuple<{{NAME}}_fake_stream*,CompoMe::Fake_stream*,{{NAME}}*>;
  using T_p_dbus = std::tuple<{{NAME}}_fake_dbus*,CompoMe::Fake_dbus*,{{NAME}}*>;
  using T_p_json = std::tuple<{{NAME}}_fake_json*,CompoMe::Fake_json*,{{NAME}}*>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs)
  {%- if OPTIONS.FAKE_STREAM %}
  ;
  {%- else %}
  {return std::make_tuple<{{NAME}}_fake_stream*,CompoMe::Fake_stream*,{{NAME}}*>(nullptr, nullptr, nullptr);}
  {%- endif %}


  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs)
  {%- if OPTIONS.FAKE_DBUS %}
    ;
  {%- else %}
  {return std::make_tuple<{{NAME}}_fake_dbus*,CompoMe::Fake_dbus*,{{NAME}}*>(nullptr, nullptr, nullptr);}
  {%- endif %}

  static T_p_json get_fake_json(CompoMe::Function_json_send &fs,
                                CompoMe::Return_json_recv &rs)
  {%- if OPTIONS.FAKE_JSON %}
    ;
  {%- else %}
  {return std::make_tuple<{{NAME}}_fake_json*,CompoMe::Fake_json*,{{NAME}}*>(nullptr, nullptr, nullptr);}
  {%- endif %}

  {%if OPTIONS.CALLER_STREAM %}
  using MyCallerStream = {{D_NAME}}_caller_stream;
  {% endif %}
  {%if OPTIONS.CALLER_DBUS %}
  using MyCallerDbus = {{D_NAME}}_caller_dbus;
  {% endif %}
  {%if OPTIONS.CALLER_JSON %}
  using MyCallerJson = {{D_NAME}}_caller_json;
  {% endif %}

  //// Caller function ////////////////////////////////////////////////////////
  {%if OPTIONS.CALLER_STREAM %}
  CompoMe::Caller_stream* get_caller_stream() override;
  {% endif %}
  {%if OPTIONS.CALLER_DBUS %}
  CompoMe::Caller_dbus* get_caller_dbus() override;
  {% endif %}
  {%if OPTIONS.CALLER_JSON %}
  CompoMe::Caller_json* get_caller_json() override;
  {% endif %}

  //! Default constructor
  {{NAME}}();

  //! Destructor
  virtual ~{{NAME}}() noexcept;

  {%- for f in FUNCTION %}
  virtual {{ f.RETURN.D_NAME }} {{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )=0;
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for v in DATA %}
  virtual {{v.TYPE.D_NAME}} get_{{v.NAME}}() const = 0;
  virtual void set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}}) = 0;
  {%- endfor %}

private:
  {%if OPTIONS.CALLER_STREAM %}
  CompoMe::Caller_stream* a_caller_stream;
  {% endif %}
  {%if OPTIONS.CALLER_DBUS %}
  CompoMe::Caller_dbus* a_caller_dbus;
  {% endif %}
  {%if OPTIONS.CALLER_JSON %}
  CompoMe::Caller_json* a_caller_json;
  {% endif %}
};

{% include "helper/namespace_close.hpp" with context %}

{%if OPTIONS.CALLER_STREAM %}
#include "Interfaces/{{F_NAME}}/{{NAME}}_caller_stream.hpp"
{% endif %}
{%if OPTIONS.CALLER_DBUS %}
#include "Interfaces/{{F_NAME}}/{{NAME}}_caller_dbus.hpp"
{% endif %}
{% if OPTIONS.CALLER_JSON %}
#include "Interfaces/{{F_NAME}}/{{NAME}}_caller_json.hpp"
{% endif %}

{%if OPTIONS.FAKE_STREAM %}
#include "Interfaces/{{F_NAME}}/{{NAME}}_fake_stream.hpp"
{% endif %}
{%if OPTIONS.FAKE_DBUS %}
#include "Interfaces/{{F_NAME}}/{{NAME}}_fake_dbus.hpp"
{% endif %}
{%if OPTIONS.FAKE_JSON %}
#include "Interfaces/{{F_NAME}}/{{NAME}}_fake_json.hpp"
{% endif %}
