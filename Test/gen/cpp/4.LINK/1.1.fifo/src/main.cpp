#include "Deployments/D_sync_server/D_sync_server.hpp"

int main(int argc, char *argv[]) {
  D_sync_server ds;
  ds.init();
  ds.configuration();
  ds.link();
  ds.start();
  ds.stop();
  ds.quit();

  return 0;
}
