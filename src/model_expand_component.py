
import collections
from tools.Uni import Uni

from model_expand_parent import component_parent_expand

from model_expand_connector import connector_instance_expand

from model_expand_function import function_expand
from model_expand_data import data_expand

from model_expand_interface import provide_expand
from model_expand_interface import require_expand, require_list_expand


def sub_component_expand(main, d, log=False):

    if isinstance(d, dict):
        return d

    elif isinstance(d, list):
        list_sub_component_expand = []

        for one_sub_component in d:
            if isinstance(one_sub_component, list):
                print("Tree function are not support")
                return None

            list_sub_component_expand.append(sub_component_expand(main, one_sub_component, log))

        return list_sub_component_expand

    elif isinstance(d, str):
        a = declaration_component_expand(main, d, log)
        return a
    else:
        return None


def component_expand(context, main, data, log=False):

    if isinstance(data, dict):
        if "PARENT" in data:
            # TODO check diamond
            data["PARENT"] = component_parent_expand(main, data, log)
        # Data
        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        # Function
        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data["FUNCTION"], log)

        # Sub Component
        if "COMPONENT_INSTANCE" in data:
            data["COMPONENT_INSTANCE"] = component_instances_expand(main, data, log)

        # Sub Component
        if "CONNECTOR_INSTANCE" in data:
            data["CONNECTOR_INSTANCE"] = connector_instances_expand(main, data, log)

        # provide
        if "PROVIDE" in data:
            data["PROVIDE"] = provide_expand(main, data, log)

        # REQUIRE
        if "REQUIRE" in data:
            data["REQUIRE"] = require_expand(main, data, log)

        # REQUIRE
        if "REQUIRE_LIST" in data:
            data["REQUIRE_LIST"] = require_list_expand(main, data, log)

        # Sub Component
        if "CONNECTION" in data:
            data["CONNECTION"] = component_connections_expand(main, data, log)

        return data


def component_instances_expand(main, data, log=False):
    instance_data = []
    u = Uni()
    if "COMPONENT_INSTANCE" in data:
        for d in data["COMPONENT_INSTANCE"]:
            p = component_instance_expand(main, d, log)

            if not u.check(p["NAME"]):
                print(colored("Error:", "red"),
                      "INSTANCE en double",
                      '"'+colored(p["NAME"], "yellow")+'"',
                      "dans le DEPLOYMENT",
                      '"'+colored(data["NAME"], "yellow")+'"')

            instance_data.append(p)

    return instance_data

