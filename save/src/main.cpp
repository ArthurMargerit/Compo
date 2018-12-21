#include "Deployments/Dep1.hpp"
#include "Deployments/Dep2.hpp"
#include "Deployments/Dep2.hpp"
#include <iostream>
#include <unistd.h>
#include <thread>


void test(){}

int main(int argc, char *argv[])
{
  Dep1 d;
  Dep2 d2;

  auto t1_code = [](Dep1* d)
                 {
                   // Dep2 d2;
                   d->init();
                   d->configuration();
                   d->link();
                   d->start();

                   while(true){
                     d->step();
                     usleep(500*1000);
                   }

                   d->stop();
                   d->quit();

                 };
  auto t2_code = [](Dep2* d)
                 {
                   d->init();
                   d->configuration();
                   d->link();
                   d->start();

                   while (true) {
                     d->step();
                     usleep(500*1000);
                   }

                   d->stop();
                   d->quit();

                 };

  std::thread t1(t1_code,&d);
  std::thread t2(t2_code,&d2);

  t1.join();
  t2.join();



  d2.stop();
  d2.quit();

  // return 0;
}
