import collections
from model_expand_parent import error_parent_expand
from model_get import get_bus, get_event
from model_expand_parent import event_parent_expand
from model_expand_data import data_expand, data_check
from model_expand_function import function_expand
from tools.Log import ERR
from model_check import is_valid_name


def check_event(data):
    pass

def event_expand(context, main, data, log=False):
    if isinstance(data, dict):

        if "PARENT" in data:
            data["PARENT"] = event_parent_expand(main, data["PARENT"])

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

        check_event(data)
        return data

    return None


def subbus_declaration_expand(main, data, log=False):
    if isinstance(data, dict):
        return data

    elif isinstance(data, list):
        ret = []
        for d in data:
            ret.append(subbus_declaration_expand(main, d, log))
        return ret

    elif isinstance(data, str):
        words = data.split(" ")
        d = collections.OrderedDict()
        d["BUS"] = get_bus(main, words[0], log=True)
        return d




def bus_expand(context, main, data, log=False):
    if isinstance(data, dict):

        if "PARENT" in data:
            data["PARENT"] = bus_parent_expand(main, data["PARENT"])

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

        if "EVENTS" in data:
            data["EVENTS"] = event_declaration_expand(main, data["EVENTS"], log)

        if "SUB_BUS" in data:
            data["SUB_BUS"] = subbus_declaration_expand(main, data["SUB_BUS"], log)

        check_event(data)
        return data

    return None


def event_declaration_expand(main, data, log=False):
    if isinstance(data, dict):
        return data

    elif isinstance(data, list):
        ret = []
        for d in data:
            ret.append(event_declaration_expand(main, d, log))
        return ret

    elif isinstance(data, str):
        words = data.split(" ")
        d = collections.OrderedDict()
        d["EVENT"] = get_event(main, words[0], log=True)
        return d



def declaration_bus_expand(main, data, log=False):

    if isinstance(data, dict):
        return data

    elif isinstance(data, list):
        return None

    elif isinstance(data, str):
        words = data.split(" ")
        d = collections.OrderedDict()
        d["NAME"] = words[1]
        d["BUS"] = get_bus(main, words[0], log=True)
        return d


def receiver_expand(main, data, log=False):
    receiver_parser = []

    for d in data["RECEIVER"]:
        i_exp = declaration_bus_expand(main, d, log)
        receiver_parser.append(i_exp)

    return receiver_parser


def emitter_expand(main, data, log=False):
    emitter_parser = []

    for d in data["EMITTER"]:
        i_exp = declaration_bus_expand(main, d, log)
        emitter_parser.append(i_exp)

    return emitter_parser
