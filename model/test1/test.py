from yaml import load, dump
from yaml import Loader, Dumper

def type_expand(data):

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


def declaration_expand(d):

    if isinstance(d, dict):
        return d

    elif isinstance(d, str):
        words = d.split(" ")
        d = {"NAME": words[-1],
             "TYPE": get_type_or_struct(words[0])}

        return d


def struct_expand(data):
    if isinstance(data, dict):
        data_parser = []

        for d in data["DATA"]:
            data_parser.append(declaration_expand(d))

        data["DATA"] = data_parser
        return data


def nop_expand(data):
    pass


def interface_expand(data):

    var_parser = []

    if "VAR" in data:
        for d in data["VAR"]:
            var_parser.append(declaration_expand(d))

        data["VAR"] = var_parser


    if "FUNCTION" in data:
        func_parser = []
        for d in data["FUNCTION"]:
            func_parser.append(function_expand(d))

        data["FUNCTION"] = func_parser

    return data


def signature_parsing(d):

    if isinstance(d, dict):
        return d
    elif isinstance(d, str):
        if not ( d[0]=="(" and d[-1]==")" ):
            print("error pas de (..) pour la signature ", d,d[-1],d[0])
            return
        element_dico = []
        elements = d[1:-1].split(",")
        for element in elements:
            element_dico.append(type_expand(element))

    return d



def function_expand(d):
    if isinstance(d, dict):
        return d

    elif isinstance(d, str):
        words = d.split(" ")
        a = {"NAME": words[1],
             "RETURN": get_type_or_struct(words[0]),
             "SIGNATURE": signature_parsing(" ".join(words[2:]))}

        return a

def get_type_or_struct(key):

    if key in MAIN["TYPES"] and key in MAIN["STRUCTS"]:
        print("WARNING: TYPES and struct DEFINITION for " ,key)

    if key in MAIN["TYPES"]:
        return MAIN["TYPES"][key]

    if key in MAIN["STRUCTS"]:
        return MAIN["STRUCTS"][key]

    print("error")


def composant_expand(data):
    if isinstance(data, dict):

        var_parser = []
        for d in data["VAR"]:
            var_parser.append(declaration_expand(d))
        data["VAR"] = var_parser

        provide_parser = []
        for d in data["PROVIDE"]:
            provide_parser.append(declaration_interface_expand(d))
        data["PROVIDE"] = provide_parser

        require_parser = []
        for d in data["REQUIRE"]:
            require_parser.append(declaration_interface_expand(d))
        data["REQUIRE"] = require_parser

        return data

def declaration_interface_expand(data):
    if isinstance(data,dict):
        return data;
    elif isinstance(data,str):
        words = data.split(" ")
        d = {"NAME":words[1],
             "INTERFACE":get_interface(words[0])}
        return d

def get_interface(key):
    if key in MAIN["INTERFACES"]:
        return MAIN["INTERFACES"][key]

    print("ERROR aucune interface avec le nom",">"+key+"<")

def get_composant(key):
    if key in MAIN["COMPOSANTS"]:
        return MAIN["COMPOSANTS"][key]

    print("ERROR aucun COMPOSANT avec le nom",">"+key+"<")


def type_parsing():
    print("type")


def struct_parsing():
    print("struct")


def nop_parsing():
    pass


def deploiement_expand(data):

    if isinstance(data, dict):

        instance_data = []
        for d in data["INSTANCE"]:
            instance_data.append(declaration_composant_expand(d))
        data["INSTANCE_DATA"] = instance_data

        link_data = []
        for d in data["LINK"]:
            link_data.append(declaration_link_expand(d))
        data["INSTANCE_DATA"] = instance_data

        return data


def declaration_composant_expand(data):

    if isinstance(data, dict):
        return data
    elif isinstance(data, str):
        words = data.split(" ")
        d = {"NAME": words[1],
             "COMPOSANT": get_composant(words[0])}



def declaration_link_expand(data):
    words = data.split(" ")
    d = {"FROM": words[0],
         "TO": words[2],
         "kIND": words[1]
    }
    return d


MAIN = {
    "TYPES": {},
    "STRUCTS": {},
    "INTERFACES": {},
    "COMPOSANTS": {},
    "DEPLOIMENTS": {}
}

EXPAND_FONCTION = {
    "TYPE": type_expand,
    "STRUCT": struct_expand,
    "INTERFACE": interface_expand,
    "COMPOSANT": composant_expand,
    "DEPLOIMENT": deploiement_expand
}

PARSING_FONCTION = {
    "TYPE": type_parsing,
    "STRUCT": struct_parsing,
    "INTERFACE": nop_parsing,
    "COMPOSANT": nop_parsing,
    "DEPLOIEMENT": nop_parsing
    }

with open("test.yaml") as file:
    data = load(file, Loader=Loader)

for a in data:
    function_selector = list(a)[0]
    information = a[function_selector]

    information = EXPAND_FONCTION[function_selector](information)


    print(function_selector)
    print("=>", information, "\n")


    MAIN[function_selector+"S"][information["NAME"]] = information
    #PARSING_FONCTION[function_selector]()

print("="*20)
from pprint import pprint
pprint(MAIN)

print(dump(MAIN))
