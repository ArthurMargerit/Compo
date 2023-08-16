
import collections
from tools.Uni import Uni
from tools.Log import ERR, WARN

from model_get import get_component, get_instance
from model_check import is_valid_name

from model_get import get_require_on_component, get_provide_on_component
from model_get import get_receiver_on_component, get_emitter_on_component

from model_get import get_require_on_connector, get_provide_on_connector
from model_get import get_receiver_on_connector, get_emitter_on_connector

from model_get import get_require_list_on_component

from model_expand_parent import component_parent_expand
from model_expand_connector import connector_instances_expand

from model_expand_function import function_expand
from model_expand_data import data_expand, parse_arg

from model_expand_interface import provide_expand
from model_expand_interface import require_expand, require_list_expand

from model_expand_event import receiver_expand, emitter_expand
from model_expand_option import options_expand


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


def component_connection_bus_expand_sc_to_sc(main, c, data, log):
    d = collections.OrderedDict()
    if "==>" in data:
        l_from_to = data.split("==>")
    else:
        l_from_to = data.split("=>")

    d["LINK"] = "SC_E_TO_SC_R"

    d["FROM"] = component_sub_component_declaration_expand(main, c,
                                                           l_from_to[0],
                                                           "EMITTER", log)

    d["TO"] = component_sub_component_declaration_expand(main, c,
                                                         l_from_to[1],
                                                         "RECEIVER", log)

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


def component_connection_bus_expand_c_to_sc(main, c, data, log):
    d = collections.OrderedDict()
    l_from_to = data.split("|=>")

    d["LINK"] = "C_R_TO_SC_R"
    d["FROM"] = get_receiver_on_component(main, c,
                                          l_from_to[0].replace(" ", ""), log)

    d["TO"] = component_sub_component_declaration_expand(main, c,
                                                         l_from_to[1],
                                                         "RECEIVER", log)

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


def component_connection_bus_expand_sc_to_c(main, c, data, log):
    d = collections.OrderedDict()
    l_from_to = data.split(">=|")

    d["LINK"] = "SC_E_TO_C_E"
    d["FROM"] = component_sub_component_declaration_expand(main, c,
                                                           l_from_to[0],
                                                           "EMITTER", log)
    # d["FROM"]["KIND"] = "set"
    d["TO"] = get_emitter_on_component(main, c,
                                       l_from_to[1].replace(" ", ""), log)

    if "LINK_FROM" not in d["TO"]:
        d["TO"]["LINK_FROM"] = []

    d["TO"]["LINK_FROM"].append(d["FROM"])
    return d


