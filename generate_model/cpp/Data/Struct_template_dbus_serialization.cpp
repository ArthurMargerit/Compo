#include "Data/{{F_NAME}}.hpp"
#include "Serialization_context.hpp"
#include <dbus-cxx.h>
#include <map>
#include <string>

namespace {

  constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

template <typename T>
void export_field(DBus::MessageAppendIterator &os,
             Serialization_context_export &p_ctx, T p_t, std::string p_name,
             std::string si) {
  os.open_container(DBus::CONTAINER_DICT_ENTRY, "sv");
  *os.sub_iterator() << p_name;
  os.sub_iterator()->open_container(DBus::CONTAINER_VARIANT, si);
  *os.sub_iterator()->sub_iterator() << p_t;
  os.sub_iterator()->close_container();
  os.close_container();
}

template <typename T>
void import_field(DBus::MessageIterator &is,
                  Serialization_context_import &p_ctx, T& p_t) {
  is >> p_t;
}

void export_sub(DBus::MessageAppendIterator &os,
                  Serialization_context_export &p_ctx, const Struct& p_t, std::string p_name) {
  os.open_container(DBus::CONTAINER_DICT_ENTRY, "sv");
  *os.sub_iterator() << p_name;
  os.sub_iterator()->open_container(DBus::CONTAINER_VARIANT, "a{sv}");
  p_t.to_stream(*os.sub_iterator()->sub_iterator(), p_ctx);
  os.sub_iterator()->close_container();
  os.close_container();
}

}
void {{ NAME }}::to_stream(DBus::MessageAppendIterator &os,
            Serialization_context_export &p_ctx) const {

  os.open_container(DBus::CONTAINER_ARRAY, "{sv}");
  export_field(*os.sub_iterator(), p_ctx, (uint64_t)this, "addr", "t");
  export_field(*os.sub_iterator(), p_ctx, "{{NAME}}", "type", "s");

  {% if PARENT %}
  export_field(*os.sub_iterator(), p_ctx, ({{PARENT.D_NAME}}*) this, "parent", "a{sv}");
  {% endif %}

  {% for i_d in DATA %}
  {% if Function.model_test.is_struct(i_d.TYPE.D_NAME, MAIN) %}
  export_sub(*os.sub_iterator(), p_ctx, this->{{i_d.NAME}}, "{{i_d.NAME}}");
  {% else %}
  export_field(*os.sub_iterator(), p_ctx, this->{{i_d.NAME}} , "{{i_d.NAME}}", "{{i_d.TYPE.DBUS}}");
  {% endif %}
  {% endfor %}

  {% if EXTRA %}
  std::stringstream ss;
  this->extra_export(ss, p_ctx);
  export_field(i3, p_ctx, ss.str() ,"extra","s");
  {% endif %}

  os.close_container();
  return;
}

void {{NAME}}::from_stream(DBus::MessageIterator &is, Serialization_context_import &p_ctx) {


  auto i1 = is.recurse();

  while (i1.is_valid()) {
    auto i2 = i1.recurse();
      std::string k;
      i2 >> k;
      auto i3 = i2.recurse();
      switch(str2int(k.c_str())) {
      case str2int("addr"):{
        int64_t t;
        import_field(i3, p_ctx, t);
        break;
      }

      case str2int("type"):{
        std::string s;
        import_field(i3, p_ctx, s);
        if(s != "{{NAME}}") {
          throw "wrong type {{NAME}} != ";
        }
        break;
      }

        {% for i_d in DATA %}
      case str2int("{{i_d.NAME}}"): {
        {% if Function.model_test.is_struct(i_d.TYPE.D_NAME, MAIN) %}
        this->{{i_d.NAME}}.from_stream(i3, p_ctx);
        {% else %}
        import_field(i3, p_ctx, this->{{i_d.NAME}});
        {% endif %}
      break;
      }

      {% endfor %}

      {% if EXTRA %}
      case str2int("extra"):
        std::string extra_str;
        std::stringstream ss;
        import_field(i3, p_ctx, this->{{i_d.NAME}});
        ss.str(extra_str);
        this->extra_import(ss, p_ctx);
        break;
      {% endif %}

      default:
        std::cerr << "wrong attribute: \""<< k <<"\" not in {{NAME}}";
        throw "wrong attribute: \""+ k +"\" not in {{NAME}}";
        break;
      } // end switch

      i1.next();
  }

  return;
}
