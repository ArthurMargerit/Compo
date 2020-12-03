#pragma once

#include "Events/Event.hpp"
#include <queue>
#include <typeindex>
#include <iostream>

#include "Bus/Bus.hpp"

{%for e in EVENTS %}
#include "Events/{{e.EVENT.F_NAME}}.hpp"
{%endfor%}

{%for sb in SUB_BUS %}
#include "Bus_Events/{{sb.BUS.F_NAME}}.hpp"
{%endfor%}

{%include "helper/namespace_open.hpp" with context %}

class {{NAME}}: public CompoMe::Bus {
  std::queue<CompoMe::Event*> Event_q;

 private:
  void m(CompoMe::Event* e) override {
    {% set impl_invt = [] %}
    {% include "Events/Bus_if.hpp" with context %}
  }

 {% set impl_invt = [] %}
 {% include "Events/Event_bus_m.hpp" with context %}

 public:
  void process() {
    while(not this->Event_q.empty()) {
      auto r = this->Event_q.front();
      m(r);
      this->internal_emit.push(r);
      this->Event_q.pop();
    }
  }

  void push(CompoMe::Event* e) {
    Event_q.push(e);
  }
};
{%include "helper/namespace_close.hpp" with context %}
