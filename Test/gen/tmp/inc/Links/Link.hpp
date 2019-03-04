#pragma once

#include <string>
#include <Interfaces/Interface.hpp>
#include <Interfaces/Fake.hpp>
#include <Interfaces/Caller.hpp>

class Link
{
public:
  virtual void step()=0;
  virtual void connect()=0;
  virtual void disconnect()=0;

  public:
  Link();
  virtual ~Link() noexcept;
};

class Link_from{
protected:
  Fake* f;
public:
  virtual void set_from(Interface** from)=0;
};

class Link_to{
protected:
  Caller* c;
public:
  virtual void set_to(Interface* to)=0;
};

class Link_direct
{
  virtual void set_from_to(Interface** from, Interface* to)=0;
};

