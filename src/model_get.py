#!/usr/bin/env python3

import collections
from tools.Log import ERR, WARN
from model_test import is_struct, is_type


def get_import(main, key, log=True):

    print(key," ", main["IMPORTS"],main["NAME"])
    if key in main["IMPORTS"]:
        return main["IMPORTS"][key]

    if main["UP"] != None:
        ret = get_import(main["UP"], key, log=False)
        if ret is not None:
            return ret

    if log:
        ERR("no IMPORT with the name >",
            "!r(", key, ")<")

    return None

def replace_last(source_string, replace_what, replace_with):
    head, _sep, tail = source_string.rpartition(replace_what)
    return head + replace_with + tail

def get_type_or_struct(main, key, already_scan=None, log=True):

    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])

    if key in main["TYPES"] and key in main["STRUCTS"]:
        WARN("TYPES and struct DEFINITION for ",
             "!y(", key, ")")

    if key in main["TYPES"]:
        return main["TYPES"][key]

    if "<" in key and ">" in key:
        l_key = key.split("<", 1)
        l_arg_dirty = l_key[1][:-1].split(",")
        l_arg = []

        r1 = ""
        # TODO good split
        for i_a in l_arg_dirty:
            if r1 == "":
                r1 = i_a
            else:
                r1 = r1+","+i_a

            if r1.count("<") == r1.count(">"):
                l_arg.append(r1)
                r1 = ""

        if r1 != "":
            ERR("wrong quantity of '>' and '<'")

        if l_key[0] in main["TYPES"]:
            dd = dict.copy(main["TYPES"][l_key[0]])
            dd["NAME"] = key
            dd["D_NAME"] = key
            dd["PARAMS"] = l_arg
            dd["DYNAMIC"] = "DONE"

            return dd

    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_type_or_struct(l_import["MAIN"], key, already_scan, log=False)
        if ret is not None:
            return ret

    if log:
        ERR("aucun STRUCT ou TYPE  avec le nom >",
            "!r(", key, ")<")

    return None


def get_interface(main, key,already_scan=None, log=False):
    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])

    if key in main["INTERFACES"]:
        return main["INTERFACES"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_interface(l_import["MAIN"], key, already_scan, log=False)
        if ret is not None:
            return ret

    if log:
        ERR("no INTERFACES with the name >",
            "!r(", key, ")<")
    return None


def get_event(main, key, already_scan=None, log=False):
    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])

    if key in main["EVENTS"]:
        return main["EVENTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_event(l_import["MAIN"], key, already_scan, log=False)
        if ret is not None:
            return ret

    if log:
        ERR("no Event with the name >",
            "!r(", key, ")<")
    return None


def get_bus(main, key,already_scan=None, log=False):
    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])

    if key in main["BUS"]:
        return main["BUS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_bus(l_import["MAIN"],already_scan, key, log=False)
        if ret is not None:
            return ret

    if log:
        ERR("no Bus with the name >",
            "!r(", key, ")<")
    return None


def get_component(main, key, already_scan=None, log=False):
    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])


    if key in main["COMPONENTS"]:
        return main["COMPONENTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_component(l_import["MAIN"], key,already_scan, log=False)
        if ret is not None:
            return ret
    if log:
        ERR("aucun COMPONENT avec le nom >",
            "!e(", key, ")<")

    return None


def get_link_priv(main, key, already_scan=None, log=False):
    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])

    if key in main["LINKS"]:
        return main["LINKS"][key]

    for i_import in main["IMPORTS"].values():
        ret = get_link_priv(i_import["MAIN"], key,already_scan,log=log)
        if ret is not None:
            return ret

    return None


def get_link(main, key, log=False):
    # key = key.replace("-(", "")
    # key = key.replace("(", "")
    # key = key.replace(")->", "")
    # key = key.replace(")", "")

    ret = get_link_priv(main, key, log)
    if ret is None:
        ERR("aucun LINK avec le nom >",
            "!e(", key, ")<")

    return ret


def get_connector(main, key, already_scan=None, log=False):
    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])

    if key in main["CONNECTORS"]:
        return main["CONNECTORS"][key]

    for i_import in main["IMPORTS"].values():
        ret = get_connector(i_import["MAIN"], key, already_scan, log=False)
        if ret is not None:
            return ret

    if log:
        ERR("aucun CONNECTOR avec le nom >",
            "!e(", key, ")<")


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
        ERR("No instance of LINK With Name ",
            ">!r(", key, ")<",
            " in the deployment ",
            ">!r(", compo["NAME"], ")")

    return None


