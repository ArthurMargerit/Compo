# !/bin/env python

import collections
from model_dump import yaml
from termcolor import colored
from Config import Configuration_manager
from model_exec import get_exec_function
from model_get import get_type_or_struct, get_interface, get_component, get_stuct, get_empty_main, get_link
import os.path
from tools.Uni import Uni
from model_expand_parent import struct_parent_expand, interface_parent_expand, component_parent_expand, deployment_parent_expand

def type_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, str):

        words = data.split(" ")
        if len(words) < 2:
            print("wrong number of word in " + data)
            return
        a = collections.OrderedDict()
        a["NAME"] = words[-1]
        a["DEFINITION"] = " ".join(words[0:-1])
        return a

    else:
        print(colored("ERROR:", "red"),
              " no implementation for ",
              colored(data,"red"))
        return


def declaration_expand(main, d, log=False):

    if isinstance(d, dict):
        r = collections.OrderedDict()
        r["NAME"] = d["NAME"]
        r["TYPE"] = get_type_or_struct(main, d["TYPE"])

        return r

    elif isinstance(d, str):
        words = d.split(" ")
        d = collections.OrderedDict()

        d["NAME"] = words[-1]
        d["TYPE"] = get_type_or_struct(main, words[0])

        return d


def data_expand(main, data, log=False):

    data_parser = []
    u = Uni()

    for d in data["DATA"]:
        p = declaration_expand(main, d, log)
        if not u.check(p["NAME"]):
            print(colored("ERROR:", "red"),
                  "nom en double",
                  '"'+colored(p["NAME"], "yellow")+'"',
                  "dans la struct",
                  '"'+colored(data["NAME"], "yellow")+'"')
        data_parser.append(p)

    return data_parser


def struct_expand(main, data, log=False):

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
        print("struct sans nom")

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


def interface_expand(main, data, log=False):

    if "PARENT" in data:
        data["PARENT"] = interface_parent_expand(main, data, log)

    if "DATA" in data:
        data["DATA"] = data_expand(main, data, log)

    if "FUNCTION" in data:
        data["FUNCTION"] = function_expand(main, data, log)

    return data


def signature_expand(main, d, log=False):

    if isinstance(d, dict):
        return d
    elif isinstance(d, str):

        if not (d[0] == "(" and d[-1] == ")"):
            print("error pas de (..) pour la signature ", d, d[-1], d[0])
            return

        if d == "()" :
            return []

        element_dico = []
        elements = d[1:-1].split(",")
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
            list_function_expand.append(one_function)

        return list_function_expand

    elif isinstance(d, str):
        words = d.split(" ")
        a = {"NAME": words[1],
             "RETURN": get_type_or_struct(main, words[0]),
             "SIGNATURE": signature_expand(main,
                                           " ".join(words[2:]),
                                           log)}
        return a
    else:
        return None


def component_expand(main, data, log=False):

    if isinstance(data, dict):
        if "PARENT" in data:
            # TODO check diamond
            data["PARENT"] = component_parent_expand(main, data, log)
        # Data
        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        # Function
        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data, log)

        # provide
        if "PROVIDE" in data:
            data["PROVIDE"] = provide_expand(main, data, log)

        # REQUIRE
        if "REQUIRE" in data:
            data["REQUIRE"] = require_expand(main, data, log)

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
            print(colored("ERROR:", "red"),
                  "INSTANCE en double",
                  '"'+colored(p["NAME"], "yellow")+'"',
                  "dans le DEPLOYMENT",
                  '"'+colored(data["NAME"], "yellow")+'"')

        instance_data.append(p)

    return instance_data


def link_expand(main, data, log=False):

    link_data = []
    for d in data["LINK"]:
        link_data.append(declaration_link_expand(main, data, d, log))

    return link_data


def deployment_expand(main, data, log=False):

    if isinstance(data, dict):

        if "PARENT" in data:
            data["PARENT"] = deployment_parent_expand(main, data, log)

        if "INSTANCE" in data:
            data["INSTANCE"] = instance_expand(main, data, log)

        if "LINK" in data:
            data["LINK"] = link_expand(main, data, log)

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data, log)

        return data


def declaration_component_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, str):
        words = data.split(" ")
        d = collections.OrderedDict()
        d["NAME"] = words[1]
        d["COMPONENT"] = get_component(main, words[0])
        return d


