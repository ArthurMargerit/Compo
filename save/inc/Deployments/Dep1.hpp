#pragma once

#include "Deployments/Deployment.hpp"


#include "Components/Math_provider/Math_provider.hpp"





    
#include "Links/Fifo_in.hpp"
    



class Dep1 : public Deployment
{
 private:
  
  Math_provider::Math_provider mp;
  


  

  
  Fifo_in l1;
  

 public:

  Dep1();
  virtual ~Dep1();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};