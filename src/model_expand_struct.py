#!/usr/bin/env python
from model_expand_parent import struct_parent_expand
from model_expand_data import data_expand, data_checks
from model_expand_function import function_expand
from model_check import is_valid_name
from model_gen import structs_gen
from tools.Log import ERR, WARN
from model_expand_option import options_expand


def struct_check(data):
    if "NAME" not in data:
        ERR("struct !y(", data, ") sans nom")

    is_valid_name(data["NAME"])

    if "DATA" not in data:
        WARN("struct !y(", data["NAME"], ") sans DATA")
    else:
        data_checks(data["DATA"])


def struct_expand(context, main, data, log=False):
    if isinstance(data, dict):
        if "PARENT" in data:
            data["PARENT"] = struct_parent_expand(main, data["PARENT"])
        else:
            data["PARENT"] = None

        if "GEN" in data:
            structs_gen(main, data, data["GEN"], log)

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "OPTIONS" not in data:
            data["OPTIONS"] = {}
        data["OPTIONS"] = options_expand("STRUCT", data["OPTIONS"])

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

        struct_check(data)
        return data

    return None
