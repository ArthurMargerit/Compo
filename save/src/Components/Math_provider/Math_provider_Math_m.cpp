
#include "Components/Math_provider/Math_provider_Math_m.hpp"
#include "Components/Math_provider/Math_provider.hpp"

namespace Math_provider
{

  Math_m::Math_m(Math_provider* comp):composant(comp){
    return;
  }

  //! Destructor
  Math_m::~Math_m() noexcept {
        return;
  }

  // //! Move assignment operator
  // m& m::operator=(m &&other) noexcept
  //                       {

  //                       }
  int Math_m::add(int a,int b){
    
    return a+b;
    
  }
  int Math_m::time(int a,int b){
    
    return 0;
    
  }
  int Math_m::sub(int a,int b){
    
    return 0;
    
  }
  int Math_m::div(int a,int b){
    
    return 0;
    
  }
  int Math_m::power(int a,int b){
    
    return 0;
    
  }
  int Math_m::mod(int a,int b){
    
    return 0;
    
  }
}; // namespace Math_provider
