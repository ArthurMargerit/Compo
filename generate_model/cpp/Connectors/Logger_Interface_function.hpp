{%if "PARENT" in i and i.PARENT != None %}
{% with i = i.PARENT %}
{% include "Connectors/Logger_Interface_function.hpp" %}
{% endwith %}
{%endif%}

{%for f in i.FUNCTION %}
    virtual
    {{f.RETURN.NAME}} {{f.NAME}}(
      {%- for p in f.SIGNATURE -%}
      {{p.TYPE.NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
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
      {{f.RETURN.NAME}} l_return = this->get__c().{{f.NAME}}({%- for p in f.SIGNATURE-%}{{p.NAME}}{% if not loop.last %},{%endif%}{%-endfor%});

      struct timespec l_a;
      clock_gettime(CLOCK_MONOTONIC, &l_a);
      ss << l_a.tv_sec <<"," << l_a.tv_nsec << ":";

      ss << l_return;
      {%else%}
      this->get__c().{{f.NAME}}({%- for p in f.SIGNATURE-%}{{p.NAME}}{% if not loop.last %},{%endif%}{%-endfor%});

      struct timespec l_a;
      clock_gettime(CLOCK_MONOTONIC, &l_a);
      ss << l_a.tv_sec <<"," << l_a.tv_nsec << ":void";
      {%endif%}

      ss << ":"<< (int64_t)(l_a.tv_sec - l_b.tv_sec) * (int64_t)1000000000UL
        + (int64_t)(l_a.tv_nsec - l_b.tv_nsec);

      this->get__os() << ss.str() << std::endl;

      {%if f.RETURN.NAME != "void" %}
      return l_return;
      {%else%}
      return;
      {%endif%}
    }
{%endfor%}
