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

class Require_helper {
public:
  virtual Fake *fake_it() = 0;
  virtual void disconnect_it() = 0;
  virtual bool connected() = 0;
};

template <class T>
class Require_helper_t: public Require_helper {
private:
  T *a_i;

public:
  Require_helper_t(T* p_i = NULL) {
    this->set(p_i);
  }

  std::ostream &operator<<(std::ostream &os) {
    return os;
  }

  virtual Fake *fake_it() {
    Fake *f = new typename T::MyFake();
    return NULL;
  }

  virtual void disconnect_it() { this->a_i = NULL; }

  virtual bool connected() { return this->a_i != NULL; }

  T *operator->() { return this->a_i; }

  void set(T *p_i) { this->a_i = p_i; }
};
