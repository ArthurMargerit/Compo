set(compo_project_name "dbus_client")
set(compo_lib_name "file")

set(src_file src/Data/file.cpp 
src/Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable.cpp 
src/Interfaces/org/mpris/MediaPlayer2/Player/Player.cpp 
src/Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl.cpp 
src/Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_fake_stream.cpp 
src/Interfaces/org/mpris/MediaPlayer2/Player/Player_fake_stream.cpp 
src/Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_fake_stream.cpp 
src/Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_fake_dbus.cpp 
src/Interfaces/org/mpris/MediaPlayer2/Player/Player_fake_dbus.cpp 
src/Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_fake_dbus.cpp 
src/Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_caller_stream.cpp 
src/Interfaces/org/mpris/MediaPlayer2/Player/Player_caller_stream.cpp 
src/Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_caller_stream.cpp 
src/Links/Link_dbus.cpp)

set(inc_file inc/Data/file.hpp 
inc/Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable.hpp 
inc/Interfaces/org/mpris/MediaPlayer2/Player/Player.hpp 
inc/Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl.hpp 
inc/Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_fake_stream.hpp 
inc/Interfaces/org/mpris/MediaPlayer2/Player/Player_fake_stream.hpp 
inc/Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_fake_stream.hpp 
inc/Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_fake_dbus.hpp 
inc/Interfaces/org/mpris/MediaPlayer2/Player/Player_fake_dbus.hpp 
inc/Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_fake_dbus.hpp 
inc/Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_caller_stream.hpp 
inc/Interfaces/org/mpris/MediaPlayer2/Player/Player_caller_stream.hpp 
inc/Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_caller_stream.hpp 
inc/Links/Link_dbus.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
