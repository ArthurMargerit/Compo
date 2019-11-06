import collections
from termcolor import colored

from model_test import is_struct


def get_type_or_struct(main, key, log=True):
    if key in main["TYPES"] and key in main["STRUCTS"]:
        print(colored("red", "WARNING"),
              "TYPES and struct DEFINITION for ",
              colored(key, "yellow"))

    if key in main["TYPES"]:
        return main["TYPES"][key]

    if "<" in key and ">" in key:
        l_key = key.split("<", 1)
        l_arg = l_key[1].replace(">", "").split(",")

        if l_key[0] in main["TYPES"]:
            dd = dict.copy(main["TYPES"][l_key[0]])
            dd["NAME"] = key
            dd["PARAMS"] = l_arg
            print(dd["PARAMS"])
            dd["DYNAMIC"] = "DONE"

            return dd

    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_type_or_struct(l_import["MAIN"], key, log=False)
        if ret is not None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucun STRUCT ou TYPE  avec le nom >",
              colored(key, "red"),
              "<")

    return None


def get_interface(main, key, log=False):
    if key in main["INTERFACES"]:
        return main["INTERFACES"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_interface(l_import["MAIN"], key, log=False)
        if ret is not None:
            return ret

    if log:
        print(colored("Error", 'red'),
              "aucune INTERFACES avec le nom >",
              colored(key, 'green'),
              "<")
    return None


def get_component(main, key, log=False):

    if key in main["COMPONENTS"]:
        return main["COMPONENTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_component(l_import["MAIN"], key, log=False)
        if ret is not None:
            return ret
    if log:
        print(colored("Error", "red"),
              " aucun COMPONENT avec le nom >",
              colored(key, "green"),
              "<")

    return None


def get_link(main, key, log=False):
    key = key.replace("-(", "")
    key = key.replace("(", "")
    key = key.replace(")->", "")
    key = key.replace(")", "")

    if key in main["LINKS"]:
        return main["LINKS"][key]

    for i_import in main["IMPORTS"].values():
        ret = get_link(i_import["MAIN"], key, log=False)
        if ret is not None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucun LINK avec le nom >",
              colored(key, "red"),
              "<")


def get_connector(main, key, log=False):

    if key in main["CONNECTORS"]:
        return main["CONNECTORS"][key]

    for i_import in main["IMPORTS"].values():
        ret = get_connector(i_import["MAIN"], key, log=False)
        if ret is not None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucun CONNECTOR avec le nom >",
              colored(key, "red"),
              "<")


def get_link_instance(main, compo, key, log=True):
    if "LINK_INSTANCE" in compo:
        for link in compo["LINK_INSTANCE"]:
            if link["NAME"] == key:
                return link

    if "PARENT" in compo and compo["PARENT"] is not None:
        inst = get_link_instance(main, compo["PARENT"], key, False)

        if inst is not None:
            return inst

    if log:
        print(colored("Error", "red"),
              "aucune instance de LINK avec le nom >",
              colored(key, "red"),
              "< dans le deploiment",
              colored(compo["NAME"], "red"))

    return None


def get_stuct(main, key, log=False):
    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_stuct(l_import["MAIN"], key, log=False)
        if ret is not None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucune STRUCT avec le nom >",
              colored(key, "red"),
              "<")


def get_error(main, key, log=False):
    if key in main["ERRORS"]:
        return main["ERRORS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_error(l_import["MAIN"], key, log=False)
        if ret is not None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucune ERROR avec le nom >",
              colored(key, "red"),
              "<")


def get_deployment(main, key, log=False):
    if key in main["DEPLOYMENTS"]:
        return main["DEPLOYMENTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_deployment(l_import["MAIN"], key, log=False)
        if ret is not None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucune DEPLOYMENT avec le nom >",
              colored(key, "red"),
              "<")


def get_instances(element_list, element_name):
    element = element_list[element_name]
    f = element["COMPONENT_INSTANCE"]

    if "PARENT" not in element or element["PARENT"] is None:
        return f

    parent_f = get_instances(element_list, element["PARENT"]["NAME"])

    return [*f, *parent_f]


def get_functions(element_list, element_name):

    element = element_list[element_name]
    f = element["FUNCTION"]

    if "PARENT" not in element or element["PARENT"] is None:
        return f

    parent_f = get_functions(element_list, element["PARENT"]["NAME"])

    return [*f, *parent_f]


