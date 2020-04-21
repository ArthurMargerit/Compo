set(_include_directories "")

{% with MY_PATH="." %}
{% include "compile/import.rec" with context %}
{% endwith %}
