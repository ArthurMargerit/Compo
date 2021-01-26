#include "Types/{{F_NAME}}.hpp"


{% if OPTIONS and OPTIONS.TO_DBUS_STREAM and DYNAMIC%}
#include <dbus/dbus.h>
// DBus Message
{%if DYNAMIC%}
template<
{%-for l_arg in ARG -%}
{% if " " in l_arg %}{{l_arg}}{%else%}typename {{l_arg}}{%endif%}
{% if not loop.last %},{%endif -%}
{%-endfor-%}
>{%endif%}
DBusMessageIter& operator<<(DBusMessageIter& os, const {{D_NAME}} {%if DYNAMIC%}<
  {%- for l_arg in ARG -%}
  {% if "..." in l_arg %}{{l_arg.replace("...","")}}...{% else -%}{{l_arg.split(" ")[-1]}}{% endif %}{% if not loop.last %},{% endif -%}
  {%- endfor -%}>{% endif %} & pt){
  // TODO
  return os;
}

{%if DYNAMIC%}
template<
{%-for l_arg in ARG -%}
{% if " " in l_arg %}{{l_arg}}{%else%}typename {{l_arg}}{%endif%}
{% if not loop.last %},{%endif -%}
{%-endfor-%}
>{%endif%}
DBusMessageIter& operator>>(DBusMessageIter& is, {{D_NAME}}{%if DYNAMIC%}<
  {%- for l_arg in ARG -%}
  {% if "..." in l_arg %}{{l_arg.replace("...","")}}...{% else -%}{{l_arg.split(" ")[-1]}}{% endif %}{% if not loop.last %},{% endif -%}
  {%- endfor -%}>{% endif %}& pt){
  // TODO
  return is;
}
{% endif %}
