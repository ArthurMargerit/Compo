#include "Components/CA/CA.hpp"
#include "Components/CB/CB.hpp"
#include "Components/CC/CC.hpp"
#include "Components/CD/CD.hpp"
#include "Components/CE/CE.hpp"
#include "Components/CF/CF.hpp"

int main(int argc, char *argv[]) {
  {
    // ca
    // ///////////////////////////////////////////////////////////////////////
    CA::CA ca;
    ca.configuration();
    ca.connection();

    ca.start();
    int va = ca.get_a();
    ca.set_a(va + 5);
    ca.stop();
  }

  {
    // cb
    // ///////////////////////////////////////////////////////////////////////
    CB::CB cb;
    cb.configuration();
    cb.connection();

    cb.start();
    int vb1 = cb.f1(1);
    int vb2 = cb.f1(2);
    cb.stop();
  }

  {
    // cc
    // ///////////////////////////////////////////////////////////////////////
    CC::CC cc;
    cc.configuration();
    cc.connection();

    cc.start();
    cc.get_b();
    cc.set_b(2);
    cc.f1(1);
    cc.get_p1().call1();
    cc.set_r1(&cc.get_p1());
    cc.stop();
  }

  {
    // cd
    // ///////////////////////////////////////////////////////////////////////
    CD::CD cd;
    cd.configuration();
    cd.connection();

    cd.start();
    cd.get_p1().call1();
    cd.get_p2().call1();
    cd.get_p3().call1();
    cd.get_p4().call1();

    cd.stop();
  }

  {
    // ce
    // ///////////////////////////////////////////////////////////////////////
    CE::CE ce;
    CD::CD cd;

    ce.configuration();
    ce.connection();
    cd.configuration();
    cd.connection();

    ce.start();
    ce.set_r1(&cd.get_p1());
    ce.set_r2(&cd.get_p1());
    ce.set_r3(&cd.get_p1());
    ce.set_r4(&cd.get_p1());
    ce.stop();

    // cf
    // ///////////////////////////////////////////////////////////////////////
    CF::CF cf;
    cf.configuration();
    cf.connection();

    cf.start();
    ce.set_r1(&cf.get_p1());
    ce.set_r2(&cf.get_p2());
    ce.set_r3(&cf.get_p3());
    ce.set_r4(&cf.get_p4());
    cf.stop();
  }

  {
    // ce
    // ///////////////////////////////////////////////////////////////////////
    CE::CE ce;

    ce.configuration();
    ce.connection();
    // Function_string_stream fs1,fs2,fs3,fs4;
    // Return_string_stream rs1,rs2,rs3,rs4;

    ce.start();
    Fake* f1 = ce.fake_r1(// fs1,rs1
                          );
    Fake* f2 = ce.fake_r2(// fs2,rs2
                          );
    Fake* f3 = ce.fake_r3(// fs3,rs3
                          );
    Fake* f4 = ce.fake_r4(// fs4,rs4
                          );
    ce.stop();
  }
  return 0;
}
