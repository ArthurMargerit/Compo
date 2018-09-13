#!/usr/bin/env python

def range_inteligent_selector(selector, data):
    a = []
    range_inteligent_selector2(selector, data,a)
    return a


def range_inteligent_selector2(selector, data, list_e):

    selectors = selector.split(".")

    # manage the empty selecetor
    if selector is '':
        list_e.append(data)
        return
    s = selectors[0]

    # manage the * selector
    if s == "*":
        if not isinstance(data, dict) and not isinstance(data, list):
            return

        for one in data.values():
            range_inteligent_selector2(".".join(selectors[1:]), one, list_e)

        return

    # manage non existence

    if s not in data:
        return

    range_inteligent_selector2(".".join(selectors[1:]), data[s], list_e)


