#include "Deployments/HelloWord_server/HelloWord_server.hpp"
#include <mutex>
#include <stdio.h>
#include <thread>

void wait(CompoMe::Deployment &a) {
  char ch;
  std::mutex m;
  m.lock();

  // main loop
  std::thread t([&m, &a]() {
    while (!m.try_lock()) {
      a.step();
    }
  });

  // cmd loop
  while (true) {
    std::string cmd;
    std::cin >> cmd;
    if (cmd == "exit") {
      m.unlock();
      break;
    } else {
      std::cout << "You need to write \"exit\"."
                << "\n";
    }
  }
  t.join();

  return;
}

int main(int argc, char *argv[]) {
  HelloWord_server a;
  a.init();
  a.configuration();
  a.link();
  a.start();

  std::cout << "Server is started... tape \"exit\""
            << "\n";
  wait(a);

  a.stop();
  a.quit();
  return 0;
}
