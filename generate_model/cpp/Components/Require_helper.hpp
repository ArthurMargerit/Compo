#pragma once

#include "Interfaces/Interface.hpp"
#include "Serialization_context.hpp"
#include <vector>

#include <algorithm>
#include <cstdlib>
#include <string>
#include <typeinfo>

namespace CompoMe {
class Fake_stream;
class Fake_dbus;
class Fake_json;

class Function_dbus_send;
class Return_dbus_recv;
class Function_stream_send;
class Return_stream_recv;
class Function_json_send;
class Return_json_recv;

class Require_helper {
public:
  virtual ~Require_helper(){};

  virtual Fake_stream *fake_stream_it(Function_stream_send &fs,
                                      Return_stream_recv &rs) = 0;
  virtual Fake_dbus *fake_dbus_it(Function_dbus_send &fs,
                                  Return_dbus_recv &rs) = 0;
  virtual Fake_json *fake_json_it(Function_json_send &fs,
                                  Return_json_recv &rs) = 0;

  virtual void disconnect_it() = 0;
  virtual bool connected() = 0;
  virtual void set_i(Interface *p_i) = 0;
  virtual std::string type() = 0;

  void set_parent(Require_helper *p_parent) { this->parent = p_parent; }

  std::ostream &operator<<(std::ostream &os) const { return os; }

  virtual std::istream &from_stream(std::istream &is,
                                    Serialization_context_import &p_ctx) = 0;
  virtual std::ostream &
  to_stream(std::ostream &os, Serialization_context_export &p_ctx) const = 0;
  virtual CompoMe::Interface& get_i()= 0;
protected:
  Require_helper *parent;
};

template <class T> class Require_helper_t : public Require_helper {

private:
  T *a_i;
  std::vector<Require_helper *> a_child;

public:
  Require_helper_t() : Require_helper_t(NULL){}
  virtual ~Require_helper_t() noexcept {}
  Require_helper_t(T *p_i) { this->set(p_i); }

  Fake_stream *fake_stream_it(Function_stream_send &fs,
                              Return_stream_recv &rs) override {
    auto f = T::get_fake_stream(fs, rs);
    this->set(std::get<2>(f));
    return std::get<1>(f);
  }

  Fake_dbus *fake_dbus_it(Function_dbus_send &fs,
                          Return_dbus_recv &rs) override {
    auto f = T::get_fake_dbus(fs, rs);
    this->set(std::get<2>(f));
    return std::get<1>(f);
  }

  Fake_json *fake_json_it(Function_json_send &fs,
                          Return_json_recv &rs) override {
    auto f = T::get_fake_json(fs, rs);
    this->set(std::get<2>(f));
    return std::get<1>(f);
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

  std::ostream &to_stream(std::ostream &os,
                          Serialization_context_export &p_ctx) const override {
    os << "0";
    // TODO
    return os;
  }

  std::istream &from_stream(std::istream &is,
                            Serialization_context_import &p_ctx) override {
    int i;
    is >> i;
    // TODO
    return is;
  }

  T& get() {
    return *this->a_i;
  }

  virtual CompoMe::Interface& get_i(){return *this->a_i;}
  
  std::string type() override {
    return typeid(T).name();
  }
};

} // namespace CompoMe
