# !/usr/bin/env python3
import model_get
from tools.Log import ERR


def is_link_instance(main, compo, key):
    return 'LINK_INSTANCE' in compo and key in compo["LINK_INSTANCE"]


def is_struct(name, main):
    if is_struct_priv(name, main["STRUCTS"]):
        return True
    else:
        for i_sf in main["IMPORTS"].values():
            if is_struct(name, i_sf["MAIN"]):
                return True
        return False


def is_struct_priv(name, structs):
    return name in structs


def is_a_pointer_type(p_type):

    if "POINTER" in p_type:
        return True

    # if "*" in p_type["DEFINITION"]:
    #     return True
    return False


def have_function(elem, name_func):
    l_comp = elem
    while True:
        if "FUNCTION" in l_comp:
            for i_f in l_comp["FUNCTION"]:
                if name_func == i_f["NAME"]:
                    return True

        if "PARENT" in l_comp:
            l_comp = l_comp["PARENT"]
        else:
            break

    return False


def have_children(p_list_elem, p_name):
    return len(model_get.get_children(p_list_elem, p_name)) != 0


def is_dbus_export(e):
    if "DBUS" not in e:
        ERR("The !y(", e["NAME"], ") is not dbus exportable.")
        return "#ERROR !!" + "The " + e["NAME"] + " is not dbus exportable !!"
    return ""
