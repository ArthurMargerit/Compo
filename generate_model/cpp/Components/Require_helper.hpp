#pragma once

#include "Interfaces/Fake.hpp"
#include "Interfaces/Interface.hpp"

#include <algorithm>
#include <vector>

class Fake;

class Require_helper {
public:
  virtual Fake *fake_it(Function_stream_send &fs, Return_stream_recv &rs) = 0;
  virtual void disconnect_it() = 0;
  virtual bool connected() = 0;
  virtual void set_i(Interface *p_i) = 0;

  void set_parent(Require_helper *p_parent) { this->parent = p_parent; }

protected:
  Require_helper *parent;
};

template <class T> class Require_helper_t : public Require_helper {
private:
  T *a_i;
  std::vector<Require_helper *> a_child;

public:
  Require_helper_t(T *p_i = NULL) { this->set(p_i); }

  std::ostream &operator<<(std::ostream &os) { return os; }

  Fake *fake_it(Function_stream_send &fs, Return_stream_recv &rs) override {
    auto f = new typename T::MyFake(fs, rs);
    this->set(f);
    return f;
  }

  void disconnect_it() override {
    this->set(NULL);
    this->set_parent(NULL);
  }

  bool connected() override { return this->a_i != NULL; }

  T *operator->() {
    if (!this->connected()) {
      throw "not connected";
    }

    return this->a_i;
  }

  void set_i(Interface *p_i) override {
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
    for (auto i_c : this->a_child) {
      i_c->set_i(this->a_i);
    }
  }

  void child_connect(Require_helper *c) {
    c->set_i(this->a_i);
    c->set_parent(this);
    this->a_child.push_back(c);
  }

  void child_disconnect(Require_helper *c) {
    c->disconnect_it();

    this->a_child.erase(
        std::remove(this->a_child.begin(), this->a_child.end(), c),
        this->a_child.end());
  }
};
