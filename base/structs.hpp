#pragma once

{% for key,value in STRUCTS.items() %}

struct {{value["NAME"]}};

{% endfor %}

