
import collections
from tools.Uni import Uni
from model_get import get_component, get_instance

from model_get import get_require_on_component, get_provide_on_component
from model_get import get_require_on_connector, get_provide_on_connector

from model_get import get_require_list_on_component

from model_expand_parent import component_parent_expand

from model_expand_connector import connector_instances_expand

from model_expand_function import function_expand
from model_expand_data import data_expand

from model_expand_interface import provide_expand
from model_expand_interface import require_expand, require_list_expand


def component_connection_expand_sc_to_sc(main, c, data, log):
    d = collections.OrderedDict()
    if "-->" in data:
        l_from_to = data.split("-->")
    else:
        l_from_to = data.split("+->")

    d["LINK"] = "SC_R_TO_SC_P"

    if "-->" in data:
        d["FROM"] = component_sub_component_declaration_expand(main, c,
                                                               l_from_to[0],
                                                               "REQUIRE", log)
        d["FROM"]["KIND"] = "set"
    else:
        d["FROM"] = component_sub_component_declaration_expand(main, c,
                                                               l_from_to[0],
                                                               "REQUIRE_LIST",
                                                               log)
        d["FROM"]["KIND"] = "add"

    d["TO"] = component_sub_component_declaration_expand(main, c,
                                                         l_from_to[1],
                                                         "PROVIDE", log)

    return d


def component_connection_expand_c_to_sc(main, c, data, log):
    d = collections.OrderedDict()
    l_from_to = data.split("|->")

    d["LINK"] = "C_P_TO_SC_P"
    d["FROM"] = get_provide_on_component(main, c,
                                         l_from_to[0].replace(" ", ""), log)

    d["TO"] = component_sub_component_declaration_expand(main, c,
                                                         l_from_to[1],
                                                         "PROVIDE", log)

    d["FROM"]["LINK_TO"] = d["TO"]

    return d


def component_connection_expand_sc_to_c(main, c, data, log):
    d = collections.OrderedDict()
    l_from_to = data.split(">-|") if ">-|" in data else data.split(">+|")

    d["LINK"] = "SC_R_TO_C_R"

    if ">-|" in data:
        d["FROM"] = component_sub_component_declaration_expand(main, c,
                                                               l_from_to[0],
                                                               "REQUIRE", log)
        d["FROM"]["KIND"] = "set"
    else:
        d["FROM"] = component_sub_component_declaration_expand(main, c,
                                                               l_from_to[0],
                                                               "REQUIRE_LIST",
                                                               log)
        d["FROM"]["KIND"] = "add"

    d["TO"] = get_require_on_component(main, c,
                                       l_from_to[1].replace(" ", ""), log)

    if "LINK_FROM" not in d["TO"]:
        d["TO"]["LINK_FROM"] = []

    d["TO"]["LINK_FROM"].append(d["FROM"])
    return d


def component_connection_expand(main, c, data, log=False):
    d = None

    # "-->" inter sub_component require to sub_component provide
    # "|->" inter component provide to sub_component provide
    # ">-|" inter sub_component require to component require
    # "|-|" or "|>->|"  inter component provide to component require

    if "-->" in data or "+->" in data:
        d = component_connection_expand_sc_to_sc(main, c, data, log)
    elif "|->" in data:
        d = component_connection_expand_c_to_sc(main, c, data, log)
    elif ">-|" in data or ">+|" in data:
        d = component_connection_expand_sc_to_c(main, c, data, log)
    elif "|-|" in data:
        # TODO:
        pass
        # component_connection_expand_c_to_c(main,c,data,log)
    else:
        print(colored("Error", "red"),
              ": link not to the  good format",
              colored(data, "yellow"),
              "in",
              colored(c["NAME"], "yellow"))

    return d



def component_sub_component_declaration_expand(main, c, data, need, log=False):
    w = data.replace(" ", "").split(".")
    instance = None
    interface = None

    instance = get_instance(main, c, w[0], log)

    compo_or_connetor = instance["COMPONENT"] if "COMPONENT" in instance else instance["CONNECTOR"]

    if "PROVIDE" == need:
        interface = get_provide_on_component(main,
                                             compo_or_connetor,
                                             w[1], log)
    elif "REQUIRE" == need:
        interface = get_require_on_component(main,
                                             compo_or_connetor,
                                             w[1], log)
    elif "REQUIRE_LIST" == need:
        interface = get_require_list_on_component(main,
                                                  compo_or_connetor,
                                                  w[1], log)
    else:
        print(colored("Error", "red"),
              ": need is one of [PROVIDE,REQUIRE]  not",
              colored(need, "yellow"))

    d = collections.OrderedDict()

    d["INSTANCE"] = instance
    d["INTERFACE"] = interface

    return d



