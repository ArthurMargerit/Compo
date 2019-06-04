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


if __name__ == '__main__':

    data0 = {"lapin": 0}
    data1 = {"lapin": 1}
    data2 = {"AND": {'lion': 1, 'lapin': 1}}
    data3 = {"OR": {'lion': 1, 'lapin': 1}}
    data4 = {"a.a": 1}
    data5 = {"a.a": 2}
    data6 = {"a": {"a": 1}}

    dd = {"lapin": 1, "a": {"a": 1}}

    print(if_solve(data0, dd) == False)
    print(if_solve(data1, dd) == True)
    print(if_solve(data2, dd) == False)
    print(if_solve(data3, dd) == True)
    print(if_solve(data4, dd) == True)
    print(if_solve(data5, dd) == False)
    print(if_solve(data6, dd) == True)
