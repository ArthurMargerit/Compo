#include "Data/Struct_A.hpp"
#include "Data/Struct_fac_A.hpp"
#include "Data/Struct_fac.hpp"
#include "Data/Struct_A1.hpp"
#include "Data/Struct_B.hpp"
#include "Data/Struct_C.hpp"

#include "Data/Struct_Pos.hpp"
#include "Data/Struct_Dot.hpp"
#include "Data/Struct_Square.hpp"
#include "Data/Struct_Tree.hpp"

#include <sstream>
#include <memory>

template<typename T>
void test_stream(T t1)
{
  T t2;
  std::stringstream ss;
  ss << t1;
  ss >> t2;
  //  if(t1 == t2){}else{}

  return ;
}


int main(int argc, char *argv[])
{
  A a;
  a.a = 1;
  test_stream(a);

  A1 a1;
  a1.a = 1;
  a1.b = 1;
  test_stream(a1);

  B b;
  b.a0();
  int br1 = b.a1();
  int br2 = b.a2(1);
  int br3 = b.a3(1,2);
  int br4 = b.a4(1,2,3);
  test_stream(a1);

  C c;
  Pos p;
  Dot d;
  Square s;

  Tree t,tg,td,tgg,tgd,tdg,tdd;
  t.g = &tg;
  t.d = &td;
  tg.g = &tgg;
  tg.d = &tgd;
  td.g = &tdg;
  td.d = &tdd;

  tgg.g = NULL;
  tgd.g = NULL;
  tdg.g = NULL;
  tdd.g = NULL;

  tgg.d = NULL;
  tgd.d = NULL;
  tdg.d = NULL;
  tdd.d = NULL;

  t.e = NULL;
  tg.e = &t;
  td.e = &t;
  tgg.e = &tg;
  tgd.e = &tg;
  tdg.e = &td;
  tdd.e = &td;

  std::stringstream ss;
  A aa;
  ss << &aa;
  std::shared_ptr<A> sa;
  ss >> sa;

  ss << &aa;
  std::shared_ptr<Struct> spa;
  ss >> spa;

  return 0;
}
