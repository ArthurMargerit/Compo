#pragma once

#include "Deployments/Deployment.hpp"


#include "Components/Calc/Calc.hpp"

#include "Components/Calc/Calc.hpp"

#include "Components/Math_provider/Math_provider.hpp"





    
#include "Links/Simple.hpp"
    

    
#include "Links/Fifo_out.hpp"
    



class Dep2 : public Deployment
{
 private:
  
  Calc::Calc m1;
  
  Calc::Calc m2;
  
  Math_provider::Math_provider mp;
  


  

  
  Simple s;
  
  Fifo_out l1;
  

 public:

  Dep2();
  virtual ~Dep2();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};