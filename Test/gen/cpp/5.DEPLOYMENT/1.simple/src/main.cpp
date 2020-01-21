#include "Deployments/D0/D0.hpp"
#include "Deployments/D0_c/D0_c.hpp"
#include "Deployments/D0_l/D0_l.hpp"
#include "Deployments/D1/D1.hpp"
#include "Deployments/D1_c/D1_c.hpp"
#include "Deployments/D1_l/D1_l.hpp"
#include "Deployments/D2/D2.hpp"
#include "Deployments/D2_c/D2_c.hpp"
#include "Deployments/D3/D3.hpp"
#include "Deployments/D3_c/D3_c.hpp"
#include "Deployments/D4_c/D4_c.hpp"
#include "Deployments/D_BIG/D_BIG.hpp"



void extract(Deployment* d) {

  d->init();
  d->configuration();
  d->link();

  d->start();
  for (int i = 0; i < 1000; ++i) {
    d->step();
  }
  d->stop();

  d->quit();
}

int main(int argc, char *argv[]) {
  D0 da;
  D0_c db;
  D0_l dc;

  D1 dd;
  D1_c de;
  D1_l df;

  D2 dg;
  D2_c dh;

  D3 di;
  D3_c dj;

  D4_c dk;

  D_BIG dl;

  extract(&da);
  extract(&db);
  extract(&dc);
  extract(&dd);
  extract(&de);
  extract(&df);
  extract(&dg);
  extract(&dh);
  extract(&dj);
  extract(&dk);
  extract(&dl);
  

  return 0;
}