def get_datas(element_list, element_name):

    element = element_list[element_name]
    d = element["DATA"]

    if "PARENT" not in element or element["PARENT"] is None:
        return d

    parent_d = get_datas(element_list, element["PARENT"]["NAME"])

    return [*d, *parent_d]


def get_struct_use_by(main, function, data):
    unique_list = dict()

    if function is None:
        function = []

    if data is None:
        data = []

    for f in function:
        if is_struct(f["RETURN"]["NAME"], main["STRUCTS"]):
            unique_list[f["RETURN"]["NAME"]] = f["RETURN"]
        else:
            if "DYNAMIC" in f["RETURN"] and "PARAMS" in f["RETURN"]:
                for p in f["RETURN"]["PARAMS"]:
                    if is_struct(p, main["STRUCTS"]):
                        unique_list[p] = get_type_or_struct(main, p, log=True)

        for p in f["SIGNATURE"]:
            if is_struct(p["TYPE"]["NAME"], main["STRUCTS"]):
                unique_list[p["TYPE"]["NAME"]] = p["TYPE"]
            else:
                if "DYNAMIC" in p["TYPE"] and "PARAMS" in p["TYPE"]:
                    for p1 in p["TYPE"]["PARAMS"]:
                        if is_struct(p1, main["STRUCTS"]):
                            unique_list[p1] = get_type_or_struct(main,
                                                                 p1, log=True)

    for a in data:
        if is_struct(a["TYPE"]["NAME"], main["STRUCTS"]):
            unique_list[a["TYPE"]["NAME"]] = a["TYPE"]
        else:
            if "DYNAMIC" in a["TYPE"] and "PARAMS" in a["TYPE"]:
                for p in a["TYPE"]["PARAMS"]:
                    if is_struct(p, main["STRUCTS"]):
                        unique_list[p] = get_type_or_struct(main, p, log=True)

    return unique_list


def get_sub_component_use_by(sub_component_list):
    unique_list = dict()

    if sub_component_list is None:
        sub_component_list = []

    for sc in sub_component_list:
        unique_list[sc["COMPONENT"]["NAME"]] = sc["COMPONENT"]

    return unique_list


def get_list_provide_of_composant(main, composant_name):
    pass


def get_list_require_of_composant(main, composant_name):
    pass


def get_children(list_element, p_elem):
    l_r = []

    for li_elem in list_element.values():
        if "PARENT" in li_elem and p_elem == li_elem["PARENT"]["NAME"]:
            l_r.append(li_elem["NAME"])

    return l_r


def get_parent_rec(list_element, p_elem):
    l_r = []
    li_parent = p_elem

    while "PARENT" in li_parent:
        li_parent = li_parent["PARENT"]
        l_r.append(li_parent["NAME"])

    return l_r


def get_children_rec(list_element, p_elem):

    l_childs = get_children(list_element, p_elem)
    l_childs_of_childs = []
    for li_name_child in l_childs:
        l_p = get_children_rec(list_element, li_name_child)
        l_childs_of_childs = {*l_childs_of_childs, *l_p}

    result = {*l_childs, *l_childs_of_childs}
    return result if result != set() else []


def get_instance(p_main, p_dep, p_name, p_log=False):

    r = get_instance_component_rec(p_dep, p_name)
    if r is None:
        r = get_instance_connector_rec(p_dep, p_name)

    if p_log is True and r is None:
        print(colored("Error:", "red"),
              "l'INSTANCE",
              colored(p_name, "yellow"),
              "n'est pas definie dans le ",
              colored(p_dep["NAME"], "yellow"))

    return r


def get_instance_component_rec(p_dep, p_name):

    if "COMPONENT_INSTANCE" in p_dep:
        for i_dep in p_dep["COMPONENT_INSTANCE"]:
            if i_dep["NAME"] == p_name:
                return i_dep

    if "PARENT" in p_dep and p_dep["PARENT"] is not None:
        return get_instance_component_rec(p_dep["PARENT"], p_name)

    return None


def get_instance_connector_rec(p_dep, p_name):

    if "CONNECTOR_INSTANCE" in p_dep:
        for i_dep in p_dep["CONNECTOR_INSTANCE"]:
            if i_dep["NAME"] == p_name:
                return i_dep

    if "PARENT" in p_dep and p_dep["PARENT"] is not None:
        return get_instance_connector_rec(p_dep["PARENT"],
                                          p_name)

    return None


