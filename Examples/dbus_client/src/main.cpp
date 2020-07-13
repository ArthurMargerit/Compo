#include "Components/Require_helper.hpp"


#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable.hpp"
#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl.hpp"
#include "Interfaces/org/mpris/MediaPlayer2/Player/Player.hpp"

#include "Links/Dbus_client/Dbus_client.hpp"

#include <dbus-cxx.h>
#include <dbus-cxx/pendingcall.h>
#include <unistd.h>

#define URL_STREAM                                                             \
  "https://www.radiantmediaplayer.com/media/big-buck-bunny-360p.mp4"

#define DBUS_VLC_DEST "org.mpris.MediaPlayer2.vlc"
#define DBUS_VLC_PATH  "/org/mpris/MediaPlayer2"
#define DBUS_VLC_INTERFACE "org.mpris.MediaPlayer2.Player"


int main(int argc, char *argv[]) {
  DBus::init();

  Dbus_client c;
  c.set_object_name("/compo/client");
  c.set_timeout(1000);
  c.connect();

  system("vlc -v &");
  sleep(1);
  {
    Require_helper_t<org::mpris::MediaPlayer2::Player> r;
    c.set_out(DBUS_VLC_DEST, DBUS_VLC_PATH, DBUS_VLC_INTERFACE, r);

    r->OpenUri(URL_STREAM);
    std::cout << "wait 5s ..."
              << "\n";
    sleep(5);

    for (int i = 0; i < 10; ++i) {
      std::cout << "Play/Pause"
                << "\n";
      r->PlayPause();
      sleep(1);
    }

    r->Stop();
    c.disconnect(r);
  }

  {
    Require_helper_t<org::mpris::MediaPlayer2::Ctl> r;
    c.set_out("org.mpris.MediaPlayer2.vlc", "/org/mpris/MediaPlayer2",
              "org.mpris.MediaPlayer2", r);
    r->Quit();
    c.disconnect(r);
  }

  c.disconnect();
  return 0;
}
