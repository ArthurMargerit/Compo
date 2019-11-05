
from model_expand_parent import struct_parent_expand
from model_expand_data import data_expand, data_check
from model_expand_function import function_expand


def check_struct(data):
    if "NAME" not in data:
        print("struct sans nom")

    if "DATA" not in data:
        print("struct sans DATA")

    else:
        if not isinstance(data["DATA"], list):
            print("DATA is not a list")
        else:
            for d in data["DATA"]:
                data_check(d)


def struct_expand(context, main, data, log=False):
    if isinstance(data, dict):
        if "PARENT" in data:
            data["PARENT"] = struct_parent_expand(main, data["PARENT"])

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

        check_struct(data)
        return data

    return None
