// #include <sstream>

#include "Deployments/Dep_on_kitchen/Dep_on_kitchen.hpp"
#include "CompoMe/Log.hpp"
#include <mutex>
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
  Dep_on_kitchen d;

  d.init();
  d.configuration();
  d.link();

  d.start();

  wait(d);
  //d.step();

  d.stop();
  d.quit();

  return 0;
}
