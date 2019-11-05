import collections


def type_expand(context, main, data, log=False):

    if isinstance(data, dict):
        if "DYNAMIC" not in data:
            data["DYNAMIC"] = False

        if "ARG" in data and data["DYNAMIC"] is False:
            print(colored("Error:", "red"),
                  "Type",
                  colored(data["NAME"], "yellow"),
                  "is not dynamic then no ARG")

        return data

    elif isinstance(data, str):

        words = data.split(" ")
        if len(words) < 2:
            print("wrong number of word in " + data)
            return

        a = collections.OrderedDict()
        a["NAME"] = words[-1]
        a["DEFINITION"] = " ".join(words[0:-1])
        a["DYNAMIC"] = True
        return a

    else:
        print(colored("Error:", "red"),
              " no implementation for ",
              colored(data, "red"))

        return None
