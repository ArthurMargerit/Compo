#include "Bus/Bus.hpp"
#include <iostream>

namespace CompoMe {

  Emit::Emit(std::string p_name):name(p_name) {

  }

  void Emit::inscribe(CompoMe::Bus* p_b, std::string origin_match, std::string destination_match) {
    Bus_match l_bus;
    l_bus.origin_match = origin_match;
    l_bus.destination_match = destination_match;
    l_bus.bus.bus_r = p_b;
    l_bus.kind_in_union = RECEIVER;

    this->b.push_back(l_bus);
  }

  void Emit::inscribe(CompoMe::Emit* p_b, std::string origin_match, std::string destination_match) {
    Bus_match l_bus;
    l_bus.origin_match = origin_match;
    l_bus.destination_match = destination_match;
    l_bus.bus.bus_e = p_b;
    l_bus.kind_in_union = EMITTER;

    this->b.push_back(l_bus);
  }

  void Emit::push(CompoMe::Event* e) {
    if(e->get_origin() == "None"){
      e->set_origin(this->name);
    }

    for (auto & f : this->b ) {

      if(std::regex_match(e->get_origin(), std::regex(f.origin_match)) &&
         std::regex_match(e->get_destination(), std::regex(f.destination_match))) {

        if (f.kind_in_union == EMITTER) {
          f.bus.bus_e->push(e);
        } else if(f.kind_in_union == RECEIVER) {
          f.bus.bus_r->push(e);
        } else {
          std::cout << "corrupted DATA" << "\n";
        }
      }
    }
  }


  Bus::Bus():internal_emit("internal"){}
  Bus::~Bus(){}

  void Bus::inscribe(CompoMe::Bus *e) {
    this->internal_emit.inscribe(e);
  }

  void Bus::inscribe(CompoMe::Emit *e) {
    this->internal_emit.inscribe(e);
  }

}  // CompoMe
