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
  std::pair<Interface **, Build_fake_F> a_f;
public:
  virtual void set_out(Interface **from,Build_fake_F& bf);
};

class Link_in {
private:
  Caller *a_c = NULL;
public:
  virtual void set_in(Interface *to);
};

class Link_array_out {
private:
  std::vector<std::pair<Interface **, Build_fake_F>> a_f;
public:
  virtual void set_out(unsigned int p_id, Interface **from, Build_fake_F& bf);
};

class Link_array_in {
private:
  std::vector<Caller*> a_c;
public:
  virtual void set_in(unsigned int p_id,Interface *to);
};

class Link_map_out {
private:
  std::map<std::string, std::pair<Interface **, Build_fake_F> > a_f;
public:
  virtual void set_out(std::string p_key, Interface **from, Build_fake_F& bf);
};

class Link_map_in {
private:
  std::map<std::string, Caller*> a_c;
public:
  virtual void set_in(std::string p_key, Interface *to);
};
