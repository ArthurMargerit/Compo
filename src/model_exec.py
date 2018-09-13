# !/bin/env python

from termcolor import colored


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
    if isinstance(data,str):
        all_key = data.split(" ")
        solve = main
        for key in all_key:
            if key in solve:
                solve = solve[key]
            else:
                print("GET:", str(key), "not in", str(solve))
                return main

        print(solve)

        return main
    else:
        print("data is not support")


def nop_exec(main, data, log=False):
    print("This exec is not ready.")
    pass


def del_exec(main, data, log=False):
    if isinstance(data, str):
        all_key = data.split(" ")
        solve = main
        value = all_key[-1]

        for key in all_key:

            if isinstance(solve, list):
                key = int(key)

            if key in solve:
                if key == all_key[-1]:
                    del solve[key]
                else:
                    solve = solve[key]

            else:
                print("DELETE:", str(key), "not in", str(solve))
                return main

    pass


def set_exec(main, data, log=False):
    if isinstance(data,str):
        all_key = data.split(" ")
        solve = main
        value = all_key[-1]

        for key in all_key[:-1]:

            if key in solve:
                if key == all_key[-2]:
                    solve[key] = value
                else:
                    solve = solve[key]

            else:
                print("SET:", str(solve), "not in", str(key))
                return main

        return main
    else:
        print("data is not support")


def rename_exec(main, data, log=False):
    if isinstance(data,str):
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
                print("RENAME:", str(key), "not in %s", str(solve))
                return main

        return main
    else:
        print("data is not support")

def cp_exec(main, data, log=False):
    if isinstance(data,str):
        all_key = data.split(" ")
        solve = main
        value = all_key[-1]

        for key in all_key[:-1]:

            if key in solve:
                if key == all_key[-2]:
                    solve[value] = solve[key]
                else:
                    solve = solve[key]

            else:
                print("CP:", str(key), "not in", str(solve))
                return main

        return main
    else:
        print("data is not support")
