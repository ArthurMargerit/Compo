#pragma once

#include "Interfaces/Interface.hpp"
#include "Linkers/Linker.hpp"

class Deployment
{
private:
  std::vector<Linker> linkers;
  std::vector<Component> components;
public:

  Deployment();
  virtual ~Deployment();

  // LINKER ///////////////////////////////////////////////////////////////////
  void linker_list() const;
  void linker_add(Linker& l);

  // COMPONENT ////////////////////////////////////////////////////////////////
  void components_list();
  void components_add(Component& l) const;

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};
