#include "Data/Types.hpp"

#include "Data/Struct_B_2.hpp"

#include <iostream>

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const B_2* c) {
  os << (Struct*) c;
  return os;
}

std::istream& operator>>(std::istream& is, B_2*& c) {
  std::string t = get_type(is);
  if(t != "B_2"
    
    && t != "B_2_1"
    
     ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <B_2>\n";
    
    std::cerr << "\t" << t << " is not one of child type {'B_2_1'}\n";
    
    }
  is >> (Struct*&) c;
  return is;
}


std::ostream& operator<<(std::ostream& os, const B_2& c)
{
  os << "{"
     << "type:"<<"B_2,"<< "parrent:" << (B) c << ","
     << "t2:"<< c.t2
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, B_2& c)
{
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type,',');
  if (type != "B_2") {
    std::cerr << "ERREUR TYPE:"
              << ">B_2< != >" << type << "<" << std::endl;
  }
  is.ignore(100, ':') >> (B&) c;
  is.ignore(100, ':') >> c.t2 ;
  is.ignore(1, '}');

  return is;
}


  B_2::B_2(int p_t2)
  :
    t2(p_t2)
  {

  }


  B_2::B_2()
  :
    t2(0)
  {
  }
int
B_2::get_t2() const {
    return this->t2;
 }

void
B_2::set_t2(const int value) {
  this->t2 = value;
}


void B_2::action1() {

  
return ;
}


void B_2::action2(int a) {

  
return ;
}


int B_2::action3() {

  
return 0;
}


int B_2::action4(int a) {

  
return 0;
}


int B_2::action5(int a,int b) {

  
return 0;
}



void B_2::to_stream(std::ostream& os) const {
  os << *this;
}