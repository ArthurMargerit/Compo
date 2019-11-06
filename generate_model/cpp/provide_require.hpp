// INTERFACE ////////////////////////////////////////////////////////////////
public:
// PROVIDES
{% for pro in PROVIDE %}
{{ pro.INTERFACE.NAME }}& get_{{ pro.NAME }}() {
    return this->{{ pro.NAME }};
}
{% endfor %}

// REQUIRES
// set
{% for req in REQUIRE %}
void set_{{ req.NAME }}({{ req.INTERFACE.NAME }}* p_r) {
  this->{{ req.NAME }} = p_r;
}
{% endfor %}
// get
{% for req in REQUIRE %}
{{ req.INTERFACE.NAME }}* get_{{ req.NAME }}() {
  return this->{{ req.NAME }};
}
{% endfor %}


// INTERFACE ////////////////////////////////////////////////////////////////
private:
// REQUIRE
{% for req in REQUIRE -%}
{{ req.INTERFACE.NAME }}* {{ req.NAME }};
{% endfor %}

// PROVIDE
{% for pro in PROVIDE -%}
{{NAME}}_{{pro.INTERFACE.NAME }} {{pro.NAME}};
{% endfor %}

