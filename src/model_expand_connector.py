import collections
from model_expand_data import data_expand
from model_get import get_connector
from model_expand_function import function_expand
from model_expand_interface import require_expand, provide_expand
from model_gen import connector_gen
from model_expand_data import parse_arg


def connector_instance_expand(main, c, data, log=False):

    d = collections.OrderedDict()

    if "WITH" in data:
        tmp_data = data.split("WITH")
        d["WITH"] = parse_arg(tmp_data[1])
        data = tmp_data[0]

    words = data.split(" ")
    d["CONNECTOR"] = get_connector(main, words[0])
    d["NAME"] = words[1]

    return d


def connector_instances_expand(main, data, log=False):
    connector_data = []
    if "CONNECTOR_INSTANCE" in data:
        for d in data["CONNECTOR_INSTANCE"]:
            ci_exp = connector_instance_expand(main, data, d, log)
            connector_data.append(ci_exp)

    return connector_data


def connector_expand(context, main, data, log=False):

    if isinstance(data, dict):
        if "GEN" in data:
            data= connector_gen(main, data, data["GEN"], log)

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data, log)

        # PROVIDE
        if "PROVIDE" in data:
            data["PROVIDE"] = provide_expand(main, data, log)

        # REQUIRE
        if "REQUIRE" in data:
            data["REQUIRE"] = require_expand(main, data, log)

        return data

    return None
