#pragma once

class Interface;

class Linker {
private:
  Interface* to;
public:
  Linker();
  virtual ~Linker();

  virtual void step() = 0;

  virtual void set_to(Interface* pto);
  virtual Interface* get_to();
};
