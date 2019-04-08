#include "Components/CA/CA.hpp"
#include "Components/CB/CB.hpp"
#include "Components/CC/CC.hpp"
#include "Components/CD/CD.hpp"
#include "Components/CE/CE.hpp"
#include "Components/CF/CF.hpp"


int main(int argc, char *argv[])
{
  {
  // ca ///////////////////////////////////////////////////////////////////////
  CA::CA ca;
  ca.configuration();
  ca.connection();

  ca.start();
  int va = ca.get_a();
  ca.set_a(va+5);
  ca.stop();
  }

  {
  // cb ///////////////////////////////////////////////////////////////////////
  CB::CB cb;
  cb.configuration();
  cb.connection();

  cb.start();
  int vb1 = cb.f1(1);
  int vb2 = cb.f1(2);
  cb.stop();
  }

  {
  // cc ///////////////////////////////////////////////////////////////////////
  CC::CC cc;
  cc.configuration();
  cc.connection();

  cc.start();
  cc.get_b();
  cc.set_b(2);
  cc.f1(1);
  cc.p1.call1();
  cc.r1  = &cc.p1;
  cc.stop();
  }

  {
  // cd ///////////////////////////////////////////////////////////////////////
  CD::CD cd;
  cd.configuration();
  cd.connection();

  cd.start();
  cd.p1.call1();
  cd.p2.call1();
  cd.p3.call1();
  cd.p4.call1();

  cd.stop();
  }

  {
  // ce ///////////////////////////////////////////////////////////////////////
    CE::CE ce;
    CD::CD cd;

  ce.configuration();
  ce.connection();
  cd.configuration();
  cd.connection();

  ce.start();
  ce.r1 = &cd.p1;
  ce.r2 = &cd.p1;
  ce.r3 = &cd.p1;
  ce.r4 = &cd.p1;
  ce.stop();
  }

  {
  // cf ///////////////////////////////////////////////////////////////////////
  CF::CF cf;
  cf.configuration();
  cf.connection();

  cf.start();
  cf.r1 = &cf.p1;
  cf.r2 = &cf.p2;
  cf.r3 = &cf.p3;
  cf.r4 = &cf.p4;
  cf.stop();
  }

  return 0;
}

