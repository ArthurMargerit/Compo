#pragma once

#include <vector>

#include "Components/Component.hpp"
#include "Links/Link.hpp"

namespace CompoMe {
class Deployment {
private:
  std::vector<Link *> links;
  std::vector<Component *> components;

public:
  Deployment();
  virtual ~Deployment();

  // LINKER ///////////////////////////////////////////////////////////////////
  void link_list() const;
  void link_add(Link *l);

  // COMPONENT ////////////////////////////////////////////////////////////////
  void components_list() const;
  void components_add(Component *l);

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
  virtual void step();
};
} // namespace CompoMe
