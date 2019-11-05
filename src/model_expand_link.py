import collections

from model_expand_parent import link_parent_expand
from model_expand_data import data_expand


def link_expand(context, main, data, log=False):

    if isinstance(data, dict):
        d = collections.OrderedDict(data)

        if "DATA" in d:
            d["DATA"] = data_expand(main, data, log)

        if "PARENT" in d:
            d["PARENT"] = link_parent_expand(main, d, log=True)

        return d
    else:
        print("error this type of link is not manage")

    return "Error"
