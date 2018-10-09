import collections
from termcolor import colored

def get_type_or_struct(main, key):
    if key in main["TYPES"] and key in main["STRUCTS"]:
        print("WARNING: TYPES and struct DEFINITION for ", key)

    if key in main["TYPES"]:
        return main["TYPES"][key]

    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]

    print(colored("ERROR", "red"),
          "aucun STRUCT ou TYPE  avec le nom >",
          colored(key, "red"),
          "<")


def get_interface(main, key):
    if key in main["INTERFACES"]:
        return main["INTERFACES"][key]

    print(colored("ERROR", 'red'),
          "aucun INTERFACES avec le nom >",
          colored("key", 'green'),
          "<")


def get_component(main, key):
    import pprint
    
    if key in main["COMPONENTS"]:
        return main["COMPONENTS"][key]

    print(colored("ERROR", "red"),
          " aucun COMPONENT avec le nom >",
          colored(key, "green"),
          "<")


def get_link(main, key):
    key = key.replace("-(", "")
    key = key.replace(")->", "")

    if key in main["LINKS"]:
        return main["LINKS"][key]

    print(colored("ERROR", "red"),
          "aucun LINK avec le nom >",
          colored(key, "red"),
          "<")


def get_stuct(main, key):
    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]

    print(colored("ERROR", "red"),
          "aucune STRUCT avec le nom >",
          colored(key, "red"),
          "<")


def get_deployment(main, key):
    if key in main["DEPLOYMENTS"]:
        return main["DEPLOYMENTS"][key]

    print(colored("ERROR", "red"),
          "aucune DEPLOYMENT avec le nom >",
          colored(key, "red"),
          "<")


def get_list_provide_of_composant(main, composant_name):
    pass


def get_list_require_of_composant(main, composant_name):
    pass


def get_empty_main():
    main = collections.OrderedDict()
    main["TYPES"] = collections.OrderedDict()
    main["STRUCTS"] = collections.OrderedDict()
    main["INTERFACES"] = collections.OrderedDict()
    main["LINKS"] = collections.OrderedDict()
    main["LINKERS"] = collections.OrderedDict()
    main["COMPONENTS"] = collections.OrderedDict()
    main["DEPLOYMENTS"] = collections.OrderedDict()
    main["IMPORTS"] = collections.OrderedDict()

    return main
