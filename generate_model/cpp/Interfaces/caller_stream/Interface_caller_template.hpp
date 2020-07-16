#pragma once

#include "Interfaces/{{F_NAME}}/{{NAME}}.hpp"
{%if PARENT%}
#include "Interfaces/{{PARENT.F_NAME}}/{{PARENT.NAME}}_caller_stream.hpp"
{%else%}
#include "Interfaces/Caller_stream.hpp"
{%endif%}

#include <string>

{% include "helper/namespace_open.hpp" with context%}

class {{NAME}}_caller_stream : public {%if PARENT%}{{PARENT.D_NAME}}_caller_stream{%else%}CompoMe::Caller_stream{%endif%}
{
 private:
  {{D_NAME}}& comp;

 public:

  {{NAME}}_caller_stream({{D_NAME}}& pcomp);
  bool call(CompoMe::Function_stream_recv& is, CompoMe::Return_stream_send& os) override;

 protected:

  bool call(std::string& name_function, CompoMe::Function_stream_recv& is, CompoMe::Return_stream_send& os) override;

 private:
{% for func in FUNCTION %}
  bool {{ func.NAME }}(CompoMe::Function_stream_recv& is, CompoMe::Return_stream_send& os);
{% endfor %}

{% for d in DATA %}
  bool get_{{ d.NAME }}(CompoMe::Function_stream_recv& is, CompoMe::Return_stream_send& os);
  bool set_{{ d.NAME }}(CompoMe::Function_stream_recv& is, CompoMe::Return_stream_send& os);
{% endfor %}


};
{% include "helper/namespace_close.hpp" with context%}
