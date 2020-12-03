#pragma once

#include "Serialization_context.hpp"

namespace CompoMe {
  class Event : public Serializable_Item
  {
  private:
    std::string destination;
    std::string origin;

  public:
    const std::string get_origin() const {
      return origin;
    }

    void set_origin(const std::string origin) {
      this->origin = origin;
    }

    const std::string get_destination() const {
      return destination;
    }

    void set_destination(const std::string destination) {
      this->destination = destination;
    }

    //std::vector get_tag();
    // std::string get_type() {
    // };

    Event();
    virtual ~Event();

  };
}  // CompoMe
