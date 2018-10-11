from termcolor import colored
from model_get import get_type_or_struct, get_interface, get_component, get_stuct, get_empty_main, get_link, get_deployment


def component_parent_expand(main, data, log=False):

    if isinstance(data, dict):
        return None

    if isinstance(data, list):
        print(colored("ERROR:", "red"),
              "many parent are not allowed,",
              "choose one of ("
              ",".join([colored(elem, "green") for elem in data]),
              ")")
        return None

    if isinstance(data, str):
        return get_component(main, data)


def struct_parent_expand(main, data, log=False):
    if isinstance(data, dict):
        return None

    if isinstance(data, list):
        print(colored("ERROR:", "red"),
              "many parent are not allowed,",
              "choose one of ("
              ",".join([colored(elem, "green") for elem in data]),
              ")")
        return None

    if isinstance(data, str):
        return get_stuct(main, data)


def interface_parent_expand(main, data, log=False):
    if isinstance(data, dict):
        return None

    if isinstance(data, list):
        print(colored("ERROR:", "red"),
              "many parent are not allowed,",
              "choose one of ("
              ",".join([colored(elem, "green") for elem in data]),
              ")")
        return None

    if isinstance(data, str):
        return get_interface(main, data)


def deployment_parent_expand(main, data, log=False):
    if isinstance(data, dict):
        return None

    if isinstance(data, list):
        print(colored("ERROR:", "red"),
              "many parent are not allowed,",
              "choose one of ("
              ",".join([colored(elem, "green") for elem in data]),
              ")")
        return None

    if isinstance(data, str):
        return get_deployment(main, data, log)
