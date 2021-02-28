#include "Structs/{{F_NAME}}.hpp"
#include "CompoMe/Log.hpp"
#include "Serialization_context.hpp"
#include <string>
#include "CompoMe_DBus.hpp"
#include "Data/CompoMe_Dbus.hpp"
#include <dbus/dbus.h>
#include <cstdlib>

template <> struct dbus_type_cls<CompoMe::Struct*> {
  static std::string sig() { return "a{sv}";}
};

namespace {
  constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}


template <typename T>
void export_field(DBusMessageIter &os,
             CompoMe::Serialization_context_export &p_ctx, T p_t, std::string p_name) {
  DBusMessageIter sub_os, sub_sub_os;
  // entry open
  dbus_message_iter_open_container(&os, DBUS_TYPE_DICT_ENTRY, NULL, &sub_os);

  // key
  const char *key = p_name.c_str();
  dbus_message_iter_append_basic(&sub_os, DBUS_TYPE_STRING, &key);

  // value
  dbus_message_iter_open_container(&sub_os, DBUS_TYPE_VARIANT, dbus_type_cls<T>::sig().c_str(), &sub_sub_os);
  sub_sub_os << p_t;
  dbus_message_iter_close_container(&sub_os, &sub_sub_os);

  // entry close
  dbus_message_iter_close_container(&os, &sub_os);
}

void export_sub(DBusMessageIter &os,
                CompoMe::Serialization_context_export &p_ctx, const CompoMe::Struct& p_t, std::string p_name) {
  DBusMessageIter sub_os, sub_sub_os;
  // entry open
  dbus_message_iter_open_container(&os, DBUS_TYPE_DICT_ENTRY, NULL, &sub_os);

  // key
  const char *key = p_name.c_str();
  dbus_message_iter_append_basic(&sub_os, DBUS_TYPE_STRING, &key);

  // value
  dbus_message_iter_open_container(&sub_os, DBUS_TYPE_VARIANT, "a{sv}", &sub_sub_os);
  p_t.to_dbus(sub_sub_os, p_ctx);
  dbus_message_iter_close_container(&sub_os, &sub_sub_os);

  // entry close
  dbus_message_iter_close_container(&os, &sub_os);
}

}

void {{ NAME }}::to_dbus(DBusMessageIter &os,
            CompoMe::Serialization_context_export &p_ctx) const {
  DBusMessageIter sub_os;
  dbus_message_iter_open_container(&os, DBUS_TYPE_ARRAY, "{sv}", &sub_os);

  export_field(sub_os, p_ctx, (uint64_t)this, "addr");
  export_field(sub_os, p_ctx, CompoMe::String("{{NAME}}"), "type");
  {% if PARENT %}
  {
  DBusMessageIter psub_os, psub_sub_os;
  dbus_message_iter_open_container(&sub_os, DBUS_TYPE_DICT_ENTRY, NULL, &psub_os);

  // key
  const char *key = "parent";
  dbus_message_iter_append_basic(&psub_os, DBUS_TYPE_STRING, &key);

  // value
  dbus_message_iter_open_container(&psub_os, DBUS_TYPE_VARIANT, "a{sv}", &psub_sub_os);
  {{PARENT.NAME}}::to_dbus(psub_sub_os, p_ctx);
  dbus_message_iter_close_container(&psub_os, &psub_sub_os);

  // entry close
  dbus_message_iter_close_container(&sub_os, &psub_os);
  }
  {% endif %}

  {% for i_d in DATA %}
  {% if Function.model_test.is_struct(i_d.TYPE.D_NAME, MAIN) %}
  export_sub(sub_os, p_ctx, this->{{i_d.NAME}}, "{{i_d.NAME}}");
  {% else %}
  export_field(sub_os, p_ctx, this->{{i_d.NAME}} , "{{i_d.NAME}}");
  {% endif %}
  {% endfor %}

  dbus_message_iter_close_container(&os, &sub_os);
}

void {{NAME}}::from_dbus(DBusMessageIter &is, CompoMe::Serialization_context_import &p_ctx) {

  DBusMessageIter sub_is, sub_sub_is,sub_sub_sub_is;
  dbus_message_iter_recurse(&is,&sub_is);

  while(true) {
    dbus_message_iter_recurse(&sub_is, &sub_sub_is);

    const char * key;
    dbus_message_iter_get_basic (&sub_sub_is, &key);
    dbus_message_iter_next(&sub_sub_is);

    dbus_message_iter_recurse(&sub_sub_is, &sub_sub_sub_is);
    switch(str2int(key)) {
          case str2int("addr"):{
            int64_t t;
            sub_sub_sub_is >> t;
            break;
          }

         {% if PARENT %}
          case str2int("parent"):{
           {{PARENT.D_NAME}}::from_dbus(sub_sub_sub_is, p_ctx);
           break;
         }
         {%endif%}

          case str2int("type"):{
            CompoMe::String s;
            sub_sub_sub_is >> s;
            if(s.str != "{{NAME}}") {
               throw "wrong type \"{{NAME}}\" != \"" + s.str + "\"";
            }
            break;
          }

          {% for i_d in DATA %}
          case str2int("{{i_d.NAME}}"): {
             {% if Function.model_test.is_struct(i_d.TYPE.D_NAME, MAIN) %}
             this->{{i_d.NAME}}.from_dbus(sub_sub_sub_is, p_ctx);
             {% else %}
             sub_sub_sub_is >> this->{{i_d.NAME}};
             {% endif %}
             break;
          }
          {% endfor %}

          default: {
            C_ERROR("wrong attribute: \"", key ,"\" not in struct {{NAME}}");
            throw "wrong attribute";
                break;
           }
    }

    if (! dbus_message_iter_has_next(&sub_is)) {
      break;
    } else {
      dbus_message_iter_next(&sub_is);
    }
  }

  dbus_message_iter_next(&is);
}
