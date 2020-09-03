{%if "PARENT" in i and i.PARENT != None %}
{% with i = i.PARENT %}
{% include "Connectors/Logger_Interface_function.cpp" %}
{% endwith %}
{%endif%}

{%for f in i.FUNCTION %}
{{f.RETURN.D_NAME}}
{{CLS_I_NAME}}::{{f.NAME}}(
      {%- for p in f.SIGNATURE -%}
      {{p.TYPE.D_NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%}
      ){

      std::stringstream ss;

      struct timespec l_b;
      clock_gettime(CLOCK_MONOTONIC, &l_b);
      ss << l_b.tv_sec <<"," << l_b.tv_nsec << ":";

      ss << "{{f.NAME}}("
        {%-for p in f.SIGNATURE-%}
      << {{p.NAME}}{% if not loop.last %} << ","{%endif%}
      {%- endfor -%} << "):";

      {%if f.RETURN.NAME != "void" %}
      auto l_return = this->get_c().r->{{f.NAME}}({%- for p in f.SIGNATURE-%}{{p.NAME}}{% if not loop.last %},{%endif%}{%-endfor%});

      struct timespec l_a;
      clock_gettime(CLOCK_MONOTONIC, &l_a);
      ss << l_a.tv_sec <<"," << l_a.tv_nsec << ":";

      ss << l_return;
      {%else%}
      this->get_c().r->{{f.NAME}}({%- for p in f.SIGNATURE-%}{{p.NAME}}{% if not loop.last %},{%endif%}{%-endfor%});

      struct timespec l_a;
      clock_gettime(CLOCK_MONOTONIC, &l_a);
      ss << l_a.tv_sec <<"," << l_a.tv_nsec << ":void";
      {%endif%}

      C_TO_DEBUG_TAG(this->get_c().log, ss.str().c_str(), "logger,{{i.D_NAME}}::{{f.NAME}}(...)");

      {%if f.RETURN.NAME != "void" %}
      return l_return;
      {%else%}
      return;
      {%endif%}
}
{%endfor%}
