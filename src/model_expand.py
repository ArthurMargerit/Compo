# !/bin/env python

import collections
from model_dump import yaml
from termcolor import colored
from Config import Configuration_manager
from model_exec import get_exec_function
from model_get import get_type_or_struct, get_interface, get_component, get_stuct, get_empty_main, get_link, get_link_instance
import os.path
from tools.Uni import Uni
from model_test import is_struct
from model_utils import print_me
from model_parsing_context import context_create, context_add_file, context_pop_file, context_list_file
from model_expand_parent import struct_parent_expand, interface_parent_expand, component_parent_expand, deployment_parent_expand, link_parent_expand


def type_expand(context, main, data, log=False):

    if isinstance(data, dict):
        if "DYNAMIC" not in data:
            data["DYNAMIC"] = False

        if "ARG" in data and data["DYNAMIC"] == False:
            print(colored("Error:", "red"),
                  "Type",
                  colored(data["NAME"], "yellow"),
                  "is not dynamic then no ARG")

        return data

    elif isinstance(data, str):

        words = data.split(" ")
        if len(words) < 2:
            print("wrong number of word in " + data)
            return

        a = collections.OrderedDict()
        a["NAME"] = words[-1]
        a["DEFINITION"] = " ".join(words[0:-1])
        a["DYNAMIC"] = True
        return a

    else:
        print(colored("Error:", "red"),
              " no implementation for ",
              colored(data, "red"))
        return


def declaration_expand(main, d, log=False):

    if isinstance(d, dict):
        r = collections.OrderedDict()
        r["NAME"] = d["NAME"]
        r["TYPE"] = get_type_or_struct(main, d["TYPE"])
        r["DEFAULT"] = default_expand(main, d["DEFAULT"])
        return r

    elif isinstance(d, str):
        words = d.split(" ")
        r = collections.OrderedDict()

        r["NAME"] = words[1]
        r["TYPE"] = get_type_or_struct(main, words[0])
        if have_default(d):
            r["DEFAULT"] = default_expand(main,
                                          r["TYPE"],
                                          d.split("DEFAULT")[1],
                                          log)
        return r


def have_default(d):
    if isinstance(d, dict):
        return "DEFAULT" in d

    if isinstance(d, str):
        return "DEFAULT" in d

import ast
def parse_arg(data):
    position_first_realchar = 0
    for a in data:
        if a == " ":
            position_first_realchar += 1
        else:
            break
    data = data[position_first_realchar:]
    r = ast.literal_eval(data)
    return r


def default_expand(main, Type, data, log=False):

    if data is None or data == []:
        return ""

    if is_struct(Type["NAME"], main["STRUCTS"]):
        return parse_arg(data)
        #remove space at begin
    else:
        return data

    return "Erreur"

def data_expand(main, data, log=False):

    data_parser = []
    u = Uni()

    for d in data["DATA"]:
        p = declaration_expand(main, d, log)
        if not u.check(p["NAME"]):
            print(colored("Error:", "red"),
                  "nom en double",
                  '"'+colored(p["NAME"], "yellow")+'"',
                  "dans la struct",
                  '"'+colored(data["NAME"], "yellow")+'"')
        data_parser.append(p)

    return data_parser


def struct_expand(context, main, data, log=False):

    if isinstance(data, dict):

        if "PARENT" in data:
            data["PARENT"] = struct_parent_expand(main, data["PARENT"])

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

        check_struct(data)
        return data

    return None


def check_struct(data):
    if "NAME" not in data:
        print("struct sans nom")

    if "DATA" not in data:
        print("struct sans DATA")

    else:
        if not isinstance(data["DATA"], list):
            print("DATA is not a list")
        else:
            for d in data["DATA"]:
                check_declaration(d)


def check_declaration(data):
    if "NAME" not in data:
        print("declaration sans NAME")

    if "TYPE" not in data:
        print("declaration sans TYPE")
    else:
        if not isinstance(data, dict):
            print("TYPE not link to a TYPE in TYPES")


def nop_expand(main, data, log=False):
    print(colored("Error:", "red"),
          "Parsing is not implemented for",
          data)
    return None


