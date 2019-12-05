import collections

from model_expand_parent import link_parent_expand
from model_expand_data import data_expand, parse_arg
from model_get import get_link
from tools.Log import ERR, WARN


def link_instance_expand(main, c, data, log=False):

    d = collections.OrderedDict()

    if "WITH" in data:
        tmp_data = data.split("WITH")
        d["WITH"] = parse_arg(tmp_data[1])
        data = tmp_data[0]

    words = data.split(" ")
    d["TYPE"] = get_link(main, words[0])
    d["NAME"] = words[1]

    return d


def link_instances_expand(main, data, log=False):

    link_data = []

    for d in data["LINK_INSTANCE"]:
        link_data.append(link_instance_expand(main, data, d, log))

    return link_data


VALID_LINK = ["IN", "OUT", "ARRAY_IN", "ARRAY_OUT", "MAP_IN", "MAP_OUT"]

def link_expand(context, main, data, log=False):

    if isinstance(data, dict):
        d = collections.OrderedDict(data)

        if "NAME" not in d:
            ERR("!y(%s) need a name" % d)

        if "S" in d:
            WARN("S field will be deprecated soon")

        if "PORT" in d:
            port_map = {}
            for i_port in d["PORT"]:
                if i_port in VALID_LINK:
                    port_map[i_port] = True
                else:
                    ERR("This kind of link is not support")

            d["PORT"] = port_map
        else:
            ERR("Need !y(PORT) in Link !y(%s)" % d["NAME"])

        if "PARENT" in d:
            d["PARENT"] = link_parent_expand(main, d, log=True)

        return d
    else:
        ERR("this type of link is not manage !y(", data, ")")

    return None
