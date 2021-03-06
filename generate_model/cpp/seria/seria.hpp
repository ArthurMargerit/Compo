{% if OPTIONS and OPTIONS.STREAM %}
// stream
void to_stream(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const override;
void from_stream(std::istream& is, CompoMe::Serialization_context_import& p_ctx) override;
{% endif %}

{% if OPTIONS and OPTIONS.DBUS %}
// dbus
void to_dbus(DBusMessageIter&, CompoMe::Serialization_context_export&) const override;
void from_dbus(DBusMessageIter&, CompoMe::Serialization_context_import&) override;
{% endif %}

{% if OPTIONS and OPTIONS.JSON %}
// json
void to_json(nlohmann::json&, CompoMe::Serialization_context_export&) const override;
void from_json(nlohmann::json&, CompoMe::Serialization_context_import&) override;
{% endif %}

{% if OPTIONS.EXTRA %}
// __ extra __
void extra_export(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const;
void extra_import(std::istream& is, CompoMe::Serialization_context_import& p_ctx);
{% endif %}
