{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set ic = MAIN.INTERFACES[INTERFACE_ASYNC_CALL] %}
{% set ir = MAIN.INTERFACES[INTERFACE_ASYNC_RETURN] %}

#include "Interfaces/{{i.NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{ir.NAME}}/{{ir.NAME}}.hpp"
#include "Interfaces/{{ic.NAME}}/{{ic.NAME}}.hpp"

class Async_{{NAME}} {
 public:

  class {{NAME}}_{{ic.NAME}} :  public {{ic.NAME}} {
  public:

    {{NAME}}_{{ic.NAME}}(Async_{{NAME}}& p_c): {{ic.NAME}}(), _c(p_c){}

    virtual ~{{NAME}}_{{ic.NAME}}(){}

    {%for fc,fr in Function.zip(ic.FUNCTION,ir.FUNCTION) %}
    virtual
    void {{fc.NAME}} (
      {%- for p in fc.SIGNATURE -%}
      {{p.TYPE.NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%}) {

      {% if fr.SIGNATURE != [] %}
      auto l_return =
      {%- endif -%}
      this->get__c().r->{{fc.NAME}}(
        {%- for p in fc.SIGNATURE -%}
        {{p.NAME}}{% if not loop.last %},{%endif%}
        {%- endfor -%});

      if(&this->get__c().rr == NULL) {
        std::cerr << "warning return value lost"<<std::endl;
      } else {
      {% if fr.SIGNATURE != [] -%}
      this->get__c().rr->{{fr.NAME}}(l_return);
      {%-else-%}
      this->get__c().rr->{{fr.NAME}}();
      {%-endif%}
      }
      return;
    }
    {%endfor%}

    Async_{{NAME}}& _c;
    Async_{{NAME}}& get__c() {
      return _c;
    }

  };

 public:

  Async_{{NAME}}():rr(NULL),r(NULL),c(*this){}
  virtual ~Async_{{NAME}}(){}

  {{i.NAME}}* r;
  {{ir.NAME}}* rr;
  {{NAME}}_{{ic.NAME}} c;

};
