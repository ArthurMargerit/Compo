#pragma once

#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

class Return_stream {

private:
  std::istream *si;
  std::ostream *so;

public:
  // GET AND SET //////////////////////////////////////////////////////////////
  std::ostream *get_so() const { return so; }

  void set_so(std::ostream *so) { this->so = so; }

  std::istream *get_si() const { return si; }

  void set_si(std::istream *si) { this->si = si; }

  Return_stream(std::istream *i_s, std::ostream *o_s);
  Return_stream(std::istream *p_s);
  Return_stream(std::ostream *p_s);

  virtual ~Return_stream();

  virtual void pull() = 0;
  virtual void end() = 0;
  char get();
};

template <typename T> Return_stream &operator<<(Return_stream &s, const T &e) {
  *s.get_so() << e;
  return s;
}

template <typename T> Return_stream &operator>>(Return_stream &s, T &e) {
  *s.get_si() >> e;
  return s;
}

// RETURN STRING STREAM ///////////////////////////////////////////////////////
class Return_string_stream : public Return_stream {
private:
  using Pull_f = std::function<void(std::stringstream &)>;
  using End_f = std::function<void(std::stringstream &)>;

  std::stringstream sf;
  Pull_f pull_f;
  End_f end_f;

public:
  Return_string_stream(
      Pull_f p_pull = [](std::stringstream &) {},
      End_f p_end = [](std::stringstream &) {});

  virtual void pull();
  virtual void end();
};

namespace std {
Return_stream &getline(Return_stream &is, string &str, char delim);
Return_stream &getline(Return_stream &is, string &str);
} // namespace std