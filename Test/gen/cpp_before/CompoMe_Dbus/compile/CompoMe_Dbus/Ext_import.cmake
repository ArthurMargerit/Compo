FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(DBUS REQUIRED "dbus-cxx-1.0")
list(APPEND _include_directories ${DBUS_INCLUDE_DIRS})
