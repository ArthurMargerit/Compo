import collections


def print_me(name, element, before=""):

        if isinstance(element, str):
            print(before, name, ":", sep="", end="")
            print(element)

        elif isinstance(element, collections.OrderedDict) or isinstance(element, dict):
            print(before, name, ":", sep="")
            for e, v in element.items():
                print_me(e, v, before+"  ")

        elif isinstance(element, list):
            print(before, name, ":", sep="")
            for i in range(len(element)):
                print_me(str(i), element[i], before+"  ")

        else:
            print(type(element))
            print("print not manage for this types")