def get_require_on_component_rec(p_comp, p_name):

    if "REQUIRE" in p_comp:
        for i_req in p_comp["REQUIRE"]:
            if i_req["NAME"] == p_name:
                return i_req

    if "PARENT" in p_comp and p_comp["PARENT"] is not None:
        return get_require_on_component_rec(p_comp["PARENT"], p_name)

    return None


def get_require_on_connector_rec(p_comp, p_name):
    if "REQUIRE" in p_comp:
        for i_req in p_comp["REQUIRE"]:
            if i_req["NAME"] == p_name:
                return i_req
    return None


def get_provide_on_connector_rec(p_comp, p_name):
    if "PROVIDE" in p_comp:
        for i_req in p_comp["PROVIDE"]:
            if i_req["NAME"] == p_name:
                return i_req
    return None


def get_require_on_component(p_main, p_comp, p_name, p_log=False):

    r = get_require_on_component_rec(p_comp, p_name)
    if p_log is True and r is None:
        print(colored("Error:", "red"),
              "l'INTERFACE",
              colored(p_name, "yellow"),
              "n'est pas definie dans le COMPONENT ",
              colored(p_comp["NAME"], "yellow"))
    return r


def get_require_list_on_component_rec(p_comp, p_name):

    if "REQUIRE_LIST" in p_comp:
        for i_req in p_comp["REQUIRE_LIST"]:
            if i_req["NAME"] == p_name:
                return i_req

    if "PARENT" in p_comp and p_comp["PARENT"] is not None:
        return get_require_list_on_component_rec(p_comp["PARENT"], p_name)

    return None


def get_require_list_on_component(p_main, p_comp, p_name, p_log=False):
    r = get_require_list_on_component_rec(p_comp, p_name)
    if p_log is True and r is None:
        print(colored("Error:", "red"),
              "l'INTERFACE",
              colored(p_name, "yellow"),
              "n'est pas definie dans le COMPONENT ",
              colored(p_comp["NAME"], "yellow"))
    return r


def get_require_on_connector(p_main, p_comp, p_name, p_log=False):
    r = get_require_on_connector_rec(p_comp, p_name)

    if p_log is True and r is None:
        print(colored("Error:", "red"),
              "l'INTERFACE",
              colored(p_name, "yellow"),
              "n'est pas definie dans le CONNECTOR ",
              colored(p_comp["NAME"], "yellow"))
    return r


def get_provide_on_component_rec(p_comp, p_name):
    if "PROVIDE" in p_comp:
        for i_req in p_comp["PROVIDE"]:
            if i_req["NAME"] == p_name:
                return i_req

    if "PARENT" in p_comp:
        return get_provide_on_component_rec(p_comp["PARENT"], p_name)

    return None


def get_provide_on_component(p_main, p_comp, p_name, p_log=False):
    r = get_provide_on_component_rec(p_comp, p_name)
    if p_log is True and r is None:
        print(colored("Error:", "red"),
              "l'INTERFACE",
              colored(p_name, "yellow"),
              "n'est pas definie dans le COMPONENT ",
              colored(p_comp["NAME"], "yellow"))

    return r


def get_provide_on_connector(p_main, p_comp, p_name, p_log=False):
    r = get_provide_on_connector_rec(p_comp, p_name)
    if p_log is True and r is None:
        print(colored("Error:", "red"),
              "l'INTERFACE",
              colored(p_name, "yellow"),
              "n'est pas definie dans le CONNECTOR ",
              colored(p_comp["NAME"], "yellow"))
    return r


def get_empty_main():
    main = collections.OrderedDict()
    main["TYPES"] = collections.OrderedDict()
    main["STRUCTS"] = collections.OrderedDict()
    main["ERRORS"] = collections.OrderedDict()
    main["INTERFACES"] = collections.OrderedDict()
    main["LINKS"] = collections.OrderedDict()
    main["COMPONENTS"] = collections.OrderedDict()
    main["DEPLOYMENTS"] = collections.OrderedDict()
    main["IMPORTS"] = collections.OrderedDict()
    main["CONNECTORS"] = collections.OrderedDict()

    return main
