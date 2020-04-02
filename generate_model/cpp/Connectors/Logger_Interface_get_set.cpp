{% if "PARENT" in i and i.PARENT != None %}
{% with i=i.PARENT %}
{% include "Connectors/Logger_Interface_get_set.cpp" %}
{% endwith %}
{% endif %}

// i.NAME
{%for d in i.DATA %}
{{d.TYPE.D_NAME}} {{CLS_I_NAME}}::get_{{d.NAME}}() const {
      std::stringstream ss;

      struct timespec l_b;
      clock_gettime(CLOCK_MONOTONIC, &l_b);
      ss << l_b.tv_sec <<"," << l_b.tv_nsec << ":";

      ss << "get_{{d.NAME}}():";
      {{d.TYPE.D_NAME}} l_return = this->get_c().r->get_{{d.NAME}}();

      struct timespec l_a;
      clock_gettime(CLOCK_MONOTONIC, &l_a);
      ss << l_a.tv_sec <<"," << l_a.tv_nsec << ":";

      ss << l_return;

      ss << ":"<< (int64_t)(l_a.tv_sec - l_b.tv_sec) * (int64_t)1000000000UL
        + (int64_t)(l_a.tv_nsec - l_b.tv_nsec);


      this->get_c().get_os() << ss.str() << std::endl;

      return l_return;
}

void {{CLS_I_NAME}}::set_{{d.NAME}}(const {{d.TYPE.D_NAME}}& {{d.NAME}}) {
      std::stringstream ss;

      struct timespec l_b;
      clock_gettime(CLOCK_MONOTONIC, &l_b);
      ss << l_b.tv_sec <<"," << l_b.tv_nsec << ":";

      ss << "set_{{d.NAME}}("<< {{d.NAME}} << "):";

      this->get_c().r->set_{{d.NAME}}({{d.NAME}});

      struct timespec l_a;
      clock_gettime(CLOCK_MONOTONIC, &l_a);
      ss << l_a.tv_sec <<"," << l_a.tv_nsec << ":";

      ss <<"void";

      ss << ":"<< (int64_t)(l_a.tv_sec - l_b.tv_sec) * (int64_t)1000000000UL
        + (int64_t)(l_a.tv_nsec - l_b.tv_nsec);

      this->get_c().get_os() << ss.str() << std::endl;
      return;
}
{%endfor%}
