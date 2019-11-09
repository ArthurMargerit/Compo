# !/bin/env python
import os.path

from model_dump import yaml

from Config import Configuration_manager
from model_exec import get_exec_function

from model_get import get_empty_main
from tools.Log import ERR

from model_parsing_context import context_list_file, context_add_file
from model_parsing_context import context_create
from model_parsing_context import context_pop_file


from model_expand_type import type_expand
from model_expand_error import error_expand
from model_expand_struct import struct_expand
from model_expand_interface import interface_expand
from model_expand_connector import connector_expand
from model_expand_component import component_expand
from model_expand_link import link_expand
from model_expand_deployment import deployment_expand


def nop_expand(main, data, log=False):
    ERR("Parsing is not implemented for",
        data)

    return None


def import_expand(context, main, data, log=False):

    if isinstance(data, dict) or isinstance(data, list):
        ERR("Import !y(", data, ") is not a string")

    if isinstance(data, str):
        file = data
        list_path = Configuration_manager.get_conf().get("import_path")
        valid = None

        for l in list_path:
            path_file = l + os.path.sep + file
            if os.path.isfile(path_file):
                valid = path_file

        if valid is None:
            ERR("file: !y(", file, ") doesn't exit :\n",
                "".join(["> !y("+m+")\n" for m in context_list_file(context)]))

        if len(context_list_file(context)) > 100:
            ERR("Import stack upper than 100, maybe a infinite loop?\n",
                "".join(["> !y("+m+")\n" for m in context_list_file(context)]))

        main_import = get_empty_main()
        main_inport = file_expand(context, main_import, valid, log)

        return {"NAME": file,
                "PATH": valid,
                "MAIN": main_inport}


def get_expand_function():

    EXPAND_FONCTION = {
        "IMPORT": import_expand,
        "TYPE": type_expand,
        "ERROR": error_expand,
        "LINK": link_expand,
        "STRUCT": struct_expand,
        "INTERFACE": interface_expand,
        "CONNECTOR": connector_expand,
        "COMPONENT": component_expand,
        "DEPLOYMENT": deployment_expand}

    return EXPAND_FONCTION


def use_type_in_struct(type, struct):
    for d in struct["DATA"]:
        if use_type_in_TYPE(type, d):
            return True
    return False


def use_type_in_TYPE(type, TYPE):
    if TYPE == type:
        return True

    # on a une struct
    if "DATA" in TYPE:
        return use_type_in_struct(TYPE)


def get_struct_with_type(type, structs):

    use_by_structs = []
    for struct in structs:
        if use_type_in_struct(type, struct):
            use_by_structs.append(struct)

    return use_by_structs


def use_type_in_interface(type, interface):

    if "DATA" in interface:
        for d in interface["DATA"]:
            if use_type_in_TYPE(type, d["TYPE"]):
                return True

    if "FUNCTION" in interface:
        for d in interface["FUNCTION"]:
            if use_type_in_TYPE(type, interface["RETURN"]):
                return True
            for param in d["SIGNATURE"]:
                if use_type_in_TYPE(type, param["TYPE"]):
                    return True


def get_interfaces_with_type(type, interfaces):

    use_by_interface = []

    for interface in interfaces:
        if use_type_in_interface(type, interface):
            use_by_interface.append(interface)

    return use_by_interface


def use_type_in_component(type, component):

    if "DATA" in component:
        for d in component["DATA"]:
            if use_type_in_TYPE(type, d):
                return True
    if "PROVIDE" in component:
        for d in component["PROVIDE"]:
            if use_type_in_interface(type, d):
                return True

    if "REQUIRE" in component:
        for d in component["REQUIRE"]:
            if use_type_in_interface(type, d):
                return True

    return False


def get_component_with_type(type, components):

    # STRUCT CHECK
    use_by_component = []

    for component in components:
        if use_type_in_component(type, component):
            use_by_component.append(component)

    return use_by_component


def use_type_in_deployment(type, deployment):

    if "COMPONENT_INSTANCE" in deployment:
        for d in deployment["COMPONENT_INSTANCE"]:
            if use_type_in_component(type, deployment):
                return True

    return False


def get_deployment_with_type(type, deployments):
    use_by_deployment = []

    for deployment in deployments:
        if use_type_in_deployment(type, deployment):
            use_by_deployment.append(deployment)

    return use_by_deployment


def file_expand(context, main, file_path, log=False):

    conf = Configuration_manager.get_conf()

    # apply a read only value as real values
    if not conf.exist("import_path"):
        conf.set("import_path", conf.get("import_path"))

    conf.get("import_path").append(os.path.dirname(file_path))

    if main is None:
        main = get_empty_main()

    main["FILE"] = os.path.basename(file_path)

    if context is None:
        context = context_create(file_path)
    else:
        context_add_file(context, file_path)

    if not os.path.isfile(file_path):
        ERR(">!y(", file_path, ")",
            " doesn't exist")

    with open(file_path) as file:
        data = yaml.load(file, Loader=yaml.SafeLoader)

    EXPAND_FONCTION = get_expand_function()
    EXEC_FUNCTION = get_exec_function()

    if data is None:
        return main

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        if function_selector in EXPAND_FONCTION:
            information = EXPAND_FONCTION[function_selector](context,
                                                             main,
                                                             information,
                                                             log=True)

            if log:
                print(function_selector)
                print("=>", information, "\n")

            main[function_selector+"S"][information["NAME"]] = information
            continue

        if function_selector in EXEC_FUNCTION:
            EXEC_FUNCTION[function_selector](main, information)
            continue

    context_pop_file(context)
    conf.get("import_path").pop()

    return main


def str_expand(context, main, txt, log=False):

    if main is None:
        main = get_empty_main()

    main["FILE"] = "d"

    data = yaml.load(txt, loader=yaml.SafeLoader)

    EXPAND_FONCTION = get_expand_function()
    EXEC_FUNCTION = get_exec_function()

    if data is None:
        return main

    for a in data:
        function_selector = list(a)[0]
        information = a[function_selector]

        if function_selector in EXPAND_FONCTION:
            f = EXPAND_FONCTION[function_selector]
            information = f(context, main, information, log=True)

            if log:
                print(function_selector)
                print("=>", information, "\n")

            main[function_selector+"S"][information["NAME"]] = information
            continue

        if function_selector in EXEC_FUNCTION:
            EXEC_FUNCTION[function_selector](main, information)
            continue

    return main
