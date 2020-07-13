#pragma once

#include "Interfaces/Caller_stream.hpp"
#include "Interfaces/Fake_stream.hpp"

#include "Interfaces/Interface.hpp"
#include "Components/Require_helper.hpp"

#include <string>
#include <vector>
#include <map>

class Link {
public:
  virtual void step();
  virtual void configuration();
  virtual void connect();
  virtual void disconnect();

public:
  Link();
  virtual ~Link() noexcept;
};

class Link_out {
protected:
  Require_helper *a_re;

public:
  virtual void set_out(Require_helper &re);
};

class Link_in {
private:
  Caller_stream *a_c = NULL;

public:
  Caller_stream &get_caller_stream();
  bool connected();
  virtual void set_in(Interface *to);
};

class Link_array_out {
protected:
  virtual void connect(Require_helper& p_i) = 0;
  virtual void disconnect(Require_helper& p_i) = 0;

private:
  std::vector<Require_helper *> a_f;

public:
  virtual void set_out(unsigned int p_id, Require_helper &p_req);
};

class Link_array_in {
private:
  std::vector<Caller_stream *> a_c;

protected:
  virtual void connect(Require_helper& p_i) = 0;
  virtual void disconnect(Require_helper& p_i) = 0;

public:
  virtual void set_in(unsigned int p_id, Interface *to);
};

class Link_map_out {
protected:
  virtual void connect(Require_helper& p_i) = 0;
  virtual void disconnect(Require_helper& p_i) = 0;

private:
  std::map<std::string, Require_helper *> a_f;

public:
  virtual void set_out(std::string p_key, Require_helper &p_req);
};

class Link_map_in {
protected:
  virtual void connect(Require_helper& p_i) = 0;
  virtual void disconnect(Require_helper& p_i) = 0;

private:
  std::map<std::string, Caller_stream *> a_c;

public:
  virtual void set_in(std::string p_key, Interface *to);
};
