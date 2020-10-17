#include "catch.hpp"
#include "Types/Vec.hpp"
#include "Structs/A.hpp"
#include <sstream>
#include <string>

TEST_CASE( "Vec serialization to string", "[vector]") {
  Vec<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  std::stringstream ss;

  ss << a;
  CHECK(ss.str() == "[1,2,3]");
  a.pop_back();

  ss.str("");
  ss << a;
  CHECK(ss.str() == "[1,2]");
  a.pop_back();

  ss.str("");
  ss << a;
  CHECK(ss.str() == "[1]");
  a.pop_back();

  ss.str("");
  ss << a;
  CHECK(ss.str() == "[]");

}

TEST_CASE( "Vec Serialization from string", "[vector]") {
  Vec<int> a;
  std::stringstream ss;

  ss << "[11,22,33]";
  ss >> a;
  CHECK(a[0] == 11);
  CHECK(a[1] == 22);
  CHECK(a[2] == 33);

  ss << "[44,55,66]";
  ss >> a;
  CHECK(a[0] == 44);
  CHECK(a[1] == 55);
  CHECK(a[2] == 66);

  ss << "[]";
  ss >> a;
  CHECK(a.size() == 0);
}

TEST_CASE( "Vec Serialization from string and to string", "[vector]") {

  Vec<int> a;
  Vec<int> b;
  std::stringstream ss;
  for (int i = 0; i < 2000; i++) {
    a.push_back(rand()%6666);
  }
  ss << a;
  ss >> b;
  CHECK(a.size()==b.size());
  CHECK(a==b);
}


TEST_CASE( "Vec Serialization struct  from string and to string", "[vector]") {

  Vec<A> a;
  Vec<A> b;
  std::stringstream ss;
  for (int i = 0; i < 100; i++) {
    A p ;
    p.set_a(rand()%6666);
    p.set_b(rand()%6666);
    p.set_c(rand()%6666);
    CompoMe::String s;
    s.str = std::string(10, ' ');
for (int i = 0; i < 10; ++i) {
  s.str[i]=rand()%('Z'-'A')+'A';
 }
p.set_s(s);


    a.push_back(p);
  }

  ss << a;
  ss >> b;
  CHECK(a.size()==b.size());
  CHECK(a==b);
}

