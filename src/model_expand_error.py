from model_expand_parent import error_parent_expand
from model_expand_data import data_expand, data_check
from model_expand_function import function_expand

from tools.Log import ERR
from model_check import is_valid_name


def check_error(data):
    if "NAME" not in data:
        ERR(data, "without NAME")

    if not is_valid_name(data["NAME"]):
        ERR(data["NAME"], " is not a valid name ")

    if "DATA" in data:
        if not isinstance(data["DATA"], list):
            print("DATA is not a list")
        else:
            for d in data["DATA"]:
                data_check(d)


def error_expand(context, main, data, log=False):
    if isinstance(data, dict):

        if "PARENT" in data:
            data["PARENT"] = error_parent_expand(main, data["PARENT"])

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

        check_error(data)
        return data

    return None
