from tools.Log import ERR

from model_get import get_error
from model_get import get_event
from model_get import get_stuct
from model_get import get_interface, get_component
from model_get import get_link, get_deployment
from model_get import get_port


def component_parent_expand(main, data, log=False):

    if isinstance(data["PARENT"], dict):
        return None

    if isinstance(data["PARENT"], list):
        ERR("many parent are not allowed,",
            "choose one of ("
            ",".join(["!g(%s)" % elem for elem in data]),
            ")")
        return None

    if isinstance(data["PARENT"], str):
        return get_component(main, data["PARENT"])


def port_parent_expand(main, data, log=False):

    if isinstance(data, dict):
        return None

    if isinstance(data, list):
        ERR("many parent are not allowed,",
            "choose one of ("
            ",".join(["!g(%s)" % elem for elem in data]),
            ")")
        return None

    if isinstance(data, str):
        return get_port(main, data)


def struct_parent_expand(main, data, log=False):
    if isinstance(data, dict):
        return None

    if isinstance(data, list):
        ERR("many parent are not allowed,",
            "choose one of ("
            ",".join(["!g(%s)" % elem for elem in data]),
            ")")
        return None

    if isinstance(data, str):
        return get_stuct(main, data)


def event_parent_expand(main, data, log=False):
    if isinstance(data, dict):
        return None

    if isinstance(data, list):
        ERR("many parent are not allowed,",
            "choose one of ("
            ",".join(["!g(%s)" % elem for elem in data]),
            ")")

    if isinstance(data, str):
        return get_event(main, data)


def error_parent_expand(main, data, log=False):
    if isinstance(data, dict):
        return None

    if isinstance(data, list):
        ERR("many parent are not allowed,",
            "choose one of ("
            ",".join(["!y(%s)" % elem for elem in data]),
            ")")
        return None

    if isinstance(data, str):
        return get_error(main, data)


def link_parent_expand(main, data, log=False):
    if isinstance(data["PARENT"], dict):
        return None

    if isinstance(data["PARENT"], list):
        ERR("many parent are not allowed,",
            "choose one of ("
            ",".join(["!y(%s)" % elem for elem in data]),
            ")")
        return None

    if isinstance(data["PARENT"], str):
        return get_link(main, data["PARENT"])

    return None


def interface_parent_expand(main, data, log=False):
    if isinstance(data, dict):
        return None

    if isinstance(data, list):
        ERR("many parent are not allowed,",
            "choose one of ("
            ",".join(["!y(%s)" % elem for elem in data]),
            ")")

        return None

    if isinstance(data, str):
        return get_interface(main, data)


def deployment_parent_expand(main, data, log=False):
    if isinstance(data["PARENT"], dict):
        return data["PARENT"]

    if isinstance(data["PARENT"], list):
        ERR("many parent are not allowed,",
            "choose one of ("
            ",".join(["!y(%s)" % elem for elem in data]),
            ")")
        return None

    if isinstance(data["PARENT"], str):
        return get_deployment(main, data["PARENT"], log=log)
