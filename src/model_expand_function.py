#!/usr/bin/env python
from model_get import get_type_or_struct
from model_expand_data import declaration_expand
from model_check import is_valid_name
from tools.Log import ERR


def signature_expand(main, d, log=False):

    if isinstance(d, dict):
        return d
    elif isinstance(d, str):

        if not (d[0] == "(" and d[-1] == ")"):
            ERR("pas de \"(\" ... \")\" in function Signature ", d, d[-1], d[0])
            return

        if d == "()":
            return []

        element_dico = []
        base = d[1:-1].replace(", ", ",").replace(" ,", ",")
        elements = base.split(",")

        for element in elements:
            element_dico.append(declaration_expand(main, element, log))

        return element_dico


def function_check(p_func):
    if "NAME" not in p_func:
        ERR("struct !y(", p_func, ") need NAME")

    is_valid_name(p_func["NAME"])
    for i_s in p_func["SIGNATURE"]:
        is_valid_name(i_s["NAME"])

    if "SIGNATURE" not in p_func:
        ERR("Struct !y(", p_func["NAME"], ") need SIGNATURE")

    if "RETURN" not in p_func:
        ERR("Struct !y(", p_func["NAME"], ") need RETURN")


def function_expand(main, d, log=False):

    if isinstance(d, dict):
        return d

    elif isinstance(d, list):
        list_function_expand = []

        for one_function in d:
            f_exp = function_expand(main, one_function, log)
            list_function_expand.append(f_exp)

        return list_function_expand

    elif isinstance(d, str):

        ret_type, func_name = [s for s in d[:d.find("(")].split(" ") if len(s)]
        signature = d[d.find("("):]

        l_func = {"NAME": func_name,
                  "RETURN": get_type_or_struct(main, ret_type),
                  "SIGNATURE": signature_expand(main,
                                                signature,
                                                log)}
        function_check(l_func)
        return l_func

    else:
        ERR("Invalid")
