{% set i  = MAIN.INTERFACES[INTERFACE] %}
#include "Interfaces/{{i.NAME}}/{{i.NAME}}.hpp"

#include <vector>
#include <random>

class {{NAME}} {
 public:

   class {{NAME}}_{{i.NAME}} :  public {{i.NAME}} {
  public:

    {{NAME}}_{{i.NAME}}({{NAME}}& p_c): {{i.NAME}}(), _c(p_c){}

    virtual ~{{NAME}}_{{i.NAME}}(){}

    {%for f in i.FUNCTION %}
    //--> {{f.NAME}} >--//
    virtual
    {{f.RETURN.NAME}} {{f.NAME}} (
      {%- for p in f.SIGNATURE -%}
      {{p.TYPE.NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%}) {
      {%if f.RETURN.NAME == "void" %}
      this->get__c().get_next()->{{f.NAME}}({%- for p in f.SIGNATURE -%}
       {{p.NAME}}{% if not loop.last %},{%endif%}
      return;
      {%- endfor -%});
      {%else%}
      return this->get__c().get_next()->{{f.NAME}}({%- for p in f.SIGNATURE -%}
       {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%});
      {%endif%}
    }
    {%endfor%}

    {%for d in i.DATA %}
    //--> {{d.NAME}} >--//
    virtual
    void set_{{d.NAME}} ( {{d.TYPE.NAME}} p_{{d.NAME}}) {
      this->get__c().get_next()->set_{{d.NAME}}(p_{{d.NAME}});
    }

    virtual
    {{d.TYPE.NAME}} get_{{d.NAME}} () const {
      return this->get__c().get_next()->get_{{d.NAME}}();
    }
    {%endfor%}


    {{NAME}}& _c;
    {{NAME}}& get__c() {
      return this->_c;
    }
    {{NAME}}& get__c() const  {
      return this->_c;
    }
  };

  {{NAME}}():c(*this){}
  virtual ~{{NAME}}(){}

  std::vector<{{i.NAME}}*> list_r;
  {{NAME}}_{{i.NAME}} c;

  {{i.NAME}}* get_next() {
    static int i = 0;
    if(list_r.size() == 0 ) {
      throw "Error No interface";
    }
    if(i >= list_r.size()){
      i = 0;
    }
    return this->list_r[i++];
  }
};
