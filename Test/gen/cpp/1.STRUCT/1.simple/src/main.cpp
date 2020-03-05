#include "Data/Struct_A.hpp"
#include "Data/Struct_A1.hpp"
#include "Data/Struct_B.hpp"
#include "Data/Struct_C.hpp"
#include "Data/Struct_Dot.hpp"
#include "Data/Struct_Pos.hpp"
#include "Data/Struct_Square.hpp"
#include "Data/code.hpp"

#include <memory>
#include <sstream>

template <typename T> void test_stream_simple(T t1) {
  T t2;
  try {

    std::stringstream ss;
    ss << t1;
    ss >> t2;
  } catch (const char *msg) {
    std::cerr << msg << " with " << &t1 << std::endl;
  }

  if (t1 == t2) {
    std::cout << "-> ok\n";
  } else {
    std::cerr << "t1 != t2 \n"
              << "t1= " << t1 << "\n"
              << "t2= " << t2 << "\n";
    throw "t1 != t2";
  }
}

template <typename T> void test_stream_pointer(T t1) {
  T *t2 = nullptr;

  try {
    std::stringstream ss;
    ss << &t1;
    ss >> t2;
  } catch (const char *msg) {
    std::cerr << "ERROR: " << msg << " with " << &t1 << std::endl;
  }

  if (t2 != NULL && t1 == *t2) {
    std::cout << "-> ok\n";
  } else {
    std::cerr << "t1 != t2 \n"
              << "t1= " << &t1 << "\n"
              << "t2= " << &t2 << std::endl;
    throw "t1 != t2";
  }

  if (t2 != NULL) {
    delete t2;
  }
}

template <typename T> void test_stream(T t1) {
  test_stream_simple(t1);
  test_stream_pointer(t1);
  return;
}

int main(int argc, char *argv[]) {
  init_code();

  {
    A a;
    test_stream(a);
    a.a = 18;
    test_stream(a);
  }

  {
    A1 a1;
    test_stream(a1);
    a1.a = 99;
    a1.b = 42;
    test_stream(a1);
  }

  {
    B b;
    test_stream(b);

    b.a0();

    int br1 = b.a1();
    int br2 = b.a2(1);
    int br3 = b.a3(1, 2);
    int br4 = b.a4(1, 2, 3);
  }

  {
    C c;
    test_stream(c);

    {
      c.a_a() = 1;
      c.a_b() = 2;

      if (c.a_a() != 1) {
        std::cerr << "a_... failed a: " << c.a_a();
        throw "get/set failed";
      }

      if (c.a_b() != 2) {
        std::cerr << "a_... failed b: " << c.a_b();
        throw "get/set failed";
      }
    }
    test_stream(c);

    {
      c.set_a(3);
      c.set_b(4);
      test_stream(c);
      if (c.get_a() != 3) {
        std::cerr << "get/set failed a: " << c.get_a();
        throw "get/set failed";
      }

      if (c.get_b() != 4) {
        std::cerr << "get/set failed b: " << c.get_b();
        throw "get/set failed";
      }
    }
    test_stream(c);
  }

  {
    Pos p;
    p.a_x() = 10;
    p.a_y() = 20;

    Dot d;
    d.a_h() = 30;
    d.a_w() = 40;

    Square s;
    s.a_position() = p;
    s.a_size() = d;
    test_stream(p);
    test_stream(d);
    test_stream(s);
  }

  {
    A *s1, *s2, *s3;
    A sa, sb, sc;
    sa.a_a() = 1;
    sb.a_a() = 2;
    sc.a_a() = 3;

    std::stringstream s;
    s << &sa << &sb << &sc;
    s >> s1 >> s2 >> s3;

    if(sa != *s1 || sb != *s2 || sc != *s3) {
      std::cerr << "Error in multi build" ;
    }
  }

  return 0;
}
