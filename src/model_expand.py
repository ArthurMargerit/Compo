# !/bin/env python

import collections
from model_dump import yaml

from Config import Configuration_manager
from model_exec import get_exec_function



from model_get import *
import os.path

from tools.Uni import Uni

from model_test import is_struct
from model_utils import print_me
from model_parsing_context import *

from model_expand_interface import provide_expand
from model_expand_interface import require_expand, require_list_expand

from model_expand_function import function_expand
from model_expand_data import data_expand, data_check

from model_expand_type import type_expand
from model_expand_error import error_expand
from model_expand_struct import struct_expand
from model_expand_interface import interface_expand
from model_expand_connector import connector_expand
from model_expand_link import link_expand
from model_expand_deployment import deployment_expand


def nop_expand(main, data, log=False):
    print(colored("Error:", "red"),
          "Parsing is not implemented for",
          data)
    return None


def link_instances_expand(main, data, log=False):

    link_data = []

    for d in data["LINK_INSTANCE"]:
        link_data.append(link_instance_expand(main, data, d, log))

    return link_data

def connection_expand(main, c, data, log=False):
    d = collections.OrderedDict()

    words = []
    from_cut, center, to_cut = False, False, False

    if "-(" in data and ')->' in data:
        from_cut = data.split('-(')[0]
        to_cut = data.split(')->')[-1]
        center = data.split('-(')[1].split(')->')[0]
    elif "-(" in data:
        from_cut = data.split('-(')[0]
        center = data.split('-(')[1].split(')->')[0].replace(')', '')
    elif "+(" in data:
        from_cut = data.split('+(')[0]
        center = data.split('+(')[1].split(')->')[0].replace(')', '')
    elif ")->" in data:
        to_cut = data.split(')->')[-1]
        center = data.split('-(')[0].split(')->')[0].replace('(', '')
    elif "-->" in data:
        to_cut = data.split('-->')[-1]
        from_cut = data.split('-->')[0]
    elif "+->" in data:
        to_cut = data.split('+->')[-1]
        from_cut = data.split('+->')[0]
    elif "->" in data:
        from_cut = data.split("->")[0]
        to_cut = data.split("->")[1]
    else:
        print(colored("Error", "red"), ": link not to the  good format", data)

    if center:
        d["LINK"] = get_link_instance(main, c, center.replace(" ", ""), True)

    if from_cut:
        d["FROM"] = declaration_interface_component_expand(main,
                                                           c,
                                                           from_cut.replace(" ", ""),
                                                           log,
                                                           "REQUIRE_LIST" if "+" in data else "REQUIRE")

        d["FROM"]["KIND"] = "add" if "+" in data else "set"
    if to_cut:
        d["TO"] = declaration_interface_component_expand(main,
                                                         c,
                                                         to_cut.replace(" ", ""),
                                                         log,
                                                         "PROVIDE")
    return d


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

def connections_expand(main, data, log=False):

    connection_data = []
    for d in data["CONNECTION"]:
        connection_data.append(connection_expand(main, data, d, log))

    return connection_data


def component_connections_expand(main, data, log=False):
    connection_data = []
    for d in data["CONNECTION"]:
        connection_data.append(component_connection_expand(main, data, d, log))

    return connection_data



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


def get_instance_connector_rec(p_dep, p_name):

    if "CONNECTOR_INSTANCE" in p_dep:
        for i_dep in p_dep["CONNECTOR_INSTANCE"]:
            if i_dep["NAME"] == p_name:
                return i_dep

    if "PARENT" in p_dep and p_dep["PARENT"] is not None:
        return get_instance_connector_rec(p_dep["PARENT"],
                                          p_name)

    return None


def get_instance_component_rec(p_dep, p_name):

    if "COMPONENT_INSTANCE" in p_dep:
        for i_dep in p_dep["COMPONENT_INSTANCE"]:
            if i_dep["NAME"] == p_name:
                return i_dep

    if "PARENT" in p_dep and p_dep["PARENT"] is not None:
        return get_instance_component_rec(p_dep["PARENT"], p_name)

    return None


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
    if p_log==True and  r == None:
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
        return get_provide_on_component_rec(p_comp["PARENT"],p_name)

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


def link_instance_expand(main, c, data, log=False):

    d = collections.OrderedDict()

    if "WITH" in data:
        tmp_data = data.split("WITH")
        d["WITH"] = parse_arg(tmp_data[1])
        data = tmp_data[0]

    words = data.split(" ")
    d["TYPE"] = get_link(main, words[0])
    d["NAME"] = words[1]

    return d



def import_expand(context, main, data, log=False):

    if isinstance(data, dict):
        print("error syntax need to be a file ")
        return

    if isinstance(data, list):
        print("error syntax need to be a file ")
        return

    if isinstance(data, str):
        file = data
        list_path = Configuration_manager.get_conf().get("import_path")
        valid = None

        for l in list_path:
            path_file = l + os.path.sep + file
            if os.path.isfile(path_file):
                valid = path_file

        if valid is None:
            print(colored("Error","red"),"\"%s\""% colored(file,"yellow"), "doesn't exit")
            for m in context_list_file(context):
                print(">", m)

            exit(1)

        if len(context_list_file(context)) > 100:
            print(colored("Error","red"),"Import stack upper than 100, maybe a infinite loop?")
            for m in context_list_file(context):
                print(">", m)
                exit(1)

        main_import = get_empty_main()
        main_inport = file_expand(context, main_import, valid, log)

        return {"NAME": file,
                "PATH": valid,
                "MAIN": main_inport}


