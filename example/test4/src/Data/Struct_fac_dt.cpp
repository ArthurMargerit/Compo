#include "Data/Struct_fac_dt.hpp"

#include <iostream>


#include "Data/Struct_dt.hpp"

#include "Data/Struct_fac.hpp"


dt_fac::dt_fac() {
  std::cout << "--dt build" << "\n";
  this->init();
                      }

dt_fac::~dt_fac(){

                       }


dt* dt_fac::build(const std::string& p_type, std::istream& p_stream) {

  if (p_type == "dt") {
    std::cout << "build of dt*" << "\n";
    dt* b = new dt();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second(p_type, p_stream);
  }

  std::cerr << "Error: of Struct* build" << std::endl;
  std::cerr << "Your type \""
            << p_type
            << "\" is not include or not init as a child."
            << std::endl;

  return NULL;
}


void dt_fac::init() {

    
    Struct_fac::Build_fac_f  f= [](const std::string& str,std::istream& p_s)
                                {return (Struct*) dt_fac::get_inst().build(str,p_s); };

    Struct_fac::get_inst().subscribe("dt", f);

    
  }


 void dt_fac::subscribe(const std::string& ss, Build_fac_f v) {

   this->childs[ss] = v;

   std::cout << "subscribe of "
             << ss
             << " in dt.\n";

   
   Struct_fac::get_inst().subscribe(ss, v);
   
 }


std::ostream& operator<<(std::ostream& os, const dt* c) {
  os << (Struct*) c;
  return os;
}

std::istream& operator>>(std::istream& is, dt*& c) {
  std::string t = get_type(is);

  if(c== NULL) {
    delete c;
  }

  c = dt_fac::get_inst().build(t,is);

  return is;
}