def get_stuct(main, key, already_scan=None, log=False):
    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])

    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_stuct(l_import["MAIN"], key, already_scan, log=False)
        if ret is not None:
            return ret

    if log:
        ERR("aucune STRUCT avec le nom ",
            ">!r(", key, ")<")


def get_error(main, key, already_scan=None, log=False):
    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])

    if key in main["ERRORS"]:
        return main["ERRORS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_error(l_import["MAIN"], key, already_scan, log=False)
        if ret is not None:
            return ret

    if log:
        ERR("No ERROR with the Name >",
            "!e(", key, ")<")


def get_deployment(main, key, already_scan=None, log=False):
    if already_scan is None:
        already_scan = []
    elif main["NAME"] in already_scan:
        return None
    else:
        already_scan.append(main["NAME"])

    if key in main["DEPLOYMENTS"]:
        return main["DEPLOYMENTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_deployment(l_import["MAIN"], key, already_scan, log=False)
        if ret is not None:
            return ret

    if log:
        ERR("No DEPLOYMENT with the Name >",
            "!r(", key, ")<")


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


def get_type_use_by(main, function, data):
    unique_list = dict()

    function = [] if function is None else function
    data = [] if data is None else data

    for i_f in function:
        unique_list = {**unique_list, **get_type_use_by_a_type(main, i_f["RETURN"])}

        for i_p in i_f["SIGNATURE"]:
            unique_list = {**unique_list, **get_type_use_by_a_type(main, i_p["TYPE"])}

    for i_d in data:
        unique_list = {**unique_list, **get_type_use_by_a_type(main, i_d["TYPE"])}

    return unique_list


def get_struct_use_by_a_type(main, p_type):
    unique_list = dict()
    if is_struct(p_type["D_NAME"], main):
        unique_list[p_type["D_NAME"]] = p_type
    elif "DYNAMIC" in p_type and "PARAMS" in p_type:

        for i_p in p_type["PARAMS"]:
            i_p_r = get_type_or_struct(main, i_p, log=False)
            if i_p_r is None:
                continue
            i_ul = get_struct_use_by_a_type(main, i_p_r)
            unique_list = {**unique_list, **i_ul}

    return unique_list


def get_type_use_by_a_type(main, p_type):
    unique_list = dict()
    if is_type(p_type["D_NAME"], main):
        unique_list[p_type["D_NAME"]] = p_type

    if "DYNAMIC" in p_type and "PARAMS" in p_type:
        for i_p in p_type["PARAMS"]:
            i_p_r = get_type_or_struct(main, i_p, log=False)
            if i_p_r is None:
                continue
            i_ul = get_type_use_by_a_type(main, i_p_r)
            unique_list = {**unique_list, **i_ul}

    return unique_list


def get_struct_use_by(main, function, data):
    unique_list = dict()

    if function is None:
        function = []

    if data is None:
        data = []

    for i_f in function:
        unique_list = {**get_struct_use_by_a_type(main, i_f["RETURN"]),
                       **unique_list}

        for i_p in i_f["SIGNATURE"]:
            unique_list = {**get_struct_use_by_a_type(main, i_p["TYPE"]),
                           **unique_list}

    for i_d in data:
        unique_list = {**get_struct_use_by_a_type(main, i_d["TYPE"]),
                       **unique_list}

    return unique_list


def get_sub_component_use_by(sub_component_list):
    unique_list = dict()

    if sub_component_list is None:
        sub_component_list = []

    for i_sc in sub_component_list:
        unique_list[i_sc["COMPONENT"]["D_NAME"]] = i_sc["COMPONENT"]

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
        ERR("l'INSTANCE ",
            "\"!y(", p_name, ")\"",
            " n'est pas definie dans le ",
            "!y(", p_dep["NAME"], ")")

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
        ERR("l'INTERFACE ",
            "!y(", p_name, ")",
            " n'est pas definie dans le COMPONENT ",
            "!y(", p_comp["NAME"], ")")
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
        ERR("l'INTERFACE ",
            "!y(", p_name, ")",
            " n'est pas definie dans le COMPONENT ",
            "!y(", p_comp["NAME"], ")")
    return r


def get_require_on_connector(p_main, p_comp, p_name, p_log=False):
    r = get_require_on_connector_rec(p_comp, p_name)

    if p_log is True and r is None:
        ERR("l'INTERFACE",
            "!y(", p_name, ")",
            "n'est pas definie dans le CONNECTOR ",
            "!y(", p_comp["NAME"], ")")
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
        ERR("l'INTERFACE",
            "!y(", p_name, ")",
            "n'est pas definie dans le COMPONENT ",
            "!y(", p_comp["NAME"], ")")

    return r

def get_emitter_on_component_rec(p_comp, p_name):
    if "EMITTER" in p_comp:
        for i_req in p_comp["EMITTER"]:
            if i_req["NAME"] == p_name:
                return i_req

    if "PARENT" in p_comp:
        return get_emitter_on_component_rec(p_comp["PARENT"], p_name)

    return None


def get_emitter_on_component(p_main, p_comp, p_name, p_log=False):
    r = get_emitter_on_component_rec(p_comp, p_name)
    if p_log is True and r is None:
        ERR("The EMITTER ",
            "!y(", p_name, ")",
            " is not define in the COMPONENT ",
            "!y(", p_comp["NAME"], ")")

    return r

def get_receiver_on_component_rec(p_comp, p_name):
    if "RECEIVER" in p_comp:
        for i_req in p_comp["RECEIVER"]:
            if i_req["NAME"] == p_name:
                return i_req

    if "PARENT" in p_comp:
        return get_receiver_on_component_rec(p_comp["PARENT"], p_name)

    return None


def get_receiver_on_component(p_main, p_comp, p_name, p_log=False):
    r = get_receiver_on_component_rec(p_comp, p_name)
    if p_log is True and r is None:
        ERR("The RECEIVER ",
            "!y(", p_name, ")",
            " is not define in the COMPONENT ",
            "!y(", p_comp["NAME"], ")")

    return r


def get_receiver_on_connector(p_main, p_comp, p_name, p_log=False):
    return get_receiver_on_component(p_main, p_comp, p_name, p_log)


def get_emitter_on_connector(p_main, p_comp, p_name, p_log=False):
    return get_emitter_on_component(p_main, p_comp, p_name, p_log)


def get_provide_on_connector(p_main, p_comp, p_name, p_log=False):
    r = get_provide_on_connector_rec(p_comp, p_name)
    if p_log is True and r is None:
        ERR("l'INTERFACE",
            "!y(", p_name, ") ",
            "n'est pas definie dans le CONNECTOR ",
            "!y(", p_comp["NAME"], ")")

    return r


def get_data_default(field, log=True):

    if "DEFAULT" in field:
        return "= " + str(field["DEFAULT"])

    if "DEFAULT" in field["TYPE"]:
        return "= " + str(field["TYPE"]["DEFAULT"])

    WARN("No default Value of !y(", field["TYPE"], " ", field["NAME"], ")")
    if "D_NAME" in field["TYPE"]:
        return field["TYPE"]["D_NAME"] + "()"
    else:
        return field["TYPE"]["NAME"] + "()"


def get_all_field_rec(data, parent):
    ret = []

    # HAVE DATA
    if data is not None:
        for i_d in data:
            ret.append(i_d)

    # MIX with parent data
    if parent is not None:
        l_data = parent["DATA"] if "DATA" in parent else None
        l_parent = parent["PARENT"] if "PARENT" in parent else None
        ret = [*ret, *get_all_field_rec(l_data, l_parent)]
        # if "DEFAULT" in parent:
        #     for i_def_k, i_def_v in parent["DEFAULT"].items():
        #         ret[i_def_k]["DEFAULT"] = i_def_v

    return ret


def keep_all(v_field, p_opt):
    return True


def keep_default(p_field, p_opt):
    return "DEFAULT" in p_field


def remove_default(p_field, p_opt):
    return "DEFAULT" not in p_field


def keep_struct(p_field, p_opt):
    return is_struct(p_field["TYPE"]["NAME"], p_opt)


def get_all_field(data, parent, p_filter=keep_all, opt_filter=None):
    l_ret = get_all_field_rec(data, parent)
    ret = []

    for i_f in l_ret:
        if p_filter(i_f, opt_filter):
            ret.append(i_f)

    return ret


def get_empty_main():
    main = collections.OrderedDict()
    main["UP"] = None
    main["TYPES"] = collections.OrderedDict()
    main["STRUCTS"] = collections.OrderedDict()
    main["ERRORS"] = collections.OrderedDict()
    main["EVENTS"] = collections.OrderedDict()
    main["BUS"] = collections.OrderedDict()
    main["INTERFACES"] = collections.OrderedDict()
    main["LINKS"] = collections.OrderedDict()
    main["COMPONENTS"] = collections.OrderedDict()
    main["DEPLOYMENTS"] = collections.OrderedDict()
    main["IMPORTS"] = collections.OrderedDict()
    main["CONNECTORS"] = collections.OrderedDict()

    return main
