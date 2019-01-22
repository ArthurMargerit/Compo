# !/bin/env python

import collections
from model_dump import yaml
from termcolor import colored
from Config import Configuration_manager
from model_exec import get_exec_function
from model_get import get_type_or_struct, get_interface, get_component, get_stuct, get_empty_main, get_link, get_linker, get_linker_instance, get_link_or_linker_instance
import os.path
from tools.Uni import Uni
from model_test import is_struct
from model_utils import print_me
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
        elements = d[1:-1].split(",")
        for element in elements:
            element_dico.append(declaration_expand(main, element, log))

        return element_dico


def function_expand(main, d, log=False):

    if isinstance(d, dict):
        print("lapin dict")
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
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

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
    else:
        print("ERROR: link not to the  good format", data)

    type, instance_Type = get_link_or_linker_instance(main, c, center, True)

    d[type] = instance_Type
    print(c)
    if from_cut:
        d["FROM"] = declaration_interface_component_expand(main,
                                                           c,
                                                           from_cut,
                                                           log,
                                                           "REQUIRE")

    if to_cut:
        d["TO"] = declaration_interface_component_expand(main,
                                                         c,
                                                         to_cut,
                                                         log,
                                                         "PROVIDE")
    
    # 3 elements
    #    LINKER INSTANCE
    #    LINK INSTANCE
    #    LINK UNAME TODO

    # 2 elements
    #    LINK INSTANCE > in
    #    LINKER INSTANCE > in
    #    LINK UNAME > in TODO

    #    out > LINK_INSTANCE
    #    out > LINKER_INSTANCE
    #    out > LINK UNAME TODO

    # if len(words) == 3:
    #     d["FROM"] = declaration_interface_component_expand(main,
    #                                                        c,
    #                                                        words[0],
    #                                                        log,
    #                                                        "REQUIRE")

    #     if is_linker_instance(words[1], c):
    #         d["LINKER"] = get_linker_instance(main, c, words[1])
    #     elif is_link_instance(words[1], c):
    #         d["LINK"] = get_link_instance(main, c,  words[1])
    #     else:
    #         #TODO UNMAME
    #         #d["TYPE"] = get_link(main, words[1])
    #         print("ERROR in Link")

    #     d["TO"] = declaration_interface_component_expand(main,
    #                                                      c,
    #                                                      words[2],
    #                                                      log,
    #                                                      "PROVIDE")


    # elif ")->" in words[0]:
    #     linker_name = words[0].replace("(", "").replace(")->", "")


    #     #d[""] = get_linker_instance(main, c, linker_name)
    #     if is_linker_instance(words[1], c):
    #         d["LINKER"] = get_linker_instance(main, c, words[1])
    #     elif is_link_instance(words[1], c):
    #         d["LINK"] = get_link_instance(main, c,  words[1])
    #     else:
    #         # TODO UNAME
    #         print("ERROR in Link")


    #     d["TO"] = declaration_interface_component_expand(main,
    #                                                      c,
    #                                                      words[1],
    #                                                      log,
    #                                                      "PROVIDE")

    # elif "->(" in words[1]:
    #     linker_name = words[1].replace(")", "").replace("->(", "")

    #     #d[""] = get_linker_instance(main, c, linker_name)
    #     if is_linker_instance(words[1], c):
    #         d["LINKER"] = get_linker_instance(main, c, words[1])
    #     elif is_link_instance(words[1], c):
    #         d["LINK"] = get_link_instance(main, c,  words[1])
    #     else:
    #         # TODO UNAME
    #         print("ERROR in Link")

    #     d["FROM"] = declaration_interface_component_expand(main,
    #                                                        c,
    #                                                        words[0],
    #                                                        log,
    #                                                        "REQUIRE")
    # else:
    #     print("ERROR in link")

    return d



def connections_expand(main, data, log=False):

    connection_data = []
    for d in data["CONNECTION"]:
        print(d)
        connection_data.append(connection_expand(main, data, d, log))

    return connection_data


def deployment_expand(main, data, log=False):

    if isinstance(data, dict):

        if "PARENT" in data:
            data["PARENT"] = deployment_parent_expand(main, data, log)

        if "INSTANCE" in data:
            data["INSTANCE"] = instance_expand(main, data, log)

        if "LINK_INSTANCE" in data:
            data["LINK_INSTANCE"] = link_instances_expand(main, data, log)

        if "LINKER_INSTANCE" in data:
            data["LINKER_INSTANCE"] = linker_instances_expand(main, data, log)

        if "CONNECTION" in data:
            data["CONNECTION"] = connections_expand(main, data, log)

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data, log)

        return data


def linker_instances_expand(main, data, log=False):
    if isinstance(data["LINKER_INSTANCE"], list):
        list_linker_instance = []
        u = Uni()
        for d in data["LINKER_INSTANCE"]:

            p = linker_instance_expand(main, d, log)

            if not u.check(p["NAME"]):
                print(colored("ERROR:", "red"),
                      "INSTANCE en double",
                      '"'+colored(p["NAME"], "yellow")+'"',
                      "dans le DEPLOYMENT",
                      '"'+colored(data["NAME"], "yellow")+'"')

            list_linker_instance.append(p)

        return list_linker_instance


def linker_instance_expand(main, data, log=False):

    if isinstance(data, str):
        ret = {}
        if "WITH" in data:
            str_with = data.split("WITH")
            ret["WITH"] = parse_arg(str_with[1])
            data = str_with[0]

        s = data.split(" ")
        ret["NAME"] = s[1]
        ret["TYPE"] = get_linker(main, s[0])
        return ret


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


def linker_expand(main, data, log=False):

    if isinstance(data, dict):

        if "LINK" not in data:
            print("error: no link in linker", data["NAME"])
            return
        else:
            data["LINK"] = get_link(main, data["LINK"])

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        return data


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

        main_import = {}
        main_inport = file_expand(main_import, valid, log)

        return {"NAME": file,
                "MAIN": main_inport}


def get_expand_function():

    EXPAND_FONCTION = {
        "IMPORT": import_expand,
        "TYPE": type_expand,
        "LINK": link_expand,
        "LINKER": linker_expand,
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

        if "DATA" in d:
            d["DATA"] = data_expand(main, data, log)

        if "DATA" in d:
            pass

        return d
    else:
        print("error this type of link is not manage")

    return "ERROR"
