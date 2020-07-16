// INTERFACE ////////////////////////////////////////////////////////////////
public:
// PROVIDES
{% for pro in PROVIDE %}
{{ pro.INTERFACE.D_NAME }}& get_{{ pro.NAME }}() {
    return this->{{ pro.NAME }};
}
{% endfor %}

public:
// REQUIRE
{% for req in REQUIRE -%}
CompoMe::Require_helper_t<{{req.INTERFACE.D_NAME}}> {{req.NAME}};
{% endfor %}

private:
// PROVIDE
{% for pro in PROVIDE -%}
{{NAME}}_{{pro.INTERFACE.NAME}} {{pro.NAME}};
{% endfor %}


