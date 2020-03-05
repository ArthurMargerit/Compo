# !/usr/bin/env python3
import os
from os import listdir
from os.path import isfile
from yaml import load, dump, safe_dump
from yaml import SafeLoader, Dumper
from termcolor import colored
import model_expand
import model_dump
import model_get


def is_link_instance(main, compo, key):
    return 'LINK_INSTANCE' in compo and key in compo["LINK_INSTANCE"]


def is_struct(name, structs):
    return name in structs


def is_a_pointer_type(p_type):

    if "POINTER" in p_type:
        return True

    # if "*" in p_type["DEFINITION"]:
    #     return True
    return False


def have_function(elem, name_func):
    l_comp=elem
    while True:
        if "FUNCTION" in l_comp:
            for  f in l_comp["FUNCTION"]:
                if name_func == f["NAME"]:
                    return True

        if "PARENT" in l_comp:
            l_comp = l_comp["PARENT"]
        else:
            break

    return False


def have_children(p_list_elem, p_name):
    return len(model_get.get_children(p_list_elem, p_name)) != 0
