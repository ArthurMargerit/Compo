from termcolor import colored
from model_get import get_type_or_struct, get_interface


def gen_async_call(main, interface, args=[], log=False):
    if "FUNCTION" not in interface:
        interface["FUNCTION"] = []

    i = get_interface(main, args[0], log)

    if "FUNCTION" in i:
        for f in i["FUNCTION"]:
            interface["FUNCTION"].append(
                {"RETURN": get_type_or_struct(main, "void"),
                 "NAME": f["NAME"],
                 "SIGNATURE": f["SIGNATURE"][:]})

    if "DATA" in i:
        for d in i["DATA"]:
            interface["FUNCTION"].append(
                {"RETURN": get_type_or_struct(main, "void"),
                 "NAME": "get_"+d["NAME"],
                 "SIGNATURE": []})

            interface["FUNCTION"].append(
                {"RETURN": get_type_or_struct(main, "void"),
                 "NAME": "set_"+d["NAME"],
                 "SIGNATURE": [{"TYPE": d["TYPE"],
                                "NAME": "p_"+d["NAME"]}]})

    return interface


def gen_async_return(main, interface, args=[], log=False):
    if "FUNCTION" not in interface:
        interface["FUNCTION"] = []

    i = get_interface(main, args[0], log)

    if "FUNCTION" in i:
        for f in i["FUNCTION"]:
            interface["FUNCTION"].append(
                {"RETURN": f["RETURN"],
                 "NAME": f["NAME"],
                 "SIGNATURE": []})

    if "DATA" in i:
        for d in i["DATA"]:
            interface["FUNCTION"].append(
                {"RETURN": get_type_or_struct(main, "void"),
                 "NAME": "get_"+d["NAME"],
                 "SIGNATURE": [{"TYPE": d["TYPE"],
                                "NAME": "p_"+d["NAME"]}]})

            interface["FUNCTION"].append(
                {"RETURN": get_type_or_struct(main, "void"),
                 "NAME": "set_"+d["NAME"],
                 "SIGNATURE": []})

    return interface

def gen_add_params(main, interface, args=[], log=False):
    if "FUNCTION" not in interface:
        interface["FUNCTION"] = []

    i = get_interface(main, args[0], log)
    t = get_type_or_struct(main, args[1])
    dd = {"NAME": "p_key",
          "TYPE": t}

    if "FUNCTION" in i:
        for f in i["FUNCTION"]:
            interface["FUNCTION"].append(
                {"RETURN": f["RETURN"],
                 "NAME": f["NAME"],
                 "SIGNATURE": [dd, *f["SIGNATURE"][:]]})

    if "DATA" in i:
        for d in i["DATA"]:
            interface["FUNCTION"].append(
                {"RETURN": get_type_or_struct(main, "void"),
                 "NAME": "set_"+d["NAME"],
                 "SIGNATURE": [dd,
                               {"TYPE": d["TYPE"],
                                "NAME": "p_"+d["NAME"]}]})

            interface["FUNCTION"].append(
                {"RETURN": d["TYPE"],
                 "NAME": "get_"+d["NAME"],
                 "SIGNATURE": [dd]})

    return interface

Gen_public = {
    "async_call": gen_async_call,
    "async_return": gen_async_return,
    "add_params": gen_add_params
}


def interface_gen(main, interface, gen_func, log=False):

    position = gen_func.find("(")
    func_name = gen_func[0:position]
    func_args = gen_func[position+1:-1].split(",")

    if func_name not in Gen_public:
        print(colored("Error:", "red"), "function gen doesn't exist")
        return None

    return Gen_public[func_name](main, interface, func_args, log)