def interface_expand(context, main, data, log=False):

    if "PARENT" in data:
        data["PARENT"] = interface_parent_expand(main, data["PARENT"], log)

    if "DATA" in data:
        data["DATA"] = data_expand(main, data, log)

    if "FUNCTION" in data:
        data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

    return data


def signature_expand(main, d, log=False):

    if isinstance(d, dict):
        return d
    elif isinstance(d, str):

        if not (d[0] == "(" and d[-1] == ")"):
            print("error pas de (..) pour la signature ", d, d[-1], d[0])
            return

        if d == "()":
            return []

        element_dico = []
        base = d[1:-1].replace(", ",",").replace(" ,",",")
        elements = base.split(",")

        for element in elements:
            element_dico.append(declaration_expand(main, element, log))

        return element_dico


def function_expand(main, d, log=False):

    if isinstance(d, dict):
        return d

    elif isinstance(d, list):
        list_function_expand = []

        for one_function in d:
            if isinstance(one_function, list):
                print("Tree function are not support")
                return None
            list_function_expand.append(function_expand(main, one_function, log))

        return list_function_expand

    elif isinstance(d, str):

        ret_type,func_name = [ s for s  in d[:d.find("(")].split(" ") if len(s)]
        signature= d[d.find("("):]

        a = {"NAME": func_name,
             "RETURN": get_type_or_struct(main, ret_type),
             "SIGNATURE": signature_expand(main,
                                           signature,
                                           log)}
        return a
    else:
        return None

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
        if "SUB_COMPONENT" in data:
            data["SUB_COMPONENT"] = sub_component_expand(main, data["SUB_COMPONENT"], log)

        # provide
        if "PROVIDE" in data:
            data["PROVIDE"] = provide_expand(main, data, log)

        # REQUIRE
        if "REQUIRE" in data:
            data["REQUIRE"] = require_expand(main, data, log)

        # Sub Component
        if "CONNECTION" in data:
            data["CONNECTION"] = component_connections_expand(main, data, log)

        return data


def require_expand(main, data, log=False):
    require_parser = []
    for d in data["REQUIRE"]:
        require_parser.append(declaration_interface_expand(main,
                                                           d,
                                                           log))
    return require_parser


def provide_expand(main, data, log=False):
    provide_parser = []
    for d in data["PROVIDE"]:
        provide_parser.append(declaration_interface_expand(main,
                                                           d,
                                                           log))
    return provide_parser


def declaration_interface_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, list):
        return None

    elif isinstance(data, str):
        words = data.split(" ")
        d = collections.OrderedDict()
        d["NAME"] = words[1]
        d["INTERFACE"] = get_interface(main, words[0])
        return d


def instance_expand(main, data, log=False):
    instance_data = []
    u = Uni()
    for d in data["INSTANCE"]:
        p = declaration_component_expand(main, d, log)

        if not u.check(p["NAME"]):
            print(colored("Error:", "red"),
                  "INSTANCE en double",
                  '"'+colored(p["NAME"], "yellow")+'"',
                  "dans le DEPLOYMENT",
                  '"'+colored(data["NAME"], "yellow")+'"')

        instance_data.append(p)

    return instance_data


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
        center = data.split('-(')[1].split(')->')[0].replace(')','')
    elif ")->" in data:
        to_cut = data.split(')->')[-1]
        center = data.split('-(')[0].split(')->')[0].replace('(','')
    elif "-->" in data:
        to_cut = data.split('-->')[-1]
        from_cut = data.split('-->')[0]
    else:
        print(colored("Error","red"),": link not to the  good format", data)

    if center:
        d["LINK"] = get_link_instance(main, c, center.replace(" ",""), True)

    if from_cut:
        d["FROM"] = declaration_interface_component_expand(main,
                                                           c,
                                                           from_cut.replace(" ",""),
                                                           log,
                                                           "REQUIRE")

    if to_cut:
        d["TO"] = declaration_interface_component_expand(main,
                                                         c,
                                                         to_cut.replace(" ",""),
                                                         log,
                                                         "PROVIDE")
    return d

def component_connection_expand_sc_to_sc(main, c, data, log):
    d = collections.OrderedDict()
    l_from_to = data.split("-->")

    d["LINK"] = "SC_R_TO_SC_P"
    d["FROM"] = component_sub_component_declaration_expand(main, c, l_from_to[0], "REQUIRE", log)
    d["TO"]   = component_sub_component_declaration_expand(main, c, l_from_to[1], "PROVIDE", log)
    return d

