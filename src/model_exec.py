# !/bin/env python

from tools.Log import ERR, INFO
from tools import Selector
import Config


def get_exec_function():

    EXEC_FUNCTION = {
        "GET": get_exec,
        "SET": set_exec,
        "RENAME": rename_exec,
        "DEL": del_exec,
        "CP": cp_exec
    }

    return EXEC_FUNCTION


def get_exec(main, data, log=False):
    if isinstance(data, str):
        all_key = data.split(" ")
        solve = main
        for key in all_key:
            if key in solve:
                solve = solve[key]
            else:
                INFO("GET:", key, "not in", solve)
                return main

        INFO(solve)

        return main
    else:
        ERR("data is not support")


def nop_exec(main, data, log=False):
    ERR("This exec is not ready.")
    pass


def del_exec(main, data, log=False):
    if isinstance(data, str):
        all_key = data.split(" ")
        solve = main
        # value = all_key[-1]

        for key in all_key:

            if isinstance(solve, list):
                key = int(key)

            if key in solve:
                if key == all_key[-1]:
                    del solve[key]
                else:
                    solve = solve[key]

            else:
                INFO("DELETE:", key, " not in ", solve)
                return main

    pass


VALID_SET = ["CONFIG", "CODE"]


def set_exec(main, data, log=False):
    if isinstance(data, str):
        all_key = data.split(" ")
        mode = all_key[0]
        key = all_key[1]
        value = " ".join(all_key[2:])

        if mode not in VALID_SET:
            ERR(mode, " is not a VALID !y(", VALID_SET, ")")
            return

        conf = Config.Configuration_manager.get_conf()
        conf.set("template_options."+key, value, True)

        return main
    else:
        ERR("data is not support !y(", data, ")")


def rename_exec(main, data, log=False):
    if isinstance(data, str):
        all_key = data.split(" ")
        solve = main
        value = all_key[-1]

        for key in all_key[:-1]:

            if key in solve:
                if key == all_key[-2]:
                    solve[value] = solve[key]
                    del solve[key]
                else:
                    solve = solve[key]

            else:
                INFO("RENAME:", key, " not in %s ", solve)
                return main

        return main
    else:
        ERR("data is not support")


# def cp_exec(main, data, log=False):
#     if isinstance(data, str):
#         all_key = data.split(" ")
#         solve = main
#         value = all_key[-1]

#         for key in all_key[:-1]:

#             if key in solve:
#                 if key == all_key[-2]:
#                     solve[value] = solve[key]
#                 else:
#                     solve = solve[key]

#             else:
#                 INFO("CP:", key, " not in ", solve)
#                 return main

#         return main
#     else:
#         ERR("data is not support")

def cp_exec(main, data, log=False):
    if isinstance(data, str):
        r = data.split(" ")
        from_e = r[0]
        to_e = r[1]
        s = Selector.range_inteligent_selector(from_e, main)
        if len(s) == 0:
            ERR("0 element selected by ", s)

        if len(s) != 1:
            ERR(len(s), " element selected by ", s, " should be 1")

        r = to_e.split(".")
        main_pos = main
        for main_selector in r[:-1]:
            main_pos = main_pos[main_selector]

        main_pos[r[-1]] = s[0]

    elif isinstance(data, list):
        pass
    else:
        ERR("data is not support")
