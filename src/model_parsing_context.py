import os.path
from model_get import get_empty_main


def context_get_empty():
    context = {
        "stack_file": [],
        "main": {},
        "message": [],
        "exec_code": [],
        "element_to_expand": {},
        "expand_order": ["IMPORTS", "TYPES", "STRUCTS", "ERRORS", "EVENTS", "BUS", "INTERFACES", "CONNECTORS", "COMPONENTS", "PORTS", "LINKS", "DEPLOYMENTS"]
    }

    return context


def context_create(main_file):
    context = context_get_empty()
    for i_e in context["expand_order"]:
        context["element_to_expand"][i_e] = []

    context_add_file(context, main_file)
    return context


def context_add_file(context, file_to_add):
    context["stack_file"].append(os.path.realpath(file_to_add))
    context["main"][file_to_add] = get_empty_main()
    return context["main"][file_to_add]


def context_add_element(context, function_selector, el, main):
    function_selector_s = function_selector + \
        ("S" if function_selector[-1] != "S" else "")
    if function_selector_s != "IMPORTS":
        main[function_selector_s][el["D_NAME"]] = el

    context["element_to_expand"][function_selector_s].append((el, main))


def context_add_exec(context, function_selector, el, main):
    context["exec_code"].append((function_selector, el, main))


def context_pop_file(context):
    context["stack_file"].pop()


def context_list_file(context):
    return context["stack_file"]


def context_get_main(context, file):
    return context["main"][file]


def context_already_import(context, file_to_import):
    return file_to_import in context["main"]
