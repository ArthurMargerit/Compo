#!/usr/bin/env python
from model_expand_parent import struct_parent_expand
from model_expand_data import data_expand, data_check
from model_expand_function import function_expand
from model_check import is_valid_name
from tools.Log import ERR,WARN

def struct_check(data):
    if "NAME" not in data:
        ERR("struct sans nom")

    is_valid_name(data["NAME"])

    if "DATA" not in data:
        WARN("struct sans DATA")
    else:
        if not isinstance(data["DATA"], list):
            ERR("DATA is not a list")

        data_checks(data["DATA"])


def struct_expand(context, main, data, log=False):
    if isinstance(data, dict):
        if "PARENT" in data:
            data["PARENT"] = struct_parent_expand(main, data["PARENT"])

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

        struct_check(data)
        return data

    return None
