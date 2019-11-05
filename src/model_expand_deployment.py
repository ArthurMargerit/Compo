from model_expand_parent import deployment_parent_expand

from model_expand_data import data_expand
from model_expand_function import function_expand

from model_expand_connector import connector_expand
from model_expand_component import component_expand
from model_expand_connection import connection_expand

from model_expand_link import link_expand


def deployment_expand(context, main, data, log=False):

    if isinstance(data, dict):

        if "PARENT" in data:
            data["PARENT"] = deployment_parent_expand(main, data, log)

        if "COMPONENT_INSTANCE" in data:
            data["COMPONENT_INSTANCE"] = component_instances_expand(main, data, log)

        if "LINK_INSTANCE" in data:
            data["LINK_INSTANCE"] = link_instances_expand(main, data, log)

        if "CONNECTOR_INSTANCE" in data:
            data["CONNECTOR_INSTANCE"] = connector_instances_expand(main, data, log)

        if "CONNECTION" in data:
            data["CONNECTION"] = connections_expand(main, data, log)

        if "DATA" in data:
            data["DATA"] = data_expand(main, data, log)

        if "FUNCTION" in data:
            data["FUNCTION"] = function_expand(main, data, log)

        return data
