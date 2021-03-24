#pragma once

#include "Interfaces/Caller_json.hpp"
#include "Interfaces/Fake_json.hpp"

#include "Components/Require_helper.hpp"
#include "Interfaces/Interface.hpp"

#include <map>
#include <string>
#include <vector>

namespace CompoMe {

class Link_json_out {
  protected:
    CompoMe::Require_helper *a_re;

  public:
    virtual ~Link_json_out() {}
    virtual void set_out(CompoMe::Require_helper &re);
};

class Link_json_in {
  private:
    CompoMe::Caller_json *a_c = NULL;

  public:
    virtual ~Link_in() {}
    CompoMe::Caller_json &get_caller_json();
    bool connected();
    virtual void set_in(CompoMe::Interface *to);
  };

class Link_map_json_in {
  private:
    std::map<std::string, CompoMe::Caller_json *> a_c;

  public:
    virtual ~Link_map_in() {}
    std::map<std::string, CompoMe::Caller_json *> &get_map_of_caller_json();
    virtual void set_in(std::string p_key, CompoMe::Interface *to);
};

class Link_map_json_out {
  protected:
    virtual void connect(CompoMe::Require_helper &p_i) = 0;
    virtual void disconnect(CompoMe::Require_helper &p_i) = 0;

  public:
    virtual ~Link_map_out() {}
    virtual void set_out(std::string p_key, CompoMe::Require_helper &p_req);

  private:
    std::map<std::string, CompoMe::Require_helper *> a_f;

  };

class Link_map_map_json_in {
  private:
    std::map<std::string, std::map<std::string, CompoMe::Caller_json *>> a_c;

  public:
    virtual ~Link_map_map_json_in() {}
    std::map<std::string, std::map<std::string, CompoMe::Caller_json *>> &
    get_map_map_of_caller_json();
    virtual void set_in(std::string p_key_c, std::string p_key_i, CompoMe::Interface *to);
};

  class Link_map_map_json_out {
  protected:
    virtual void connect(CompoMe::Require_helper &p_i) = 0;
    virtual void disconnect(CompoMe::Require_helper &p_i) = 0;

  private:
    std::map<std::string,std::map<std::string, CompoMe::Require_helper *>> a_f;

  public:
    virtual ~Link_map_map_out() {}
    virtual void set_out(std::string p_key_c, std::string p_key_i,
                         CompoMe::Require_helper &p_req);
  };

} // namespace CompoMe
