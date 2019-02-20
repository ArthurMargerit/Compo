#pragma once

#include "Deployments/Deployment.hpp"


#include "Components/Calc/Calc.hpp"





    
#include "Links/Udp_client/Udp_client.hpp"
    



class Dep2 : public Deployment
{
 private:
  
  Calc::Calc mc;
  


  

  
  Udp_client l;
  

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