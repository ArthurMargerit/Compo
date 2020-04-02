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
    cc.r1.set(&cc.get_p1());
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
    ce.r1.set(&cd.get_p1());
    ce.r2.set(&cd.get_p1());
    ce.r3.set(&cd.get_p1());
    ce.r4.set(&cd.get_p1());
    ce.stop();

    // cf
    // ///////////////////////////////////////////////////////////////////////
    CF::CF cf;
    cf.configuration();
    cf.connection();

    cf.start();
    ce.r1.set(&cf.get_p1());
    ce.r1.set(&cf.get_p2());
    ce.r3.set(&cf.get_p3());
    ce.r4.set(&cf.get_p4());
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
    Require_helper* r1 = &ce.r1;
    r1->fake_it();


    // Fake* f2 = ce.r2.fake_it(// fs2,rs2
    //                       );
    // Fake* f3 = ce.r3.fake_it(// fs3,rs3
    //                       );
    // Fake* f4 = ce.r4.fake_it(// fs4,rs4
    //                          );
    ce.stop();
  }
  return 0;
}
