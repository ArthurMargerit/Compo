import collections

from model_get import get_type_or_struct
from tools.Uni import Uni
from tools.Log import ERR
from model_get import is_struct
import ast


def have_default(d):
    if isinstance(d, dict):
        return "DEFAULT" in d

    if isinstance(d, str):
        return "DEFAULT" in d


def parse_arg(data):
    position_first_realchar = 0
    for a in data:
        if a == " ":
            position_first_realchar += 1
        else:
            break
    data = data[position_first_realchar:]
    r = ast.literal_eval(data)
    return r


def default_expand(main, Type, data, log=False):

    if data is None or data == []:
        return ""

    if is_struct(Type["NAME"], main["STRUCTS"]):
        return parse_arg(data)
    else:
        return data

    return "Erreur"


def declaration_expand(main, d, log=False):

    if isinstance(d, dict):
        r = collections.OrderedDict()
        r["NAME"] = d["NAME"]
        r["TYPE"] = get_type_or_struct(main, d["TYPE"])
        r["DEFAULT"] = default_expand(main, d["DEFAULT"])
        return r

    elif isinstance(d, str):
        words = d.split(" ")
        r = collections.OrderedDict()

        r["NAME"] = words[1]
        r["TYPE"] = get_type_or_struct(main, words[0])
        if have_default(d):
            r["DEFAULT"] = default_expand(main,
                                          r["TYPE"],
                                          d.split("DEFAULT")[1],
                                          log)
        return r


def data_check(data):

    if "NAME" not in data:
        ERR("declaration sans NAME")

    if "TYPE" not in data:
        ERR("declaration sans TYPE")
    else:
        if not isinstance(data["TYPE"], dict):
            ERR("Type !y(", data["TYPE"], ")is not valid")


def data_expand(main, data, log=False):

    data_parser = []
    u = Uni()

    for d in data["DATA"]:
        p = declaration_expand(main, d, log)
        if not u.check(p["NAME"]):
            ERR("nom en double ",
                ">!y(", p["NAME"], ")<",
                " dans la struct ",
                ">!y(", data["NAME"], ")<")
        data_parser.append(p)

    return data_parser
