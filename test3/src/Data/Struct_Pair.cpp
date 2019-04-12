#include "Data/Types.hpp"

#include "Data/Struct_Pair.hpp"

#include <iostream>

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const Pair* c) {
  os << (Struct*) c;
  return os;
}

std::istream& operator>>(std::istream& is, Pair*& c) {
  std::string t = get_type(is);
  if(t != "Pair"
    
     ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <Pair>\n";
    
    }
  is >> (Struct*&) c;
  return is;
}


std::ostream& operator<<(std::ostream& os, const Pair& c)
{
  os << "{"
     << "type:"<<"Pair,"
     << "a:"<< c.a<<","
     << "b:"<< c.b
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, Pair& c)
{
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type,',');
  if (type != "Pair") {
    std::cerr << "ERREUR TYPE:"
              << ">Pair< != >" << type << "<" << std::endl;
  }
  
  is.ignore(100, ':') >> c.a ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.b ;
  is.ignore(1, '}');

  return is;
}


  Pair::Pair(int p_a,int p_b)
  :
    a(p_a),
    b(p_b)
  {

  }


  Pair::Pair()
  :
    a(0),
    b(0)
  {
  }
int
Pair::get_a() const {
    return this->a;
 }

void
Pair::set_a(const int value) {
  this->a = value;
}
int
Pair::get_b() const {
    return this->b;
 }

void
Pair::set_b(const int value) {
  this->b = value;
}

void Pair::to_stream(std::ostream& os) const {
  os << *this;
}