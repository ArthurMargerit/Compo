// INTERFACE ////////////////////////////////////////////////////////////////
public:
// PROVIDES
{% for pro in PROVIDE %}
{{ pro.INTERFACE.D_NAME }}& get_{{ pro.NAME }}() {
    return this->{{ pro.NAME }};
}
{% endfor %}

// REQUIRES
// set
{% for req in REQUIRE %}
void set_{{req.NAME}}({{req.INTERFACE.D_NAME}}* p_r) {
  this->{{ req.NAME }} = p_r;
}
{% endfor %}
// get
{% for req in REQUIRE %}
{{req.INTERFACE.D_NAME}}* get_{{req.NAME}}() {
  return this->{{ req.NAME }};
}
{% endfor %}


// INTERFACE ////////////////////////////////////////////////////////////////
private:
// REQUIRE
{% for req in REQUIRE -%}
{{req.INTERFACE.D_NAME}}* {{req.NAME}};
{% endfor %}

// PROVIDE
{% for pro in PROVIDE -%}
{{NAME}}_{{pro.INTERFACE.NAME}} {{pro.NAME}};
{% endfor %}

