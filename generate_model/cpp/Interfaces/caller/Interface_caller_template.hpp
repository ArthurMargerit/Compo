#pragma once

#include "Interfaces/{{D_NAME.replace('::','/')}}//{{NAME}}.hpp"
{%if PARENT%}
#include "Interfaces/{{PARENT.D_NAME.replace('::','/')}}/{{PARENT.NAME}}_caller.hpp"
{%else%}
#include "Interfaces/Caller.hpp"
{%endif%}

#include <string>

{% include "helper/namespace_open.hpp" with context%}
class {{NAME}}_caller : public {%if PARENT%}{{PARENT.D_NAME}}_caller{%else%}Caller{%endif%}
{
 private:
  {{D_NAME}}& comp;

 public:

  {{NAME}}_caller({{D_NAME}}& pcomp);
  bool call(Function_stream_recv& is, Return_stream_send& os) override;

 protected:

  bool call(std::string& name_function, Function_stream_recv& is, Return_stream_send& os) override;

 private:
{% for func in FUNCTION %}
  bool {{ func.NAME }}(Function_stream_recv& is, Return_stream_send& os);
{% endfor %}

{% for d in DATA %}
  bool get_{{ d.NAME }}(Function_stream_recv& is, Return_stream_send& os);
  bool set_{{ d.NAME }}(Function_stream_recv& is, Return_stream_send& os);
{% endfor %}


};
{% include "helper/namespace_close.hpp" with context%}