def get_expand_function():

    EXPAND_FONCTION = {
        "IMPORT": import_expand,
        "TYPE": type_expand,
        "ERROR": error_expand,
        "LINK": link_expand,
        "STRUCT": struct_expand,
        "INTERFACE": interface_expand,
        "CONNECTOR": connector_expand,
        "COMPONENT": component_expand,
        "DEPLOYMENT": deployment_expand}

    return EXPAND_FONCTION


def use_type_in_struct(type, struct):
    for d in struct["DATA"]:
        if use_type_in_TYPE(type, d):
            return True
    return False


def use_type_in_TYPE(type, TYPE):
    if TYPE == type:
        return True

    # on a une struct
    if "DATA" in TYPE:
        return use_type_in_struct(TYPE)


def get_struct_with_type(type, structs):

    use_by_structs = []
    for struct in structs:
        if use_type_in_struct(type, struct):
            use_by_structs.append(struct)

    return use_by_structs


def use_type_in_interface(type, interface):

    if "DATA" in interface:
        for d in interface["DATA"]:
            if use_type_in_TYPE(type, d["TYPE"]):
                return True

    if "FUNCTION" in interface:
        for d in interface["FUNCTION"]:
            if use_type_in_TYPE(type, interface["RETURN"]):
                return True
            for param in d["SIGNATURE"]:
                if use_type_in_TYPE(type, param["TYPE"]):
                    return True


def get_interfaces_with_type(type, interfaces):

    use_by_interface = []

    for interface in interfaces:
        if use_type_in_interface(type, interface):
            use_by_interface.append(interface)

    return use_by_interface


def use_type_in_component(type, component):

    if "DATA" in component:
        for d in component["DATA"]:
            if use_type_in_TYPE(type, d):
                return True
    if "PROVIDE" in component:
        for d in component["PROVIDE"]:
            if use_type_in_interface(type, d):
                return True

    if "REQUIRE" in component:
        for d in component["REQUIRE"]:
            if use_type_in_interface(type, d):
                return True

    return False


def get_component_with_type(type, components):

    # STRUCT CHECK
    use_by_component = []

    for component in components:
        if use_type_in_component(type, component):
            use_by_component.append(component)

    return use_by_component


def use_type_in_deployment(type, deployment):

    if "COMPONENT_INSTANCE" in deployment:
        for d in deployment["COMPONENT_INSTANCE"]:
            if use_type_in_component(type, deployment):
                return True

    return False


def get_deployment_with_type(type, deployments):
    use_by_deployment = []

    for deployment in deployments:
        if use_type_in_deployment(type, deployment):
            use_by_deployment.append(deployment)

    return use_by_deployment


def file_expand(context, main, file_path, log=False):

    conf = Configuration_manager.get_conf()

    # apply a read only value as real values
    if not conf.exist("import_path"):
        conf.set("import_path", conf.get("import_path"))

    conf.get("import_path").append(os.path.dirname(file_path))

    if main is None:
        main = get_empty_main()

    main["FILE"] = os.path.basename(file_path)

    if context is None:
        context = context_create(file_path)
    else:
        context_add_file(context, file_path)

    if not os.path.isfile(file_path):
        print(colored("error", "red"),
              "\"%s\"" % colored(file_path, "yellow"),
              "doesn't exist")
        exit(1)

    with open(file_path) as file:
        data = yaml.load(file, Loader=yaml.SafeLoader)

    EXPAND_FONCTION = get_expand_function()
    EXEC_FUNCTION = get_exec_function()

    if data is None:
        return main

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        if function_selector in EXPAND_FONCTION:
            information = EXPAND_FONCTION[function_selector](context,
                                                             main,
                                                             information,
                                                             log=True)

            if log:
                print(function_selector)
                print("=>", information, "\n")

            main[function_selector+"S"][information["NAME"]] = information
            continue

        if function_selector in EXEC_FUNCTION:
            EXEC_FUNCTION[function_selector](main, information)
            continue

    context_pop_file(context)
    conf.get("import_path").pop()

    return main


def str_expand(main, txt, log=False):

    if main is None:
        main = get_empty_main()

    main["FILE"] = "d"

    data = yaml.load(txt, loader=yaml.SafeLoader)

    EXPAND_FONCTION = get_expand_function()
    EXEC_FUNCTION = get_exec_function()

    if data is None:
        return main

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        if function_selector in EXPAND_FONCTION:
            f = EXPAND_FONCTION[function_selector]
            information = f(context, main, information, log=True)

            if log:
                print(function_selector)
                print("=>", information, "\n")

            main[function_selector+"S"][information["NAME"]] = information
            continue

        if function_selector in EXEC_FUNCTION:
            EXEC_FUNCTION[function_selector](main, information)
            continue

    return main
