# !/usr/bin/env python3
import os
from os import listdir
from os.path import isfile
from yaml import load, dump, safe_dump
from yaml import Loader, Dumper
from termcolor import colored
import model_expand
import model_dump
import traceback

def check_test(test_info, base_name="./"):

    if "IN" not in test_info:
        return "NO IN FILE"

    if "OUT" not in test_info:
        return "NO OUT FILE"

    if "COMPARE" not in test_info:
        return "NO COMPARE FILE"

    if not isfile(base_name + os.path.sep+test_info["IN"]):
        return "No file IN at " + base_name + os.path.sep+test_info["IN"]

    if not isfile(base_name+os.path.sep+test_info["OUT"]):
        return "No file OUT at " + base_name + os.path.sep+test_info["OUT"]

    if not isfile(base_name+os.path.sep+test_info["COMPARE"]):
        return "No file COMPARE at " + base_name + os.path.sep+test_info["COMPARE"]

    return "OK"

def bytes_test(test_info, base_name="./"):
    str_result = ""
    str_expected = ""

    with open(base_name + os.path.sep+test_info["COMPARE"], "r") as f:
        str_result = f.read()

    with open(base_name + os.path.sep+test_info["OUT"], "r") as f:
        str_expected = f.read()

    return "OK" if str_result == str_expected else "FAIL"

def run_test(test_info, base_name="./"):

    with open(base_name + os.path.sep+test_info["COMPARE"], "r") as f:
        expected = load(f, Loader=Loader)

    # TODO
    result = model_expand.file_expand(None, base_name + os.path.sep+test_info["IN"])

    model_dump.model_dump(result,base_name + os.path.sep+test_info["OUT"])

    if expected == result:
        return "OK"
    else:
        return "FAIL"

def color_result(text):
    color = "green" if text == "OK" else "red"
    return colored("%10s"%text, color)


def test_model(file_test_model):

    try:
        with open(file_test_model) as f:
            data = load(f, Loader=Loader)
    except Exception as exp:
        print("YAML error", exp)

    base_name = os.path.dirname(file_test_model)

    print("TEST")

    print("||"+("-"*10+"+")*5+"-"*10+"||")
    print("||%10s|%10s|%10s|%10s|%10s|%10s||" % ("NAME",
                                                 "VERSION",
                                                 "TEST",
                                                 "FILE",
                                                 "RESULT",
                                                 "BYTES"))
    print("||"+("-"*10+"+")*5+"-"*10+"||")

    for one in data:
        check = check_test(one, base_name)
        file_ok = "OK"
        bytes = "wait"
        bytes_ok = "wait"
        run_result = "wait"
        if check == "OK":
            try:
                run_result = run_test(one, base_name)

                bytes_ok = bytes_test(one, base_name)
            except Exception as a:
                file_ok = "FAIL " + str(a)
                traceback.format_exc()
        else:
            run_result = "UNVALID"

        print("||%10s|%10s|%s|%s|%s|%s||" % (one["NAME"],
                                             one["VERSION"],
                                             color_result(check),
                                             color_result(file_ok),
                                             color_result(run_result),
                                             color_result(bytes_ok)))

    print("||"+("-"*10+"+")*5+"-"*10+"||")


def is_link_instance(main, compo, key):
    return 'LINK_INSTANCE' in compo and key in compo["LINK_INSTANCE"]


def is_struct(name, structs):
    return name in structs
