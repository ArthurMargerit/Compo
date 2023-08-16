#!/usr/bin/env python
from tools.Log import ERR


def range_inteligent_selector(selector, data, extra_arg=dict()):
    a = []
    range_inteligent_selector2(selector, data, a, extra_arg)
    return a


def range_inteligent_selector2(selector, data, list_e, arg=dict()):

    selectors = selector.split(".")

    # manage the empty selecetor
    if selector == '':
        list_e.append(data if len(arg) == 0 else {**arg, **data})
        return
    s = selectors[0]

    # manage the * selector
    if s[0] == "*":
        arg_name = ""

        if len(s) != 1:
            arg_name = s[2:-1]

        if not isinstance(data, dict) and not isinstance(data, list):
            ERR("... Wrong selecetor ...", selector)
            return

        for one in data.values() if isinstance(data, dict) else data:
            arg_next = arg.copy()

            if arg_name != "":
                arg_next[arg_name] = one

            range_inteligent_selector2(
                ".".join(selectors[1:]), one, list_e, arg_next)

        return

    # manage non existence

    if s not in data:
        return

    range_inteligent_selector2(".".join(selectors[1:]), data[s], list_e, arg)
