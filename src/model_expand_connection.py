import collections

from model_get import get_link_instance
from model_expand_component import declaration_interface_component_expand


def connection_expand(main, c, data, log=False):
    d = collections.OrderedDict()

    words = []
    from_cut, center, to_cut = False, False, False

    if "-(" in data and ')->' in data:
        from_cut = data.split('-(')[0]
        to_cut = data.split(')->')[-1]
        center = data.split('-(')[1].split(')->')[0]
    elif "-(" in data:
        from_cut = data.split('-(')[0]
        center = data.split('-(')[1].split(')->')[0].replace(')', '')
    elif "+(" in data:
        from_cut = data.split('+(')[0]
        center = data.split('+(')[1].split(')->')[0].replace(')', '')
    elif ")->" in data:
        to_cut = data.split(')->')[-1]
        center = data.split('-(')[0].split(')->')[0].replace('(', '')
    elif "-->" in data:
        to_cut = data.split('-->')[-1]
        from_cut = data.split('-->')[0]
    elif "+->" in data:
        to_cut = data.split('+->')[-1]
        from_cut = data.split('+->')[0]
    elif "->" in data:
        from_cut = data.split("->")[0]
        to_cut = data.split("->")[1]
    else:
        print(colored("Error", "red"), ": link not to the  good format", data)

    if center:
        d["LINK"] = get_link_instance(main, c, center.replace(" ", ""), True)

    if from_cut:
        d["FROM"] = declaration_interface_component_expand(main,
                                                           c,
                                                           from_cut.replace(" ", ""),
                                                           log,
                                                           "REQUIRE_LIST" if "+" in data else "REQUIRE")

        d["FROM"]["KIND"] = "add" if "+" in data else "set"
    if to_cut:
        d["TO"] = declaration_interface_component_expand(main,
                                                         c,
                                                         to_cut.replace(" ", ""),
                                                         log,
                                                         "PROVIDE")
    return d


def connections_expand(main, data, log=False):

    connection_data = []
    for d in data["CONNECTION"]:
        connection_data.append(connection_expand(main, data, d, log))

    return connection_data
