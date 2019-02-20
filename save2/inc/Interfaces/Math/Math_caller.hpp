#pragma once


#include <istream>
#include <ostream>

#include "Interfaces/Math/Math.hpp"
#include "Interfaces/Caller.hpp"


class Math_caller : public Caller
{
 private:
  Math& comp;

 public:

  Math_caller(Math& pcomp);

  bool call(std::istream& is, std::ostream& os);

 private:

  
  void add(std::istream& is, std::ostream& os);
  
  void time(std::istream& is, std::ostream& os);
  
  void sub(std::istream& is, std::ostream& os);
  
  void div(std::istream& is, std::ostream& os);
  
  void power(std::istream& is, std::ostream& os);
  
  void mod(std::istream& is, std::ostream& os);
  

  


};
