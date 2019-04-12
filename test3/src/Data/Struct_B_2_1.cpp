#include "Data/Types.hpp"

#include "Data/Struct_B_2_1.hpp"

#include <iostream>

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const B_2_1* c) {
  os << (Struct*) c;
  return os;
}

std::istream& operator>>(std::istream& is, B_2_1*& c) {
  std::string t = get_type(is);
  if(t != "B_2_1"
    
     ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <B_2_1>\n";
    
    }
  is >> (Struct*&) c;
  return is;
}


std::ostream& operator<<(std::ostream& os, const B_2_1& c)
{
  os << "{"
     << "type:"<<"B_2_1,"<< "parrent:" << (B_2) c << ","
     << "t3:"<< c.t3
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, B_2_1& c)
{
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type,',');
  if (type != "B_2_1") {
    std::cerr << "ERREUR TYPE:"
              << ">B_2_1< != >" << type << "<" << std::endl;
  }
  is.ignore(100, ':') >> (B_2&) c;
  is.ignore(100, ':') >> c.t3 ;
  is.ignore(1, '}');

  return is;
}


  B_2_1::B_2_1(int p_t3)
  :
    t3(p_t3)
  {

  }


  B_2_1::B_2_1()
  :
    t3(0)
  {
  }
int
B_2_1::get_t3() const {
    return this->t3;
 }

void
B_2_1::set_t3(const int value) {
  this->t3 = value;
}
void B_2_1::action6() {

  
return ;
}






void B_2_1::action1() {

  
return ;
}


void B_2_1::action2(int a) {

  
return ;
}


int B_2_1::action3() {

  
return 0;
}


int B_2_1::action4(int a) {

  
return 0;
}


int B_2_1::action5(int a,int b) {

  
return 0;
}



void B_2_1::to_stream(std::ostream& os) const {
  os << *this;
}