#include "Data/Struct_fac_dT0.hpp"

#include <iostream>


#include "Data/Struct_dT0.hpp"

#include "Data/Struct_fac.hpp"


dT0_fac::dT0_fac() {
  std::cout << "--dT0 build" << "\n";
  this->init();
                      }

dT0_fac::~dT0_fac(){

                       }


dT0* dT0_fac::build(const std::string& p_type, std::istream& p_stream) {

  if (p_type == "dT0") {
    std::cout << "build of dT0*" << "\n";
    dT0* b = new dT0();
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


void dT0_fac::init() {

    
    Struct_fac::Build_fac_f  f= [](const std::string& str,std::istream& p_s)
                                {return (Struct*) dT0_fac::get_inst().build(str,p_s); };

    Struct_fac::get_inst().subscribe("dT0", f);

    
  }


 void dT0_fac::subscribe(const std::string& ss, Build_fac_f v) {

   this->childs[ss] = v;

   std::cout << "subscribe of "
             << ss
             << " in dT0.\n";

   
   Struct_fac::get_inst().subscribe(ss, v);
   
 }


std::ostream& operator<<(std::ostream& os, const dT0* c) {
  os << (Struct*) c;
  return os;
}

std::istream& operator>>(std::istream& is, dT0*& c) {
  std::string t = get_type(is);

  if(c== NULL) {
    delete c;
  }

  c = dT0_fac::get_inst().build(t,is);

  return is;
}