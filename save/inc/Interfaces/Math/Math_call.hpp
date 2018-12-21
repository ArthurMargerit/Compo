#pragma once


#include <istream>
#include <ostream>

#include "Interfaces/Math/Math.hpp"
#include "Interfaces/Caller.hpp"

constexpr unsigned int str2int(const char* str, int h = 0)
{
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

class Math_caller : public Caller
{
 private:

  Math& comp;

 public:

  Math_caller(Math& pcomp)
 : comp(pcomp)
 {

   return ;
 }


  bool call(std::istream& is, std::ostream& os)
       {

         std::string name_function;

         std::getline(is, name_function, '(');

         switch(str2int(name_function.c_str())){
           
         case str2int("add"):
           this->add(is, os);
           return true;
           break;
           
         case str2int("time"):
           this->time(is, os);
           return true;
           break;
           
         case str2int("sub"):
           this->sub(is, os);
           return true;
           break;
           
         case str2int("div"):
           this->div(is, os);
           return true;
           break;
           
         case str2int("power"):
           this->power(is, os);
           return true;
           break;
           
         case str2int("mod"):
           this->mod(is, os);
           return true;
           break;
           
           
         };

         std::getline(is, name_function);

         return false;
       }

 private:

  
  void add(std::istream& is, std::ostream& os)
  {
    
    int l_a;
    is >> l_a;is.get();

    
    int l_b;
    is >> l_b;

    

    std::string l;
    std::getline(is, l);

    os << this->comp.add(l_a, l_b) << std::endl;

    return;
  }
  
  void time(std::istream& is, std::ostream& os)
  {
    
    int l_a;
    is >> l_a;is.get();

    
    int l_b;
    is >> l_b;

    

    std::string l;
    std::getline(is, l);

    os << this->comp.time(l_a, l_b) << std::endl;

    return;
  }
  
  void sub(std::istream& is, std::ostream& os)
  {
    
    int l_a;
    is >> l_a;is.get();

    
    int l_b;
    is >> l_b;

    

    std::string l;
    std::getline(is, l);

    os << this->comp.sub(l_a, l_b) << std::endl;

    return;
  }
  
  void div(std::istream& is, std::ostream& os)
  {
    
    int l_a;
    is >> l_a;is.get();

    
    int l_b;
    is >> l_b;

    

    std::string l;
    std::getline(is, l);

    os << this->comp.div(l_a, l_b) << std::endl;

    return;
  }
  
  void power(std::istream& is, std::ostream& os)
  {
    
    int l_a;
    is >> l_a;is.get();

    
    int l_b;
    is >> l_b;

    

    std::string l;
    std::getline(is, l);

    os << this->comp.power(l_a, l_b) << std::endl;

    return;
  }
  
  void mod(std::istream& is, std::ostream& os)
  {
    
    int l_a;
    is >> l_a;is.get();

    
    int l_b;
    is >> l_b;

    

    std::string l;
    std::getline(is, l);

    os << this->comp.mod(l_a, l_b) << std::endl;

    return;
  }
  

  


};
