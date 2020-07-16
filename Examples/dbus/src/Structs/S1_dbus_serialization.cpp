#include "Structs/S1.hpp"

#include "Serialization_context.hpp"
#include <dbus-cxx.h>
#include <map>
#include <string>

namespace {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

template <typename T>
void export_field(DBus::MessageAppendIterator &os,
                  CompoMe::Serialization_context_export &p_ctx, T p_t,
                  std::string p_name, std::string si) {
  os.open_container(DBus::CONTAINER_DICT_ENTRY, "sv");
  *os.sub_iterator() << p_name;
  os.sub_iterator()->open_container(DBus::CONTAINER_VARIANT, si);
  *os.sub_iterator()->sub_iterator() << p_t;
  os.sub_iterator()->close_container();
  os.close_container();
}

template <typename T>
void import_field(DBus::MessageIterator &is,
                  CompoMe::Serialization_context_import &p_ctx, T &p_t) {
  is >> p_t;
}

void export_sub(DBus::MessageAppendIterator &os,
                CompoMe::Serialization_context_export &p_ctx,
                const CompoMe::Struct &p_t, std::string p_name) {
  os.open_container(DBus::CONTAINER_DICT_ENTRY, "sv");
  *os.sub_iterator() << p_name;
  os.sub_iterator()->open_container(DBus::CONTAINER_VARIANT, "a{sv}");
  p_t.to_stream(*os.sub_iterator()->sub_iterator(), p_ctx);
  os.sub_iterator()->close_container();
  os.close_container();
}

} // namespace

DBus::MessageAppendIterator &
S1::to_stream(DBus::MessageAppendIterator &os,
              CompoMe::Serialization_context_export &p_ctx) const {

  os.open_container(DBus::CONTAINER_ARRAY, "{sv}");
  export_field(*os.sub_iterator(), p_ctx, (uint64_t)this, "addr", "t");
  export_field(*os.sub_iterator(), p_ctx, "S1", "type", "s");

  export_field(*os.sub_iterator(), p_ctx, this->i1, "i1", "i");

  os.close_container();
  return os;
}

DBus::MessageIterator &
S1::from_stream(DBus::MessageIterator &is,
                CompoMe::Serialization_context_import &p_ctx) {

  auto i1 = is.recurse();

  while (i1.is_valid()) {
    auto i2 = i1.recurse();
    std::string k;
    i2 >> k;
    auto i3 = i2.recurse();
    switch (str2int(k.c_str())) {
    case str2int("addr"): {
      int64_t t;
      import_field(i3, p_ctx, t);
      break;
    }

    case str2int("type"): {
      std::string s;
      import_field(i3, p_ctx, s);
      if (s != "S1") {
        throw "wrong type S1 != ";
      }
      break;
    }

    case str2int("i1"): {

      import_field(i3, p_ctx, this->i1);

      break;
    }

    default:
      std::cerr << "wrong attribute: \"" << k << "\" not in S1";
      throw "wrong attribute: \"" + k + "\" not in S1";
      break;
    } // end switch

    i1.next();
  }

  is.next();
  return is;
}