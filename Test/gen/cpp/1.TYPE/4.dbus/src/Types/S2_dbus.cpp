#include "Types/S2.hpp"
#include <dbus/dbus.h>

// DBus Message
DBusMessageIter &operator<<(DBusMessageIter &os, const S2 &pt) {
  DBusMessageIter sub_os;
  const E1 *t = pt.data();

  dbus_message_iter_open_container(&os, DBUS_TYPE_ARRAY,
                                   DBUS_TYPE_INT32_AS_STRING, &sub_os);
  dbus_message_iter_append_fixed_array(&sub_os, DBUS_TYPE_INT32, &t, pt.size());
  dbus_message_iter_close_container(&os, &sub_os);
  return os;
}

DBusMessageIter &operator>>(DBusMessageIter &is, S2 &pt) {

  DBusMessageIter sub_is;
  dbus_message_iter_recurse(&is, &sub_is);
  for (std::size_t i = 0; i < pt.size(); ++i) {
    sub_is >> pt[i];
  }

  dbus_message_iter_next(&is);

  return is;
}
