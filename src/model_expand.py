# !/bin/env python

from yaml import load, dump
from yaml import Loader, Dumper

from model_get import *


def type_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, str):

        words = data.split(" ")

        if len(words) < 2:
            print("wrong number of word")
            return

        a = {"NAME": words[-1],
             "DEFINITION": " ".join(words[0:-1])}

        return a

    else:
        print("error")
        return


def declaration_expand(main, d, log=False):

    if isinstance(d, dict):
        return d

    elif isinstance(d, str):
        words = d.split(" ")
        d = {"NAME": words[-1],
             "TYPE": get_type_or_struct(main, words[0])}

        return d


def struct_expand(main, data, log=False):

    if isinstance(data, dict):
        data_parser = []

        for d in data["DATA"]:
            data_parser.append(declaration_expand(main, d, log))

        data["DATA"] = data_parser
        return data


def nop_expand(main, data, log=False):
    pass


def interface_expand(main, data, log=False):

    var_parser = []

    if "VAR" in data:
        for d in data["VAR"]:
            var_parser.append(declaration_expand(main, d, log))

        data["VAR"] = var_parser

    if "FUNCTION" in data:
        func_parser = []
        for d in data["FUNCTION"]:
            func_parser.append(function_expand(main, d, log))

        data["FUNCTION"] = func_parser

    return data


def signature_expand(main, d, log=False):

    if isinstance(d, dict):
        return d
    elif isinstance(d, str):

        if not (d[0] == "(" and d[-1] == ")"):
            print("error pas de (..) pour la signature ", d, d[-1], d[0])
            return

        element_dico = []
        elements = d[1:-1].split(",")
        for element in elements:

            element_dico.append(type_expand(main, element, log))

        return d


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

        var_parser = []
        for d in data["VAR"]:
            var_parser.append(declaration_expand(main, d, log))
        data["VAR"] = var_parser

        provide_parser = []
        for d in data["PROVIDE"]:
            provide_parser.append(declaration_interface_expand(main, d, log))
        data["PROVIDE"] = provide_parser

        require_parser = []
        for d in data["REQUIRE"]:
            require_parser.append(declaration_interface_expand(main, d, log))
        data["REQUIRE"] = require_parser

        return data


def declaration_interface_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, str):
        words = data.split(" ")
        d = {"NAME": words[1],
             "INTERFACE": get_interface(main, words[0])}
        return d


def deploiement_expand(main, data, log=False):

    if isinstance(data, dict):

        if "INSTANCE" in data:
            instance_data = []
            for d in data["INSTANCE"]:
                instance_data.append(
                    declaration_composant_expand(main, d, log)
                )
            data["INSTANCE"] = instance_data

        if "LINK" in data:
            link_data = []
            for d in data["LINK"]:
                link_data.append(declaration_link_expand(main, d, log))
            data["LINK"] = link_data

        return data


def declaration_composant_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, str):
        words = data.split(" ")
        d = {"NAME": words[1],
             "COMPOSANT": get_composant(main, words[0])}
        return d

def declaration_link_expand(main, data, log=False):
    words = data.split(" ")

    d = {"FROM": words[0],
         "TO": words[2],
         "kIND": words[1]}

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
        data = load(file, Loader=Loader)

    EXPAND_FONCTION = get_exapnd_function()

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        information = EXPAND_FONCTION[function_selector](main, information)

        if log:
            print(function_selector)
            print("=>", information, "\n")

        main[function_selector+"S"][information["NAME"]] = information

    return main


def str_expand(main, str, log=False):

    if main is None:
        main = get_empty_main()

    data = load(str, Loader=Loader)
    EXPAND_FONCTION = get_exapnd_function()

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        information = EXPAND_FONCTION[function_selector](main, information)

        if log:
            print(function_selector)
            print("=>", information, "\n")

        main[function_selector+"S"][information["NAME"]] = information

    return main
