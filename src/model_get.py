import collections
from termcolor import colored

from model_test import is_struct, is_link_instance


def get_type_or_struct(main, key, log=True):
    if key in main["TYPES"] and key in main["STRUCTS"]:
        print(colored("red", "WARNING"), "TYPES and struct DEFINITION for ", colored(key, "yellow"))

    if key in main["TYPES"]:
        return main["TYPES"][key]

    if "<" in key:
        l_key = key.split("<",1)
        if l_key[0] in main["TYPES"]:

            dd = dict.copy(main["TYPES"][l_key[0]])
            dd["NAME"] = key
            dd["DYNAMIC"] = "DONE"

            return dd

    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_type_or_struct(l_import["MAIN"], key, log=False)
        if ret != None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucun STRUCT ou TYPE  avec le nom >",
              colored(key, "red"),
              "<")

    return None


def get_interface(main, key, log=False):
    if key in main["INTERFACES"]:
        return main["INTERFACES"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_interface(l_import["MAIN"], key, log=False)
        if ret != None:
            return ret

    if log:
        print(colored("Error", 'red'),
              "aucune INTERFACES avec le nom >",
              colored(key, 'green'),
              "<")
    return None

def get_component(main, key, log=False):

    if key in main["COMPONENTS"]:
        return main["COMPONENTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_component(l_import["MAIN"], key, log=False)
        if ret != None:
            return ret
    if log:
        print(colored("Error", "red"),
              " aucun COMPONENT avec le nom >",
              colored(key, "green"),
              "<")

    return None


def get_link(main, key, log=False):
    key = key.replace("-(", "")
    key = key.replace("(", "")
    key = key.replace(")->", "")
    key = key.replace(")", "")

    if key in main["LINKS"]:
        return main["LINKS"][key]

    for i_import in main["IMPORTS"].values():
        ret = get_link(i_import["MAIN"], key, log=False)
        if ret is not None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucun LINK avec le nom >",
              colored(key, "red"),
              "<")


def get_link_instance(main, compo, key, log=True):
    if "LINK_INSTANCE" in compo:
        for link in compo["LINK_INSTANCE"]:
            if link["NAME"] == key:
                return link

    if "PARENT" in compo and compo["PARENT"] is not None:
       inst= get_link_instance(main, compo["PARENT"], key , False)
       if inst is not  None :
           return inst

    if log:
        print(colored("Error", "red"),
              "aucune instance de LINK avec le nom >",
              colored(key, "red"),
              "< dans le deploiment",
              colored(compo["NAME"], "red"))

    return None


def get_stuct(main, key, log=False):
    if key in main["STRUCTS"]:
        return main["STRUCTS"][key]


    for l_import in main["IMPORTS"].values():
        ret = get_stuct(l_import["MAIN"], key, log=False)
        if ret != None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucune STRUCT avec le nom >",
              colored(key, "red"),
              "<")


def get_error(main, key, log=False):
    if key in main["ERRORS"]:
        return main["ERRORS"][key]


    for l_import in main["IMPORTS"].values():
        ret = get_error(l_import["MAIN"], key, log=False)
        if ret != None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucune ERROR avec le nom >",
              colored(key, "red"),
              "<")



def get_deployment(main, key, log=False):
    if key in main["DEPLOYMENTS"]:
        return main["DEPLOYMENTS"][key]

    for l_import in main["IMPORTS"].values():
        ret = get_deployment(l_import["MAIN"], key, log=False)
        if ret != None:
            return ret

    if log:
        print(colored("Error", "red"),
              "aucune DEPLOYMENT avec le nom >",
              colored(key, "red"),
              "<")


def get_instances(element_list, element_name):
    element = element_list[element_name]
    f = element["INSTANCE"]

    if "PARENT" not in element or element["PARENT"] is None:
        return f

    parent_f = get_instances(element_list, element["PARENT"]["NAME"])

    return [*f, *parent_f]



def get_functions(element_list, element_name):

    element = element_list[element_name]
    f = element["FUNCTION"]

    if "PARENT" not in element or element["PARENT"] is None:
        return f

    parent_f = get_functions(element_list, element["PARENT"]["NAME"])

    return [*f, *parent_f]


def get_datas(element_list, element_name):

    element = element_list[element_name]
    d = element["DATA"]

    if "PARENT" not in element or element["PARENT"] is None:
        return d

    parent_d = get_datas(element_list, element["PARENT"]["NAME"])

    return [*d, *parent_d]


def get_struct_use_by(main, function, data):
    unique_list = dict()

    if function == None:
        function = []

    if data == None:
        data = []

    for f in function:
        if is_struct(f["RETURN"]["NAME"], main["STRUCTS"]):
            unique_list[f["RETURN"]["NAME"]] = f["RETURN"]

        for p in f["SIGNATURE"]:
            if is_struct(p["TYPE"]["NAME"], main["STRUCTS"]):
                unique_list[p["TYPE"]["NAME"]] = p["TYPE"]

    for a in data:
        if is_struct(a["TYPE"]["NAME"], main["STRUCTS"]):
            unique_list[a["TYPE"]["NAME"]] = a["TYPE"]

    return unique_list

def get_sub_component_use_by(sub_component_list):
    unique_list = dict()

    if sub_component_list == None:
        sub_component_list = []

    for sc in sub_component_list:
        unique_list[sc["COMPONENT"]["NAME"]] = sc["COMPONENT"]

    return unique_list


def get_list_provide_of_composant(main, composant_name):
    pass


def get_list_require_of_composant(main, composant_name):
    pass


def get_children(list_element,p_elem):
    l_r = []

    for li_elem  in list_element.values():
        if( "PARENT" in li_elem and p_elem == li_elem["PARENT"]["NAME"]):
            l_r.append(li_elem["NAME"])

    return l_r


def get_parent_rec(list_element,p_elem):
    l_r = []
    li_parent=p_elem

    while "PARENT" in li_parent:
        li_parent = li_parent["PARENT"]
        l_r.append(li_parrent["NAME"])

    return l_r


def get_children_rec(list_element,p_elem):

    l_childs = get_children(list_element,p_elem)

    l_childs_of_childs = []
    for li_name_child in l_childs:
        l_p = get_children_rec(list_element, li_name_child)
        l_childs_of_childs = {*l_childs_of_childs, *l_p}

    result = {*l_childs,*l_childs_of_childs}
    return result if result != set() else []


def get_empty_main():
    main = collections.OrderedDict()
    main["TYPES"] = collections.OrderedDict()
    main["STRUCTS"] = collections.OrderedDict()
    main["ERRORS"] = collections.OrderedDict()
    main["INTERFACES"] = collections.OrderedDict()
    main["LINKS"] = collections.OrderedDict()
    main["COMPONENTS"] = collections.OrderedDict()
    main["DEPLOYMENTS"] = collections.OrderedDict()
    main["IMPORTS"] = collections.OrderedDict()

    return main
