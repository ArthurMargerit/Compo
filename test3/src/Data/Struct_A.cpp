#include "Data/Types.hpp"

#include "Data/Struct_A.hpp"

#include <iostream>

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const A* c) {
  os << (Struct*) c;
  return os;
}

std::istream& operator>>(std::istream& is, A*& c) {
  std::string t = get_type(is);
  if(t != "A"
    
     ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <A>\n";
    
    }
  is >> (Struct*&) c;
  return is;
}


std::ostream& operator<<(std::ostream& os, const A& c)
{
  os << "{"
     << "type:"<<"A,"
     << "a:"<< c.a<<","
     << "b:"<< c.b
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, A& c)
{
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type,',');
  if (type != "A") {
    std::cerr << "ERREUR TYPE:"
              << ">A< != >" << type << "<" << std::endl;
  }
  
  is.ignore(100, ':') >> c.a ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.b ;
  is.ignore(1, '}');

  return is;
}


  A::A(int p_a,int p_b)
  :
    a(p_a),
    b(p_b)
  {

  }


  A::A()
  :
    a(0),
    b(0)
  {
  }
int
A::get_a() const {
    return this->a;
 }

void
A::set_a(const int value) {
  this->a = value;
}
int
A::get_b() const {
    return this->b;
 }

void
A::set_b(const int value) {
  this->b = value;
}

void A::to_stream(std::ostream& os) const {
  os << *this;
}