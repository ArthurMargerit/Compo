#include "Data/Struct_Base1.hpp"
#include "Data/Struct_Base1_rev.hpp"
#include "Data/Struct_Base2.hpp"
#include "Data/Struct_Node.hpp"
#include "Data/code.hpp"

#include <memory>
#include <sstream>

int main(int argc, char *argv[]) {
  init_code();

  { // b1
    Base1 b1;
    b1.a_ea().set_pa(99);
    b1.a_ea().set_pb(99);
    std::cout << b1 << std::endl;

    b1.set_ep(&b1.a_ea());
    std::cout << b1 << std::endl;

    Elem e;
    b1.set_ep(&e);
    std::cout << b1 << "\n";
  }

  {
    // b1
    Base1_rev b1;
    b1.a_ea().set_pa(99);
    b1.a_ea().set_pb(99);
    std::cout << b1 << std::endl;

    b1.set_ep(&b1.a_ea());
    std::cout << b1 << std::endl;

    Elem e;
    b1.set_ep(&e);
    std::cout << b1 << "\n";
  }

  {
    // a* - a
    pNode pa;
    Node a;
    pa = &a;
    std::cout << a << "\n";
    std::cout << pa << "\n";
    std::cout << &pa << "\n";
  }

  {
    //       - b -
    // a - <       > - d
    //       - c -
    Node a, b, c, d;
    a.set_g(&b);
    a.set_d(&c);
    b.set_d(&d);
    c.set_g(&d);
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
    std::cout << d << "\n";

    std::cout << &a << "\n";
    std::cout << &b << "\n";
    std::cout << &c << "\n";
    std::cout << &d << "\n";

    Node n;
    std::stringstream ss;
    ss << a;
    ss >> n;

    std::cout <<"____"  << "\n";
    std::cout << a << "\n";
    std::cout <<" == "  << "\n";
    std::cout << n << "\n";
    std::cout <<"____"  << "\n";

    if(n.a_d() == NULL) {
      std::cerr << "Error 1";
      throw "Error 1";
    }

    if(n.a_g() == NULL) {
      std::cerr << "Error 2";
      throw "Error 2";
    }

    if(n.a_g()->a_d() != n.a_d()->a_g()) {
      std::cerr << "Error 3";
      throw "Error 3";
    }
  }


  {
    Node a,b,c,d;
    Node a1,b1,c1,d1;

    a.a_g() = &b;
    b.a_g() = &c;
    c.a_g() = &d;
    d.a_g() = &a;

    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
    std::cout << d << "\n";

    std::stringstream ss;
    ss << a << b << c << d;
    ss >> a1 >> b1 >> c1 >> d1; 
  }
  return 0;
}
