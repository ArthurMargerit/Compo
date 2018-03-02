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

def get_expand_function():

    EXPAND_FONCTION = {
        "IMPORT": import_expand,
        "TYPE": type_expand,
        "STRUCT": struct_expand,
        "INTERFACE": interface_expand,
        "COMPOSANT": composant_expand,
        "DEPLOIMENT": deploiement_expand}

    return EXPAND_FONCTION

def get_exec_function():

    EXEC_FUNCTION = {
        "GET": get_exec,
        "SET": set_exec,
        "RENAME": rename_exec,
        "DEL": del_exec,
        "CP": cp_exec
    }

    return EXEC_FUNCTION


def get_exec(main, data, log=False):
    if isinstance(data,str):
        all_key = data.split(" ")
        solve = main
        for key in all_key:
            if key in solve:
                solve = solve[key]
            else:
                print("GET:", str(key), "not in", str(solve))
                return main

        print(solve)

        return main
    else:
        print("data is not support")


def nop_exec(main, data, log=False):
    print("This exec is not ready.")
    pass


def del_exec(main, data, log=False):
    if isinstance(data, str):
        all_key = data.split(" ")
        solve = main
        value = all_key[-1]

        for key in all_key:

            if isinstance(solve, list):
                key = int(key)

            if key in solve:
                if key == all_key[-1]:
                    del solve[key]
                else:
                    solve = solve[key]

            else:
                print("DELETE:", str(key), "not in", str(solve))
                return main

    pass


def set_exec(main, data, log=False):
    if isinstance(data,str):
        all_key = data.split(" ")
        solve = main
        value = all_key[-1]

        for key in all_key[:-1]:

            if key in solve:
                if key == all_key[-2]:
                    solve[key] = value
                else:
                    solve = solve[key]

            else:
                print("SET:", str(solve), "not in", str(key))
                return main

        return main
    else:
        print("data is not support")


def rename_exec(main, data, log=False):
    if isinstance(data,str):
        all_key = data.split(" ")
        solve = main
        value = all_key[-1]

        for key in all_key[:-1]:

            if key in solve:
                if key == all_key[-2]:
                    solve[value] = solve[key]
                    del solve[key]
                else:
                    solve = solve[key]

            else:
                print("RENAME:", str(key), "not in %s", str(solve))
                return main

        return main
    else:
        print("data is not support")

def cp_exec(main, data, log=False):
    if isinstance(data,str):
        all_key = data.split(" ")
        solve = main
        value = all_key[-1]

        for key in all_key[:-1]:

            if key in solve:
                if key == all_key[-2]:
                    solve[value] = solve[key]
                else:
                    solve = solve[key]

            else:
                print("CP:", str(key), "not in", str(solve))
                return main

        return main
    else:
        print("data is not support")


def use_type_in_struct(type, struct):
    for d in strut["DATA"]:
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

def use_type_in_interface(type,interface):

    if "DATA" in interface:
        for d in interface["DATA"]:
            if use_type_in_TYPE(type,d["TYPE"]):
                return True

    if "FUNCTION" in interface:
        for d in interface["FUNCTION"]:
            if use_type_in_TYPE(type,interface["RETURN"]):
                return True

            for param in d["SIGNATURE"]:
                if use_type_in_TYPE(type,param["TYPE"]):
                    return True

def get_interfaces_with_type(type, interfaces):

    use_by_interface = []

    for interface in interfaces:
        if use_type_in_interface(type, interface):
            use_by_interface.append(struct)

    return use_by_interface


def use_type_by_composant(type, composant):

    if "DATA" in composant:
        for d in composant["DATA"]:
            if use_type_in_TYPE(type, d):
                return True
    if "PROVIDE" in composant:
        for d in composant["PROVIDE"]:
            if use_type_in_interface(type, d):
                return True

    if "REQUIRE" in composant:
        for d in composant["REQUIRE"]:
            if use_type_in_interface(type, d):
                return True

    return False


def get_composant_with_type(type, composants):

    ## STRUCT CHECK
    use_by_composant = []

    for composant in composants :
        if use_type_in_composant(type,composant):
            use_by_composant.append(composant)

    return use_by_composant


def use_type_in_deploment(type, deploiement):

    if "INSTANCE" in deploiement:
        for d in deploiement["INSTANCE"]:
            if use_type_by_composant(type ,deploiement):
                return True

    return False

def get_deploiment_with_type(type, deploiments):
    use_by_deploiment = []

    for deploiment in deploiments :
        if use_type_in_deploment(type, deploiment):
            use_by_deploiment.append(deploiment)

    return use_by_deploiment


def type_find(main,name):
    type = main["TYPES"][name]

    ## STRUCT CHECK
    use_by_structs = []
    for strut in main["STRUCTS"]:
        append = False
        for d in strut["DATA"]:
            if d["TYPE"] == type:
                append = True
        if append:
            use_by_structs.append(struct)

    ## INTERFACE
    use_by_interface=[]
    for interface in main["INTERFACES"]:
        append = False
        for d in interface["DATA"]:
            if d["TYPE"] == type:
                append = True
            elif "DATA" in d["TYPE"]:



        for d in interface["FUNCTION"]:
            if d["RETURN"] == type:
                append = true

            for si in d["SIGNATURE"]:
                if si["TYPE"] == type:
                    append = true

        if append:
            use_by_structs.append(struct)


    return {"USE_BY":main["TYPES"],
            "RESULT":main["TYPES"][data]}


def struct_find(main,data):
    pass

def interface_find(main,data):
    pass

def composant_find(main,data):
    pass

def deploiment_find(main,data):
    pass




def file_expand(main, file_path, log=False):

    if main is not None:
        main = get_empty_main()

    with open(file_path) as file:
        data = load(file, Loader=Loader)

    EXPAND_FONCTION = get_expand_function()
    EXEC_FUNCTION = get_exec_function()

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


# def str_expand(main, str, log=False):

#     if main is not None:
#         main = get_empty_main()

#     data = load(str, Loader=Loader)
#     EXPAND_FONCTION = get_expand_function()

#     for a in data:
#         function_selector = list(a)[0]
#         information = a[function_selector]

#         information = EXPAND_FONCTION[function_selector](main, information)

#         if log:
#             print(function_selector)
#             print("=>", information, "\n")

#         main[function_selector+"S"][information["NAME"]] = information

#     return main
