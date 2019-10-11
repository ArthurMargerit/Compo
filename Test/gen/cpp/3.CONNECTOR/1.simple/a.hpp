{% set i = MAIN.INTERFACES[INTERFACE] %}

#include "Interfaces/{{i.NAME}}/{{i.NAME}}.hpp"


class Logger_{{NAME}} {


  class {{NAME}}_{{i.NAME}} :  public {{i.NAME}} {
  public:
    Logger_{{NAME}}* lo;
    {{NAME}}_{{i.NAME}}(Logger_{{NAME}}* p_lo = NULL):lo(p_lo){
    }

    {%for f in i.FUNCTION %}
    virtual
    {{f.RETURN.NAME}} {{f.NAME}}(
      {%- for p in f.SIGNATURE -%}
      {{p.TYPE.NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%}
      ){
      this->get__os() << "{{f.NAME}}("
        {%-for p in f.SIGNATURE-%}
      << {{p.NAME}}{% if not loop.last %} << ","{%endif%}
      {%- endfor -%} << ")=>";

      {{f.RETURN.NAME}} l_return = this->get__c().{{f.NAME}}(
          {%- for p in f.SIGNATURE-%}
      {{p.NAME}}{% if not loop.last %},{%endif%}
        {%-endfor%});

      this->get__os() << l_return << std::endl;
      return l_return;
    }
    {%endfor%}

    {%for d in i.DATA %}
    virtual
    {{d.TYPE.NAME}} get_{{d.NAME}}() const {
      this->get__os() << "get_{{d.NAME}}()=>";
      {{d.TYPE.NAME}} l_return = this->get__c().get_{{d.NAME}}();
      this->get__os() << l_return << std::endl;
      return l_return;
    }

    virtual
    void set_{{d.NAME}}({{d.TYPE.NAME}} {{d.NAME}}) {
      this->get__os() << "set_{{d.NAME}}("<< {{d.NAME}} << ")=>";

      this->get__c().set_{{d.NAME}}({{d.NAME}});
      this->get__os()<<std::endl;
      return;
    }
    {%endfor%}

    {{i.NAME}}& get__c() const{
      return this->lo->r;
    }

std::ostream& get__os() const{
      return *this->lo->os;
              }

  };

 public:
  Logger_{{NAME}}({{i.NAME}}& p_r, std::ostream& p_os = std::cout):os(&p_os),r(p_r),p(this){

  }

  std::ostream* os;

  {{i.NAME}}& r;

  {{NAME}}_{{i.NAME}} p;
};