def sub_component_expand(main, d, log=False):

    if isinstance(d, dict):
        return d

    elif isinstance(d, list):
        list_sub_component_expand = []

        for one_sub_component in d:
            if isinstance(one_sub_component, list):
                print("Tree function are not support")
                return None

            list_sub_component_expand.append(sub_component_expand(main, one_sub_component, log))

        return list_sub_component_expand

    elif isinstance(d, str):
        a = declaration_component_expand(main, d, log)
        return a
    else:
        return None


def component_connections_expand(main, data, log=False):
    connection_data = []
    for d in data["CONNECTION"]:
        connection_data.append(component_connection_expand(main, data, d, log))

    return connection_data



def component_expand(context, main, data, log=False):

    if isinstance(data, dict):
        if "PARENT" in data:
            # TODO check diamond
            data["PARENT"] = component_parent_expand(main, data, log)
        # Data
        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        # Function
        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

        # Sub Component
        if "COMPONENT_INSTANCE" in data:
            data["COMPONENT_INSTANCE"] = component_instances_expand(main, data, log)

        # Sub Component
        if "CONNECTOR_INSTANCE" in data:
            data["CONNECTOR_INSTANCE"] = connector_instances_expand(main, data, log)

        # provide
        if "PROVIDE" in data:
            data["PROVIDE"] = provide_expand(main, data, log)

        # REQUIRE
        if "REQUIRE" in data:
            data["REQUIRE"] = require_expand(main, data, log)

        # REQUIRE
        if "REQUIRE_LIST" in data:
            data["REQUIRE_LIST"] = require_list_expand(main, data, log)

        # Sub Component
        if "CONNECTION" in data:
            data["CONNECTION"] = component_connections_expand(main, data, log)

        return data


def component_instance_expand(main, data, log=False):
    if isinstance(data, dict):
        return data

    elif isinstance(data, str):
        d = collections.OrderedDict()
        if "WITH" in data:
            tmp_data = data.split("WITH")
            data = tmp_data[0]
            d["WITH"] = parse_arg(tmp_data[1])

        words = data.split(" ")

        d["NAME"] = words[1]
        d["COMPONENT"] = get_component(main, words[0])
        return d


def component_instances_expand(main, data, log=False):
    instance_data = []
    u = Uni()
    if "COMPONENT_INSTANCE" in data:
        for d in data["COMPONENT_INSTANCE"]:
            p = component_instance_expand(main, d, log)

            if not u.check(p["NAME"]):
                print(colored("Error:", "red"),
                      "INSTANCE en double",
                      '"'+colored(p["NAME"], "yellow")+'"',
                      "dans le DEPLOYMENT",
                      '"'+colored(data["NAME"], "yellow")+'"')

            instance_data.append(p)

    return instance_data


def declaration_interface_component_expand(main, c, data, log, need):
    w = data.split(".")
    instance = None
    interface = None

    instance = get_instance(main, c, w[0], log)

    if "COMPONENT" in instance:
        if "PROVIDE" is need:
            interface = get_provide_on_component(main,
                                                 instance["COMPONENT"],
                                                 w[1], log)
        elif "REQUIRE" is need:
            interface = get_require_on_component(main,
                                                 instance["COMPONENT"],
                                                 w[1], log)
        elif "REQUIRE_LIST" is need:
            interface = get_require_list_on_component(main,
                                                      instance["COMPONENT"],
                                                      w[1], log)
        else:
            print(colored("Error", "red"),
                  ": need is provide or require not",
                  colored(need, "yellow"))

    elif "CONNECTOR" in instance:
        if "PROVIDE" is need:
            interface = get_provide_on_connector(main,
                                                 instance["CONNECTOR"],
                                                 w[1], log)
        elif "REQUIRE" is need:
            interface = get_require_on_connector(main,
                                                 instance["CONNECTOR"],
                                                 w[1], log)
        elif "REQUIRE_LIST" is need:
            interface = get_require_list_on_component(main,
                                                      instance["CONNECTOR"],
                                                      w[1], log)

        else:
            print(colored("Error", "red"),
                  ": need is provide or require not",
                  colored(need, "yellow"))

    d = collections.OrderedDict()
    d["INSTANCE"] = instance
    d["INTERFACE"] = interface
    return d

