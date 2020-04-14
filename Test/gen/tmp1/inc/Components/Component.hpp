#pragma once
#include <functional>

class Fake;

class Component {
public:
  Component();
  virtual ~Component();

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void step();
  virtual void stop();
  virtual void status();
};

#include "Interfaces/Interface.hpp"
#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

#include <algorithm>
#include <vector>

class Require_helper {
public:
  virtual Fake *fake_it(Function_stream& fs, Return_stream& rs) = 0;
  virtual void disconnect_it() = 0;
  virtual bool connected() = 0;
  virtual void set_i(Interface *p_i) = 0;
};

template <class T> class Require_helper_t : public Require_helper {
private:
  T *a_i;
  std::vector<Require_helper *> v;

public:
  Require_helper_t(T *p_i = NULL) { this->set(p_i); }

  std::ostream &operator<<(std::ostream &os) { return os; }

  virtual Fake *fake_it(Function_stream& fs, Return_stream& rs) {

    typename T::MyFake* f = new typename T::MyFake(fs, rs);
    this->set(f);
    return f;
  }

  virtual void disconnect_it() { this->set(NULL); }

  virtual bool connected() { return this->a_i != NULL; }

  T *operator->() { return this->a_i; }

  void set_i(Interface *p_i) {
    if (p_i == NULL) {
      this->set(NULL);
      return;
    }

    T *l_i = dynamic_cast<T *>(p_i);

    if (l_i == NULL) {
      throw "Error wrong connection";
    }

    this->set(l_i);
  }

  void set(T *p_i) {
    this->a_i = p_i;
    for (auto i_c : this->v) {
      i_c->set_i(this->a_i);
    }
  }

  void child_connect(Require_helper *c) {
    c->set_i(this->a_i);
    this->v.push_back(c);
  }

  void child_disconnect(Require_helper *c) {
    c->set_i(NULL);
    this->v.erase(std::remove(this->v.begin(), this->v.end(), c), v.end());
  }
};
