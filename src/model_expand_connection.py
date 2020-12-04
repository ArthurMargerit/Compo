import collections
from tools.Log import ERR

from model_get import get_link_instance
from model_expand_component import declaration_interface_component_expand
from model_expand_component import declaration_bus_component_expand


def connection_expand(main, c, data, log=False):
    d = collections.OrderedDict()

    from_cut, center, to_cut = False, False, False

    if "-->" in data:
        from_cut = data.split("-->")[0]
        to_cut = data.split("-->")[1]
        kind_connection = "interface"
    elif "-(" in data and ')->' in data:
        from_cut = data.split('-(')[0]
        to_cut = data.split(')->')[-1]
        center = data.split('-(')[1].split(')->')[0]
        kind_connection = "interface"
    elif "-(" in data:
        from_cut = data.split('-(')[0]
        center = data.split('-(')[1].split(')->')[0].replace(')', '')
        kind_connection = "interface"
    elif "+(" in data:
        from_cut = data.split('+(')[0]
        center = data.split('+(')[1].split(')->')[0].replace(')', '')
        kind_connection = "interface"
    elif ")->" in data:
        to_cut = data.split(')->')[-1]
        center = data.split('-(')[0].split(')->')[0].replace('(', '')
        kind_connection = "interface"
    elif "+->" in data:
        to_cut = data.split('+->')[-1]
        from_cut = data.split('+->')[0]
        kind_connection = "interface"
    elif "->" in data:
        to_cut = data.split('->')[-1]
        from_cut = data.split('->')[0]
        kind_connection = "interface"
    elif "=>" in data:
        from_cut = data.split("=>")[0]
        to_cut = data.split("=>")[1]
        kind_connection = "event"
    elif "==>" in data:
        from_cut = data.split("==>")[0]
        to_cut = data.split("==>")[1]
        kind_connection = "event"
    elif ")=>" in data:
        # TODO link event in
        pass
    elif ">=(" in data:
        # TODO link event out
        pass
    else:
        ERR("link not to the  good format", data)


    if kind_connection == "interface":
        if center:
            l_link = center.split(" at ")

            if len(l_link) == 2:
                d["AT"] = l_link[1]

                d["LINK"] = get_link_instance(main, c, l_link[0], True)

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
    elif kind_connection == "event":
        if center:
            ERR("no center needed for event to a link")

        if from_cut:
            d["FROM"] = declaration_bus_component_expand(main,
                                                         c,
                                                         from_cut.replace(" ", ""),
                                                         log,
                                                         "EMITTER")
        if to_cut:
            d["TO"] = declaration_bus_component_expand(main,
                                                       c,
                                                       to_cut.replace(" ", ""),
                                                       log,
                                                       "RECEIVER")

    return d


def connections_expand(main, data, log=False):

    connection_data = []
    for d in data["CONNECTION"]:
        connection_data.append(connection_expand(main, data, d, log))

    return connection_data
