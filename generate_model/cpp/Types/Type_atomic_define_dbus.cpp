#include "Types/{{F_NAME}}.hpp"


{% if OPTIONS and OPTIONS.TO_DBUS_STREAM and not DYNAMIC %}
#include <dbus/dbus.h>
#include "CompoMe_DBus.hpp"

template <> struct dbus_type_cls<{{NAME}}>{
  static std::string sig(){
    return std::string({{OPTIONS.DBUS_TYPE}}_AS_STRING);
}
};

// DBus Message
DBusMessageIter& operator<<(DBusMessageIter& os, const {{D_NAME}}& pt){
  {% if OPTIONS.DBUS_TYPE %}

  if (false == dbus_message_iter_append_basic(&os, dbus_type<{{D_NAME}}>(), &pt)) {
    throw "Not enough memory";
  }
  {%else%}
  // TODO
  {% endif %}

  return os;
}

DBusMessageIter& operator>>(DBusMessageIter& is, {{D_NAME}}& pt){
  {% if OPTIONS.DBUS_TYPE %}
  if (dbus_message_iter_get_arg_type(&is) != dbus_type<{{D_NAME}}>() ) {
    return is;
  }

  dbus_message_iter_get_basic(&is, &pt);
  dbus_message_iter_next(&is);
  {%else%}
  // TODO
  {% endif %}

  return is;
}
{% endif %}
