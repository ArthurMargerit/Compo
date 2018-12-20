#pragma once

#include "Deployments/Deployment.hpp"


#include "Components/Math_provider/Math_provider.hpp"

#include "Components/Calc/Calc.hpp"





    
#include "Links/Simple.hpp"
    



class Dep3 : public Deployment
{
 private:
  
  Math_provider::Math_provider mp;
  
  Calc::Calc m1;
  


  

  
  Simple s1;
  

 public:

  Dep3();
  virtual ~Dep3();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};