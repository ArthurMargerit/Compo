import collections
from tools.Log import ERR
from model_expand_option import options_expand


def type_expand(context, main, data, log=False):

    if isinstance(data, dict):
        if "DYNAMIC" not in data:
            data["DYNAMIC"] = False

        if "ARG" in data and data["DYNAMIC"] is False:
            ERR("TYPE",
                "!y(", data["NAME"], ")",
                "is not dynamic then no ARG")

        if "OPTIONS" not in data:
            data["OPTIONS"] = {}
        data["OPTIONS"] = options_expand("TYPE", data["OPTIONS"])

        return data

    elif isinstance(data, str):

        words = data.split(" ")
        if len(words) < 2:
            ERR("TYPE wrong number of word in !y(", data, ")")
            return

        a = collections.OrderedDict()
        a["NAME"] = words[-1]
        a["DEFINITION"] = " ".join(words[0:-1])
        a["DYNAMIC"] = True

        if "OPTIONS" not in data:
            data["OPTIONS"] = {}
        data["OPTIONS"] = options_expand("TYPE", data["OPTIONS"])

        return a

    else:
        ERR("TYPE wrong declaration !y(", data, ")")
        return None
