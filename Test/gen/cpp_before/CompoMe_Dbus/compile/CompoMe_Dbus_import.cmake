FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(DBUS REQUIRED "dbus-cxx-1.0")
set(_include_directories ${_include_directories} ${DBUS_INCLUDE_DIRS})