def component_connection_expand_c_to_sc(main, c, data, log):
    d = collections.OrderedDict()
    l_from_to = data.split("|->")

    d["LINK"] = "C_P_TO_SC_P"
    d["FROM"] = get_provide_on_component(main, c, l_from_to[0].replace(" ", ""), log)
    d["TO"]   = component_sub_component_declaration_expand(main, c, l_from_to[1], "PROVIDE", log)

    d["FROM"]["LINK_TO"] = d["TO"]


    return d

def component_connection_expand_sc_to_c(main, c, data, log):
    d = collections.OrderedDict()
    l_from_to = data.split(">-|")

    d["LINK"] = "SC_R_TO_C_R"
    d["FROM"]   = component_sub_component_declaration_expand(main, c, l_from_to[0], "REQUIRE", log)
    d["TO"] = get_require_on_component(main, c, l_from_to[1].replace(" ", ""), log)

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

    if "-->" in data:
        d = component_connection_expand_sc_to_sc(main, c, data, log)
    elif "|->" in data:
        d = component_connection_expand_c_to_sc(main, c, data, log)
    elif ">-|" in data:
        d = component_connection_expand_sc_to_c(main, c, data, log)
    elif "|-|" in data:
        # TODO:
        pass
        # component_connection_expand_c_to_c(main,c,data,log)
    else:
        print(colored("Error","red"),
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


def deployment_expand(context, main, data, log=False):

    if isinstance(data, dict):

        if "PARENT" in data:
            data["PARENT"] = deployment_parent_expand(main, data, log)

        if "INSTANCE" in data:
            data["INSTANCE"] = instance_expand(main, data, log)

        if "LINK_INSTANCE" in data:
            data["LINK_INSTANCE"] = link_instances_expand(main, data, log)

        if "CONNECTION" in data:
            data["CONNECTION"] = connections_expand(main, data, log)

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data, log)

        return data



def declaration_component_expand(main, data, log=False):

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


def component_sub_component_declaration_expand(main, c, data, need, log= False):
    w = data.replace(" ","").split(".")
    instance = None
    interface = None

    instance = get_instance_on_component(main, c, w[0], log)

    if "PROVIDE" is need:
        interface = get_provide_on_component(main, instance["COMPONENT"], w[1], log)
    elif "REQUIRE" is need:
        interface = get_require_on_component(main, instance["COMPONENT"], w[1], log)
    else:
        print(colored("Error", "red"), ": need is one of [PROVIDE,REQUIRE]  not", colored(need,"yellow"))

    d = collections.OrderedDict()
    d["INSTANCE"] = instance
    d["INTERFACE"] = interface

    return d


def declaration_interface_component_expand(main, c, data, log, need):
    w = data.split(".")
    instance = None
    interface = None

    instance = get_instance_on_deployment(main, c, w[0], log)

    if "PROVIDE" is need:
        interface=get_provide_on_component(main, instance["COMPONENT"], w[1], log)
    elif "REQUIRE" is need:
        interface=get_require_on_component(main, instance["COMPONENT"], w[1], log)
    else:
        print(colored("Error", "red"), ": need is provide or require not", colored(need,"yellow"))

    d = collections.OrderedDict()
    d["INSTANCE"] = instance
    d["INTERFACE"] = interface

    return d

def get_instance_on_deployment_rec(p_dep, p_name):

    if "INSTANCE" in p_dep:
        for i_dep in p_dep["INSTANCE"]:
            if i_dep["NAME"] == p_name:
                return i_dep

    if "PARENT" in p_dep and p_dep["PARENT"] != None:
        return get_instance_on_deployment_rec(p_dep["PARENT"], p_name)

    return None

def get_instance_on_deployment(p_main, p_dep, p_name, p_log=False):
    r = get_instance_on_deployment_rec(p_dep, p_name)
    if p_log == True and r == None:
        print(colored("Error:", "red"),
              "l'INSTANCE",
              colored(p_name, "yellow"),
              "n'est pas definie dans le DEPLOYEMENT",
              colored(p_dep["NAME"], "yellow"))
    return r


