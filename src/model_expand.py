# !/bin/env python
from model_get import get_type_or_struct, get_interface, get_composant, get_stuct, get_empty_main
import collections
from model_dump import yaml
from termcolor import colored

class Uni:
    def __init__(self):
        self.Uni = {}

    def check(self, s):
        if s in self.Uni:
            return False
        else:
            self.Uni[s] = 1
            return True

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
        print("error")
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


def struct_expand(main, data, log=False):

    if isinstance(data, dict):
        data_parser = []
        u = Uni()
        if "DATA" in data:
            for d in data["DATA"]:
                p = declaration_expand(main, d, log)
                if not u.check(p["NAME"]):
                    print(colored("ERROR:", "red"),
                          "nom en double",
                          '"'+colored(p["NAME"], "yellow")+'"',
                          "dans la struct",
                          '"'+colored(data["NAME"], "yellow")+'"')
                data_parser.append(p)
        data["DATA"] = data_parser

        check_struct(data)
        return data


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

    var_parser = []
    if "VAR" in data:
        u = Uni()
        for d in data["VAR"]:
            p = declaration_expand(main, d, log)
            if not u.check(p["NAME"]):
                print(colored("ERROR:", "red"),
                      "VAR en double",
                      '"'+colored(p["NAME"], "yellow")+'"',
                      "dans la struct",
                      '"'+colored(data["NAME"], "yellow")+'"')

            var_parser.append(p)

        data["VAR"] = var_parser

    func_parser = []
    if "FUNCTION" in data:
        u = Uni()
        for d in data["FUNCTION"]:
            p = function_expand(main, d, log)
            if not u.check(p["NAME"]):
                print(colored("ERROR:", "red"),
                      "FUNCTION en double",
                      '"'+colored(p["NAME"], "yellow")+'"',
                      "dans la struct",
                      '"'+colored(data["NAME"], "yellow")+'"')

            func_parser.append(p)

    data["FUNCTION"] = func_parser

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

    elif isinstance(d, str):
        words = d.split(" ")
        a = {"NAME": words[1],
             "RETURN": get_type_or_struct(main, words[0]),
             "SIGNATURE": signature_expand(main,
                                           " ".join(words[2:]),
                                           log)}

        return a


def composant_expand(main, data, log=False):
    if isinstance(data, dict):

        # VAR
        var_parser = []
        if "DATA" in data:
            for d in data["DATA"]:
                var_parser.append(declaration_expand(main, d, log))
        data["DATA"] = var_parser

        # function
        var_parser = []
        if "FUNCTION" in data:
            for d in data["FUNCTION"]:
                var_parser.append(function_expand(main, d, log))
        data["FUNCTION"] = var_parser

        # PROVIDE
        provide_parser = []
        if "PROVIDE" in data:
            for d in data["PROVIDE"]:
                provide_parser.append(declaration_interface_expand(main,
                                                                   d,
                                                                   log))
        data["PROVIDE"] = provide_parser

        # REQUIRE
        require_parser = []
        if "REQUIRE" in data:
            for d in data["REQUIRE"]:
                require_parser.append(declaration_interface_expand(main,
                                                                   d,
                                                                   log))
        data["REQUIRE"] = require_parser

        return data


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


def deploiement_expand(main, data, log=False):

    if isinstance(data, dict):

        instance_data = []
        if "INSTANCE" in data:
            u = Uni()
            for d in data["INSTANCE"]:
                p = declaration_composant_expand(main, d, log)
                if not u.check(p["NAME"]):
                    print(colored("ERROR:", "red"),
                          "INSTANCE en double",
                          '"'+colored(p["NAME"], "yellow")+'"',
                          "dans le DEPLOIMENT",
                          '"'+colored(data["NAME"], "yellow")+'"')

                instance_data.append(p)
        data["INSTANCE"] = instance_data

        if "LINK" in data:
            link_data = []
            for d in data["LINK"]:
                link_data.append(declaration_link_expand(main,data, d, log))
            data["LINK"] = link_data

        return data


def declaration_composant_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, str):
        words = data.split(" ")
        d = collections.OrderedDict()
        d["NAME"] = words[1]
        d["COMPOSANT"] = get_composant(main, words[0])
        return d


def declaration_interface_composant_expand(main, c, data, log, need):

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
              "n'est pas definie dans le DEPLOIEMENT",
              colored(c["NAME"], "yellow"))

    # TODO clean
    interface = None
    for i in i["COMPOSANT"][need]:
        if i["NAME"] == w[1]:
            interface = i

    if interface is None:
        print(colored("Error:", "red"),
              "l'INTERFACE",
              colored(w[1], "yellow"),
              "n'est pas definie dans le composant",
              colored(instance["COMPOSANT"]["NAME"]+" "+w[0], "yellow"))

    d = collections.OrderedDict()
    d["INSTANCE"] = instance
    d["INTERFACE"] = interface

    return d


def declaration_link_expand(main, c, data, log=False):
    words = data.split(" ")
    d = collections.OrderedDict()
    d["FROM"] = declaration_interface_composant_expand(main,
                                                       c,
                                                       words[0],
                                                       log,
                                                       "REQUIRE")
    d["TYPE"] = words[1]
    d["TO"] = declaration_interface_composant_expand(main,
                                                     c,
                                                     words[2],
                                                     log,
                                                     "PROVIDE")

    return d


def import_expand(main, data, log=False):

    if isinstance(data, dict):
        print("error syntax need to be [file1 , ... ] or file ")
        return

    if isinstance(data, list):
        for file in data:
            file_expand(main, data, log)

    if isinstance(data, str):
        file = data
        file_expand(main, file, log)
        return {"NAME": file}

def get_exapnd_function():

    EXPAND_FONCTION = {
        "IMPORT": import_expand,
        "TYPE": type_expand,
        "STRUCT": struct_expand,
        "INTERFACE": interface_expand,
        "COMPOSANT": composant_expand,
        "DEPLOIMENT": deploiement_expand}

    return EXPAND_FONCTION


def file_expand(main, file_path, log=False):

    if main is None:
        main = get_empty_main()

    with open(file_path) as file:
        data = yaml.load(file)

    EXPAND_FONCTION = get_exapnd_function()

    if data is None:
        return main

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        information = EXPAND_FONCTION[function_selector](main, information)

        if log:
            print(function_selector)
            print("=>", information, "\n")

        if information["NAME"] in main[function_selector+"S"]:
            print(colored("WARNING:", "red"),
                  " REDEFINITION de ",
                  '"'+information["NAME"]+'"',
                  "in file ",
                  file_path)

        main[function_selector+"S"][information["NAME"]] = information

    return main


def str_expand(main, str, log=False):

    if main is  None:
        main = get_empty_main()

    data = yaml.load(str)
    EXPAND_FONCTION = get_exapnd_function()

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        information = EXPAND_FONCTION[function_selector](main, information)

        if log:
            print(function_selector)
            print("=>", information, "\n")

        if information["NAME"] in main[function_selector+"S"]:
            print(colored("WARNING:","red")," REDEFINITION de\"", information["NAME"],"\"")

        main[function_selector+"S"][information["NAME"]] = information

    return main
