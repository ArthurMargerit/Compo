#pragma once

#include "Interfaces/Caller_stream.hpp"
#include "Interfaces/Fake_stream.hpp"

#include "Components/Require_helper.hpp"
#include "Interfaces/Interface.hpp"

#include <map>
#include <string>
#include <vector>

namespace CompoMe {

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
  CompoMe::Require_helper *a_re;

public:
  virtual void set_out(CompoMe::Require_helper &re);
};

class Link_in {
private:
  CompoMe::Caller_stream *a_c = NULL;

public:
  CompoMe::Caller_stream &get_caller_stream();
  bool connected();
  virtual void set_in(CompoMe::Interface *to);
};

class Link_array_out {
protected:
  virtual void connect(CompoMe::Require_helper &p_i) = 0;
  virtual void disconnect(CompoMe::Require_helper &p_i) = 0;

private:
  std::vector<CompoMe::Require_helper *> a_f;

public:
  virtual void set_out(unsigned int p_id, CompoMe::Require_helper &p_req);
};

class Link_array_in {
private:
  std::vector<CompoMe::Caller_stream *> a_c;

public:
  virtual void set_in(unsigned int p_id, CompoMe::Interface *to);
};

class Link_map_out {
protected:
  virtual void connect(CompoMe::Require_helper &p_i) = 0;
  virtual void disconnect(CompoMe::Require_helper &p_i) = 0;

private:
  std::map<std::string, CompoMe::Require_helper *> a_f;

public:
  virtual void set_out(std::string p_key, CompoMe::Require_helper &p_req);
};

class Link_map_map_out {
protected:
  virtual void connect(CompoMe::Require_helper &p_i) = 0;
  virtual void disconnect(CompoMe::Require_helper &p_i) = 0;

private:
  std::map<std::string,std::map<std::string, CompoMe::Require_helper *>> a_f;

public:
  virtual void set_out(std::string p_key_c, std::string p_key_i,
                       CompoMe::Require_helper &p_req);
};

class Link_map_in {

private:
  std::map<std::string, CompoMe::Caller_stream *> a_c;

public:
  std::map<std::string, CompoMe::Caller_stream *> &get_map_of_caller_stream();
  virtual void set_in(std::string p_key, CompoMe::Interface *to);
};

class Link_map_map_in {

private:
  std::map<std::string, std::map<std::string, CompoMe::Caller_stream *>> a_c;

public:
  std::map<std::string, std::map<std::string, CompoMe::Caller_stream *>> &
  get_map_map_of_caller_stream();
  virtual void set_in(std::string p_key_c, std::string p_key_i, CompoMe::Interface *to);
};

} // namespace CompoMe
