
class {{NAME}}_{{iwi.NAME}} :  public {{iwi.NAME}} {

  public:
    {{NAME}}_{{iwi.NAME}}({{NAME}}& p_c): {{iwi.NAME}}(), _c(p_c){}
    virtual ~{{NAME}}_{{iwi.NAME}}(){}

    {%for f in iwi.FUNCTION %}
    //--> {{f.NAME}} >--//
    virtual
    {{f.RETURN.NAME}} {{f.NAME}} (
      {%- for p in f.SIGNATURE -%}
      {{p.TYPE.NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%}) {

      {%if f.RETURN.NAME == "void" %}
      this->get__c().list_r[{{f.SIGNATURE[0].NAME}}]->{{f.NAME}}({%- for p in f.SIGNATURE[1:] -%}
           {{p.NAME}}{% if not loop.last %},{%endif%}{%- endfor -%});
      return;

      {%else%} {# NON VOID#}

      return this->get__c().list_r[{{f.SIGNATURE[0].NAME}}]->{{f.NAME}}(
        {%- for p in f.SIGNATURE[1:] -%}
        {{p.NAME}}{% if not loop.last %},{%endif%}
        {%- endfor -%});
      {%endif%}
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