def component_connection_bus_expand_c_to_c(main, c, data, log):
    d = collections.OrderedDict()
    l_from_to = data.split("|=|")

    d["LINK"] = "C_R_TO_C_E"
    d["FROM"] = get_receiver_on_component(main, c,
                                          l_from_to[0].replace(" ", ""), log)

    d["TO"] = get_emitter_on_component(main, c,
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
        pass
        # d = component_connection_expand_c_to_c(main, c, data, log)
    elif "|=>" in data:
        d = component_connection_bus_expand_c_to_sc(main, c, data, log)
    elif ">=|" in data:
        d = component_connection_bus_expand_sc_to_c(main, c, data, log)
    elif "|=|" in data:
        d = component_connection_bus_expand_c_to_c(main, c, data, log)
    elif "==>" in data or "=>" in data:
        d = component_connection_bus_expand_sc_to_sc(main, c, data, log)
    else:
        ERR(" link not to the  good format ",
            ">!y(", data, ")<",
            " in ",
            ">!y(", c["NAME"], ")")

    return d


def component_sub_component_declaration_expand(main, c, data, need, log=False):
    w = data.replace(" ", "").split(".")
    instance = None
    interface = None

    kind = "None"
    instance = get_instance(main, c, w[0], log)
    if "COMPONENT" in instance:
        compo_or_connetor = instance["COMPONENT"]
    else:
        compo_or_connetor = instance["CONNECTOR"]

    if "PROVIDE" == need:
        interface = get_provide_on_component(main,
                                             compo_or_connetor,
                                             w[1], log)
        kind = "INTERFACE"
    elif "REQUIRE" == need:
        interface = get_require_on_component(main,
                                             compo_or_connetor,
                                             w[1], log)
        kind = "INTERFACE"
    elif "RECEIVER" == need:
        interface = get_receiver_on_component(main,
                                              compo_or_connetor,
                                              w[1], log)
        kind = "BUS"
    elif "EMITTER" == need:
        interface = get_emitter_on_component(main,
                                             compo_or_connetor,
                                             w[1], log)
        kind = "BUS"
    elif "REQUIRE_LIST" == need:
        interface = get_require_list_on_component(main,
                                                  compo_or_connetor,
                                                  w[1], log)
        kind = "INTERFACE"
    else:
        ERR("need is one of [PROVIDE,REQUIRE,REQUIRE_LIST,EMITTER,RECEIVER] not ",
            ">!y(", need, ")<")

    d = collections.OrderedDict()

    d["INSTANCE"] = instance
    d[kind] = interface
    d["TYPE"] = interface

    return d


def list_name(l_d):
    return [l["NAME"] for l in l_d]


def sub_component_expand(main, d, log=False):

    if isinstance(d, dict):
        return d

    elif isinstance(d, list):
        list_sub_component_expand = []

        for one_sub_component in d:
            if isinstance(one_sub_component, list):
                ERR("Tree function are not support")

            sc_exp = sub_component_expand(main, one_sub_component, log)
            list_sub_component_expand.append(sc_exp)

        return list_sub_component_expand

    elif isinstance(d, str):
        a = component_instances_expand(main, d, log)
        return a
    else:
        return None


def component_connections_expand(main, data, log=False):
    connection_data = []
    for d in data["CONNECTION"]:
        connection_data.append(component_connection_expand(main, data, d, log))

    return connection_data


def component_check(l_compo):

    if "NAME" not in l_compo:
        ERR("struct sans nom")

    is_valid_name(l_compo["NAME"])

    if ("DATA" not in l_compo and "PROVIDE" not in l_compo and "REQUIRE" not in l_compo and "SUB_COMPONENT" not in l_compo):
        WARN("component !y(", l_compo["NAME"],
             ") without data,provide and require")

    u = Uni()
    list_of_uni_name = ["DATA", "PROVIDE", "REQUIRE",
                        "COMPONENT_INSTANCE", "CONNECTOR_INSTANCES"]

    for i_uni in list_of_uni_name:
        d = list_name(l_compo[i_uni]) if i_uni in l_compo else []
        r, t = u.checks(d)

        if not r:
            ERR("The field !y(", t, ') define in !y(',
                i_uni, ") was define in a other section.")


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

        # Options
        if "OPTIONS" not in data:
            data["OPTIONS"] = {}
        data["OPTIONS"] = options_expand("COMPONENT", data["OPTIONS"])

        # Sub Component
        if "COMPONENT_INSTANCE" in data:
            data["COMPONENT_INSTANCE"] = component_instances_expand(main,
                                                                    data,
                                                                    log)

        # Sub Component
        if "CONNECTOR_INSTANCE" in data:
            data["CONNECTOR_INSTANCE"] = connector_instances_expand(main,
                                                                    data,
                                                                    log)

        # provide
        if "PROVIDE" in data:
            data["PROVIDE"] = provide_expand(main, data, log)

        if "RECEIVER" in data:
            data["RECEIVER"] = receiver_expand(main, data, log)

        if "EMITTER" in data:
            data["EMITTER"] = emitter_expand(main, data, log)

        # REQUIRE
        if "REQUIRE" in data:
            data["REQUIRE"] = require_expand(main, data, log)

        # REQUIRE
        if "REQUIRE_LIST" in data:
            data["REQUIRE_LIST"] = require_list_expand(main, data, log)

        # Sub Component
        if "CONNECTION" in data:
            data["CONNECTION"] = component_connections_expand(main, data, log)

        component_check(data)
        return data


def component_instance_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    if isinstance(data, str):
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
                ERR("INSTANCE en double",
                    '>!y(', p["NAME"], ')<',
                    " in DEPLOYMENT ",
                    '>!y(', data["NAME"], ')<')

            instance_data.append(p)

    return instance_data


def declaration_interface_component_expand(main, c, data, log, need):
    w = data.split(".")
    instance = None
    interface = None

    instance = get_instance(main, c, w[0], log)

    if "COMPONENT" in instance:
        if "PROVIDE" == need:
            interface = get_provide_on_component(main,
                                                 instance["COMPONENT"],
                                                 w[1], log)
        elif "REQUIRE" == need:
            interface = get_require_on_component(main,
                                                 instance["COMPONENT"],
                                                 w[1], log)
        elif "REQUIRE_LIST" == need:
            interface = get_require_list_on_component(main,
                                                      instance["COMPONENT"],
                                                      w[1], log)
        else:
            ERR("need is provide or require not",
                "!y(", need, ")")

    elif "CONNECTOR" in instance:
        if "PROVIDE" == need:
            interface = get_provide_on_connector(main,
                                                 instance["CONNECTOR"],
                                                 w[1], log)
        elif "REQUIRE" == need:
            interface = get_require_on_connector(main,
                                                 instance["CONNECTOR"],
                                                 w[1], log)
        elif "REQUIRE_LIST" == need:
            interface = get_require_list_on_component(main,
                                                      instance["CONNECTOR"],
                                                      w[1], log)

        else:
            ERR("need is provide or require not",
                "!y(", need, ")")

    d = collections.OrderedDict()
    d["INSTANCE"] = instance
    d["INTERFACE"] = interface
    d["TYPE"] = interface
    return d


def declaration_bus_component_expand(main, c, data, log, need):
    w = data.split(".")
    instance = None
    interface = None

    instance = get_instance(main, c, w[0], log)

    if "COMPONENT" in instance:
        if "EMITTER" == need:
            interface = get_emitter_on_component(main,
                                                 instance["COMPONENT"],
                                                 w[1], log)
        elif "RECEIVER" == need:
            interface = get_receiver_on_component(main,
                                                  instance["COMPONENT"],
                                                  w[1], log)
        else:
            ERR("need is provide or require not",
                "!y(", need, ")")

    elif "CONNECTOR" in instance:
        if "EMITTER" == need:
            interface = get_emitter_on_connector(main,
                                                 instance["CONNECTOR"],
                                                 w[1], log)
        elif "RECEIVER" == need:
            interface = get_receiver_on_connector(main,
                                                  instance["CONNECTOR"],
                                                  w[1], log)
        else:
            ERR("need is provide or require not",
                "!y(", need, ")")

    d = collections.OrderedDict()
    d["INSTANCE"] = instance
    d["BUS"] = interface
    d["TYPE"] = interface
    return d
