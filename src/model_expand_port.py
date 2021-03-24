import collections
from model_get import get_port
from tools.Log import ERR, WARN
from model_expand_option import options_expand
from model_expand_data import key_expand, data_expand
from model_expand_function import function_expand
from model_expand_parent import port_parent_expand


def declaration_port_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, list):
        return None

    elif isinstance(data, str):
        words = data.split(" ")
        d = collections.OrderedDict()
        d["NAME"] = words[1]
        d["PORT"] = get_port(main, words[0], log=True)
        return d

port_v = ["FUNCTION_IN", "FUNCTION_OUT", "EVENT_IN", "EVENT_OUT"]
def port_expand(context, main, data, log=False):

    if "PARENT" in data:
        data["PARENT"] = port_parent_expand(main, data["PARENT"], log)

    if "KIND" not in data:
        ERR('!g(', data["D_NAME"], ") No kind specified choose !r(", "),!r(".join(port_v), ")")

    if data["KIND"] not in port_v:
        ERR('!g(', data["D_NAME"],
            ") with kind specified !y(", data["KIND"],
            ") is not valid. Choose !r(",
            "), !r(".join(port_v), ")")

    if "KEY" in data and data["KEY"]:
        data["KEY"] = key_expand(main, data, log)
    else:
        data["KEY"] = None

    if "DATA" in data:
        data["DATA"] = data_expand(main, data, log)

    if "FUNCTION" in data:
        data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

    # if "GEN" in data:
    #     data = interface_gen(main, data, data["GEN"], log)

    # if "OPTIONS" not  in data:
    #     data["OPTIONS"] = {}
    # data["OPTIONS"] = options_expand("INTERFACE", data["OPTIONS"])

    return data
