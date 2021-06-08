#pragma once


namespace CompoMe {

class Link {
public:
  virtual void step();
  virtual void configuration();
  virtual void main_connect();
  virtual void main_disconnect();

public:
  Link();
  virtual ~Link() noexcept;
};

} // namespace CompoMe
