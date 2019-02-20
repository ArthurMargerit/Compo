#pragma once

#include "Deployments/Deployment.hpp"


#include "Components/Math_P/Math_P.hpp"





    
#include "Links/Udp_server/Udp_server.hpp"
    



class Dep1 : public Deployment
{
 private:
  
  Math_P::Math_P mp;
  


  

  
  Udp_server lu;
  

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