import collections
from model_get import get_interface
from model_gen import interface_gen
from model_expand_option import options_expand
from model_expand_data import data_expand
from model_expand_function import function_expand
from model_expand_parent import interface_parent_expand


def declaration_interface_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, list):
        return None

    elif isinstance(data, str):
        words = data.split(" ")
        d = collections.OrderedDict()
        d["NAME"] = words[1]
        d["INTERFACE"] = get_interface(main, words[0], log=True)
        return d


def provide_expand(main, data, log=False):
    provide_parser = []

    for d in data["PROVIDE"]:
        i_exp = declaration_interface_expand(main, d, log)
        provide_parser.append(i_exp)

    return provide_parser


def require_expand(main, data, log=False):
    require_parser = []

    for d in data["REQUIRE"]:
        i_exp = declaration_interface_expand(main, d, log)
        require_parser.append(i_exp)

    return require_parser


def require_list_expand(main, data, log=False):
    require_parser = []

    for d in data["REQUIRE_LIST"]:
        i_exp = declaration_interface_expand(main, d, log)
        require_parser.append(i_exp)

    return require_parser


def interface_expand(context, main, data, log=False):

    if "PARENT" in data:
        data["PARENT"] = interface_parent_expand(main, data["PARENT"], log)

    if "DATA" in data:
        data["DATA"] = data_expand(main, data, log)

    if "FUNCTION" in data:
        data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

    if "GEN" in data:
        data = interface_gen(main, data, data["GEN"], log)

    if "OPTIONS" not in data:
        data["OPTIONS"] = {}
    data["OPTIONS"] = options_expand("INTERFACE", data["OPTIONS"])

    return data
