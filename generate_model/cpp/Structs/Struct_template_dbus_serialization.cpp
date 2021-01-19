#include "Structs/{{F_NAME}}.hpp"
#include "CompoMe/Log.hpp"
#include "Serialization_context.hpp"
#include <string>
#include <dbus/dbus.h>

namespace {
  constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

template <typename T>
void export_field(DBusMessageIter &os,
             CompoMe::Serialization_context_export &p_ctx, T p_t, std::string p_name,
             std::string si) {
  DBusMessageIter sub_os, sub_sub_os;
  // entry open
  dbus_message_iter_open_container(&os, DBUS_TYPE_DICT_ENTRY, NULL, &sub_os);

  // key
  const char *key = p_name.c_str();
  dbus_message_iter_append_basic(&sub_os, DBUS_TYPE_STRING, &key);

  // value
  dbus_message_iter_open_container(&sub_os, DBUS_TYPE_VARIANT, si.c_str(), &sub_sub_os);
  dbus_message_iter_append_basic(&sub_sub_os, si[0] ,&p_t);
  dbus_message_iter_close_container(&sub_os, &sub_sub_os);

  // entry close
  dbus_message_iter_close_container(&os, &sub_os);
}

template <typename T>
void import_field(DBusMessageIter &is,
                  CompoMe::Serialization_context_import &p_ctx, T& p_t) {
  dbus_message_iter_get_basic (&is, &p_t);
  dbus_message_iter_next(&is);
}

template<>
void import_field<std::string>(DBusMessageIter &is,
                               CompoMe::Serialization_context_import &p_ctx, std::string& p_t) {
  const char * addr;
  dbus_message_iter_get_basic (&is, &addr);
  p_t = std::string(addr);
  dbus_message_iter_next(&is);
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
  p_t.to_stream(sub_sub_os, p_ctx);
  dbus_message_iter_close_container(&sub_os, &sub_sub_os);

  // entry close
  dbus_message_iter_close_container(&os, &sub_os);
}

}

DBusMessageIter &{{ NAME }}::to_stream(DBusMessageIter &os,
            CompoMe::Serialization_context_export &p_ctx) const {
  DBusMessageIter sub_os;
  dbus_message_iter_open_container(&os, DBUS_TYPE_ARRAY, "{sv}", &sub_os);

  export_field(sub_os, p_ctx, (uint64_t)this, "addr", "t");
  export_field(sub_os, p_ctx, "{{NAME}}", "type", "s");
  {% if PARENT %}
  export_field(sub_os, p_ctx, ({{PARENT.D_NAME}}*) this, "parent", "a{sv}");
  {% endif %}

  {% for i_d in DATA %}
  {% if Function.model_test.is_struct(i_d.TYPE.D_NAME, MAIN) %}
  export_sub(sub_os, p_ctx, this->{{i_d.NAME}}, "{{i_d.NAME}}");
  {% else %}
  export_field(sub_os, p_ctx, this->{{i_d.NAME}} , "{{i_d.NAME}}", "{{i_d.TYPE.DBUS}}");
  {% endif %}
  {% endfor %}

  dbus_message_iter_close_container(&os, &sub_os);
  return os;
}

DBusMessageIter& {{NAME}}::from_stream(DBusMessageIter &is, CompoMe::Serialization_context_import &p_ctx) {

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
            import_field(sub_sub_sub_is, p_ctx, t);
            break;
          }

          case str2int("type"):{
            std::string s;
            import_field(sub_sub_sub_is, p_ctx, s);
            if(s != "{{NAME}}") {
               throw "wrong type \"{{NAME}}\" != \"" + s+"\"";
            }
            break;
          }

          {% for i_d in DATA %}
          case str2int("{{i_d.NAME}}"): {
             {% if Function.model_test.is_struct(i_d.TYPE.D_NAME, MAIN) %}
             this->{{i_d.NAME}}.from_stream(sub_sub_sub_is, p_ctx);
             {% else %}
             import_field(sub_sub_sub_is, p_ctx, this->{{i_d.NAME}});
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
  return is;
}