def get_instance_on_component_rec(p_dep, p_name):

    if "SUB_COMPONENT" in p_dep:
        for i_dep in p_dep["SUB_COMPONENT"]:
            if i_dep["NAME"] == p_name:
                return i_dep

    if "PARENT" in p_dep and p_dep["PARENT"] != None:
        return get_instance_on_component_rec(p_dep["PARENT"], p_name)

    return None

def get_instance_on_component(p_main, p_dep, p_name, p_log=False):
    r = get_instance_on_component_rec(p_dep, p_name)
    if p_log == True and r == None:
        print(colored("Error:", "red"),
              "l'INSTANCE (sub component)",
              colored(p_name, "yellow"),
              "n'est pas definie dans le COMPONENT",
              colored(p_dep["NAME"], "yellow"))

    return r



def get_require_on_component_rec(p_comp, p_name):

    if "REQUIRE" in p_comp:
        for i_req in p_comp["REQUIRE"]:
            if i_req["NAME"] == p_name:
                return i_req

    if "PARENT" in p_comp and p_comp["PARENT"] != None:
        return get_require_on_component_rec(p_comp["PARENT"],p_name)

    return None

def get_require_on_component(p_main, p_comp, p_name, p_log=False):

    r = get_require_on_component_rec(p_comp, p_name)
    if p_log==True and  r == None:
        print(colored("Error:", "red"),
              "l'INTERFACE",
              colored(p_name, "yellow"),
              "n'est pas definie dans le COMPONENT ",
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
    if p_log==True and  r == None:
        print(colored("Error:", "red"),
              "l'INTERFACE",
              colored(p_name, "yellow"),
              "n'est pas definie dans le COMPONENT ",
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
        "LINK": link_expand,
        "STRUCT": struct_expand,
        "INTERFACE": interface_expand,
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

    if "INSTANCE" in deployment:
        for d in deployment["INSTANCE"]:
            if use_type_in_component(type, deployment):
                return True

    return False


def get_deployment_with_type(type, deployments):
    use_by_deployment = []

    for deployment in deployments:
        if use_type_in_deployment(type, deployment):
            use_by_deployment.append(deployment)

    return use_by_deployment


def file_expand(context ,main, file_path, log=False):

    conf = Configuration_manager.get_conf()

    # apply a read only value as real values
    if not conf.exist("import_path"):
        conf.set("import_path", conf.get("import_path"))

    conf.get("import_path").append(os.path.dirname(file_path))

    if main is None:
        main = get_empty_main()

    if context is None:
        context = context_create(file_path)
    else:
        context_add_file(context, file_path)

    if not os.path.isfile(file_path):
        print(colored("error","red"),"\"%s\""%colored(file_path, "yellow"), "doesn't exist");
        exit(1)

    with open(file_path) as file:
        data = yaml.load(file, Loader = yaml.SafeLoader)

    EXPAND_FONCTION = get_expand_function()
    EXEC_FUNCTION = get_exec_function()

    if data is None:
        return main

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        if function_selector in EXPAND_FONCTION:
            information = EXPAND_FONCTION[function_selector](context, main, information, log=True)

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

    data = yaml.load(txt,loader=yaml.SafeLoader)

    EXPAND_FONCTION = get_expand_function()
    EXEC_FUNCTION = get_exec_function()

    if data is None:
        return main

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        if function_selector in EXPAND_FONCTION:
            information = EXPAND_FONCTION[function_selector](context, main, information, log=True)

            if log:
                print(function_selector)
                print("=>", information, "\n")

            main[function_selector+"S"][information["NAME"]] = information
            continue

        if function_selector in EXEC_FUNCTION:
            EXEC_FUNCTION[function_selector](main, information)
            continue

    return main


def link_expand(context, main, data, log=False):

    if isinstance(data, dict):
        d = collections.OrderedDict(data)

        if "DATA" in d:
            d["DATA"] = data_expand(main, data, log)

        if "DATA" in d:
            pass

        if "PARENT" in d:
            d["PARENT"] = link_parent_expand(main, d, log=True)

        return d
    else:
        print("error this type of link is not manage")

    return "Error"