def declaration_interface_component_expand(main, c, data, log, need):

    w = data.split(".")

    # TODO clean
    instance = None
    for i in c["INSTANCE"]:
        if i["NAME"] == w[0]:
            instance = i

    if instance is None:
        print(colored("Error:", "red"),
              "l'INSTANCE",
              colored(w[0], "yellow"),
              "n'est pas definie dans le DEPLOYEMENT",
              colored(c["NAME"], "yellow"))

    # TODO clean
    interface = None
    for i in instance["COMPONENT"][need]:
        if i["NAME"] == w[1]:
            interface = i

    if interface is None:
        print(colored("Error:", "red"),
              "l'INTERFACE",
              colored(w[1], "yellow"),
              "n'est pas definie dans le COMPONENT",
              colored(instance["COMPONENT"]["NAME"]+" "+w[0], "yellow"))

    d = collections.OrderedDict()
    d["INSTANCE"] = instance
    d["INTERFACE"] = interface

    return d


def declaration_link_expand(main, c, data, log=False):
    words = data.split(" ")
    print(words)
    d = collections.OrderedDict()
    d["FROM"] = declaration_interface_component_expand(main,
                                                       c,
                                                       words[0],
                                                       log,
                                                       "REQUIRE")
    d["TYPE"] = get_link(main, words[1])
    d["TO"] = declaration_interface_component_expand(main,
                                                     c,
                                                     words[2],
                                                     log,
                                                     "PROVIDE")

    return d


def import_expand(main, data, log=False):

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
            print("NO FILE", file, "in ", list_path)
            return "ERROR " + file

        file_expand(main, valid, log)
        return {"NAME": file}


def get_expand_function():

    EXPAND_FONCTION = {
        "IMPORT": import_expand,
        "TYPE": type_expand,
        "LINK": link_expand,
        # "LINKER": linker_expand,
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


def file_expand(main, file_path, log=False):

    conf = Configuration_manager.get_conf()

    if not conf.exist("import_path"):
        conf.set("import_path", [])

    conf.get("import_path").append(os.path.dirname(file_path))

    if main is None:
        main = get_empty_main()

    with open(file_path) as file:
        data = yaml.load(file)

    EXPAND_FONCTION = get_expand_function()
    EXEC_FUNCTION = get_exec_function()

    if data is None:
        return main

    for a in data:
        function_selector = list(a)[0]
        print(function_selector)
        information = a[function_selector]

        if function_selector in EXPAND_FONCTION:
            information = EXPAND_FONCTION[function_selector](main, information)

            if log:
                print(function_selector)
                print("=>", information, "\n")


            main[function_selector+"S"][information["NAME"]] = information
            continue

        if function_selector in EXEC_FUNCTION:
            EXEC_FUNCTION[function_selector](main, information)
            continue

    conf.get("import_path").pop()

    return main


def str_expand(main, txt, log=False):

    if main is None:
        main = get_empty_main()

    data = yaml.load(txt)

    EXPAND_FONCTION = get_expand_function()
    EXEC_FUNCTION = get_exec_function()

    if data is None:
        return main

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        if function_selector in EXPAND_FONCTION:
            information = EXPAND_FONCTION[function_selector](main, information)

            if log:
                print(function_selector)
                print("=>", information, "\n")

            main[function_selector+"S"][information["NAME"]] = information
            continue

        if function_selector in EXEC_FUNCTION:
            EXEC_FUNCTION[function_selector](main, information)
            continue

    return main


def link_expand(main, data, log=False):

    if isinstance(data, dict):
        d = collections.OrderedDict(data)

        if "ONE2ONE" not in d:
            d["ONE2ONE"] = True
        elif not isinstance(d["ONE2ONE"], bool):
            print(d["ONE2ONE"], "is not a boolean")

        if "ONE2MANY" not in d:
            d["ONE2MANY"] = False
        elif not isinstance(d["ONE2MANY"], bool):
            print(d["ONE2MANY"], "is not a boolean")

        if "MANY2ONE" not in d:
            d["MANY2ONE"] = False
        elif not isinstance(d["MANY2ONE"], bool):
            print(d["MANY2ONE"], "is not a boolean")

        if "MANY2MANY" not in d:
            d["MANY2MANY"] = False
        elif not isinstance(d["MANY2MANY"], bool):
            print(d["MANY2MANY"], "is not a boolean")

        return d
    else:
        print("error this type of link is not manage")

    return "ERROR"
