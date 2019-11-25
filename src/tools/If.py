from tools import Selector


def if_test(key, val, data):
    result = Selector.range_inteligent_selector(key, data)

    if len(result) == 0:
        return False

    if len(result) != 1:
        return False

    return val == result[0]


def if_solve(resolve, data):

    if "OR" in resolve:
        result = False
        for one in resolve["OR"].items():
            result = result or if_solve({one[0]: one[1]}, data)
        return result

    if "NOT" in resolve:
        for one in resolve["NOT"].items():
            result = not if_solve({one[0]: one[1]}, data)
            return result

    if "AND" in resolve:
        result = True
        for one in resolve["AND"].items():
            result = result and if_solve({one[0]: one[1]}, data)
        return result

    result = True
    for var in resolve.items():
        result = result and if_test(var[0], var[1], data)
    return result
