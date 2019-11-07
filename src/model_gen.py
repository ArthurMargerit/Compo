from model_get import get_type_or_struct, get_interface
from tools.Log import ERR


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
            sig = []
            if f["RETURN"]["NAME"] != "void":
                sig.append({"TYPE": f["RETURN"],
                            "NAME": "p_"+f["NAME"]})

            interface["FUNCTION"].append(
                {"RETURN": get_type_or_struct(main, "void"),
                 "NAME": f["NAME"],
                 "SIGNATURE": sig})

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


def build_sign_of_arg(main, vec, sign):
    r_sign = []
    for s in sign:
        line = {"NAME": s["NAME"],
                "TYPE": get_type_or_struct(main,
                                           vec+"<"+s["TYPE"]["NAME"]+">",
                                           True)}
        r_sign.append(line)

    return r_sign


def gen_many_return(main, interface, args=[], log=False):
    if "FUNCTION" not in interface:
        interface["FUNCTION"] = []

    i = get_interface(main, args[0], log)

    if "FUNCTION" in i:
        for f in i["FUNCTION"]:

            if f["RETURN"]["NAME"] == "void":
                interface["FUNCTION"].append(
                    {"RETURN": f["RETURN"],
                     "NAME": f["NAME"],
                     "SIGNATURE": f["SIGNATURE"]})

            else:
                l_return = get_type_or_struct(main,
                                              args[1]+"<"+f["RETURN"]["NAME"]+">",
                                              log)
                interface["FUNCTION"].append(
                    {"RETURN": l_return,
                     "NAME": f["NAME"],
                     "SIGNATURE": f["SIGNATURE"]})

    if "DATA" in i:
        for d in i["DATA"]:
            l_return = get_type_or_struct(main,
                                          args[1]+"<"+d["TYPE"]["NAME"]+">",
                                          log)
            interface["FUNCTION"].append(
                {"RETURN": l_return,
                 "NAME": "get_"+d["NAME"],
                 "SIGNATURE": []})

            interface["FUNCTION"].append(
                {"RETURN": get_type_or_struct(main, "void"),
                 "NAME": "set_"+d["NAME"],
                 "SIGNATURE": [{"NAME": "p_"+d["NAME"],
                                "TYPE": d["TYPE"]}]})

    return interface


def gen_many_interface(main, interface, args, func, log):
    if func["RETURN"]["NAME"] == "void":
        interface["FUNCTION"].append(
            {"RETURN": func["RETURN"],
             "NAME": func["NAME"],
             "SIGNATURE": build_sign_of_arg(main,
                                            args[1],
                                            func["SIGNATURE"])})
    else:
        l_return = get_type_or_struct(main,
                                      args[1]+"<"+func["RETURN"]["NAME"]+">",
                                      log)
        interface["FUNCTION"].append(
            {"RETURN": l_return,
             "NAME": func["NAME"],
             "SIGNATURE": build_sign_of_arg(main, args[1], func["SIGNATURE"])})


def gen_many_data(main, interface, args, d, log):
    l_return = get_type_or_struct(main, args[1]+"<"+d["TYPE"]["NAME"]+">", log)
    interface["FUNCTION"].append(
        {"RETURN": l_return,
         "NAME": "get_"+d["NAME"],
         "SIGNATURE": []})

    interface["FUNCTION"].append(
        {"RETURN": get_type_or_struct(main, "void"),
         "NAME": "set_"+d["NAME"],
         "SIGNATURE": [{"NAME": "p_"+d["NAME"],
                        "TYPE": l_return}]})


def gen_many(main, interface, args=[], log=False):
    if "FUNCTION" not in interface:
        interface["FUNCTION"] = []

    i = get_interface(main, args[0], log)

    if "FUNCTION" in i:
        for f in i["FUNCTION"]:
            gen_many_interface(main, interface, args, f, log)

    if "DATA" in i:
        for d in i["DATA"]:
            gen_many_data(main, interface, args, d, log)

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
    "many": gen_many,
    "many_return": gen_many_return,
    "async_return": gen_async_return,
    "add_params": gen_add_params
}


def interface_gen(main, interface, gen_func, log=False):

    position = gen_func.find("(")
    func_name = gen_func[0:position]
    func_args = gen_func[position+1:-1].split(",")

    if func_name not in Gen_public:
        ERR("function gen doesn't exist")
        return None

    return Gen_public[func_name](main, interface, func_args, log)
