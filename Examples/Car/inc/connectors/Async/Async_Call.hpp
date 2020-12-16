#pragma once

#include <ctime>
#include <future>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <thread>

namespace CompoMe {
namespace Async {

// generic implementation of a async call without type (design to be virtual)
class Async_Call_g {
private:
  static unsigned int get_new_id() {
    static unsigned int i = 0;
    i++;
    return i;
  }

protected:
  std::string a_func_name;
  std::string a_type;
  std::chrono::time_point<std::chrono::system_clock> a_start;
  std::chrono::microseconds a_timeout;
  unsigned int a_id_exec;

  Async_Call_g(const std::string &p_f_name, const std::string &p_r_type,
               int timeout_ms = 5000)
      : a_func_name(p_f_name), a_type(p_r_type),
        a_start(std::chrono::system_clock::now()), a_timeout(timeout_ms * 1000),
        a_id_exec(Async_Call_g::get_new_id()) {}

public:
  virtual ~Async_Call_g() {}
  unsigned int id() { return this->a_id_exec; };

  virtual std::string state() {
    auto t = std::chrono::system_clock::to_time_t(this->a_start);
    auto t1 = std::localtime(&t);

    std::stringstream ss;
    ss << "-"
       << " " << this->a_func_name << " -> " << this->a_type << " at "
       << std::put_time(t1, "%H:%M:%S")
       << " T: " << std::chrono::microseconds(this->a_timeout).count()
       << " S: " << f_state();
    return ss.str();
  }

  std::string f_state() {
    return (this->finish() ? "finish" : (this->timeout()) ? "timeout" : "wait");
  }

  virtual bool finish() = 0;
  virtual bool timeout() {
    auto t = std::chrono::system_clock::now() - this->a_start;
    return std::chrono::duration_cast<std::chrono::microseconds>(t) >
           this->a_timeout;
  }

  virtual void release() = 0;
};

// Implementation for all type
template <typename T> class Async_Call : public Async_Call_g {

private:
  std::shared_future<T> a_future;
  std::function<void(T)> a_f;

public:
  Async_Call(const std::string &p_f_name, std::shared_future<T> p_t,
             std::function<void(T)> f)
      : Async_Call_g(p_f_name, typeid(T).name()), a_future(p_t), a_f(f) {}

  virtual ~Async_Call() {}

  bool finish() override {
    return a_future.wait_for(std::chrono::seconds(0)) ==
           std::future_status::ready;
  }

  void release() override {
    this->a_f(this->a_future.get());
    return;
  }
};

// Implementation for void
template <> class Async_Call<void> : public Async_Call_g {
private:
  std::shared_future<void> a_future;
  std::function<void(void)> a_f;

public:
  Async_Call(const std::string &p_f_name, std::shared_future<void> p_t,
             std::function<void(void)> f)
      : Async_Call_g(p_f_name, typeid(void).name()), a_future(p_t), a_f(f) {}
  virtual ~Async_Call() {}

  bool finish() override {
    return a_future.wait_for(std::chrono::seconds(0)) ==
           std::future_status::ready;
  }

  void release() override {
    this->a_future.get();
    this->a_f();
    return;
  }
};
} // namespace Async
} // namespace CompoMe