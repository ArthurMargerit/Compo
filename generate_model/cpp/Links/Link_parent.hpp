#pragma once

#include <Interfaces/Caller.hpp>
#include <Interfaces/Fake.hpp>
#include <Interfaces/Interface.hpp>
#include <string>

class Link {
public:
  virtual void step();
  virtual void connect();
  virtual void disconnect();

public:
  Link();
  virtual ~Link() noexcept;
};

class Link_out {
private:
  Fake *f = NULL;
public:
  virtual void set_out(Interface **from);
};

class Link_in {
private:
  Caller *c = NULL;
public:
  virtual void set_in(Interface *to);
};
