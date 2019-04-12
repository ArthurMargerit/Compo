#include "Data/Types.hpp"

#include "Data/Struct_B_1.hpp"

#include <iostream>

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const B_1* c) {
  os << (Struct*) c;
  return os;
}

std::istream& operator>>(std::istream& is, B_1*& c) {
  std::string t = get_type(is);
  if(t != "B_1"
    
     ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <B_1>\n";
    
    }
  is >> (Struct*&) c;
  return is;
}


std::ostream& operator<<(std::ostream& os, const B_1& c)
{
  os << "{"
     << "type:"<<"B_1,"<< "parrent:" << (B) c << ","
     << "t:"<< c.t
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, B_1& c)
{
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type,',');
  if (type != "B_1") {
    std::cerr << "ERREUR TYPE:"
              << ">B_1< != >" << type << "<" << std::endl;
  }
  is.ignore(100, ':') >> (B&) c;
  is.ignore(100, ':') >> c.t ;
  is.ignore(1, '}');

  return is;
}


  B_1::B_1(int p_t)
  :
    t(p_t)
  {

  }


  B_1::B_1()
  :
    t(0)
  {
  }
int
B_1::get_t() const {
    return this->t;
 }

void
B_1::set_t(const int value) {
  this->t = value;
}


void B_1::action1() {

  
return ;
}


void B_1::action2(int a) {

  
return ;
}


int B_1::action3() {

  
return 0;
}


int B_1::action4(int a) {

  
return 0;
}


int B_1::action5(int a,int b) {

  
return 0;
}



void B_1::to_stream(std::ostream& os) const {
  os << *this;
}