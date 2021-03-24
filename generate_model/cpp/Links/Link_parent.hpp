#pragma once


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

} // namespace CompoMe
