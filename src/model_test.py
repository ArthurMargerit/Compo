# !/usr/bin/env python3

from os import listdir
from os.path import isfile
from yaml import load, dump
from yaml import Loader, Dumper

def check_test(test_info, base_name="./"):

    if not "IN"  in test_info:
        return "NO IN FILE"

    if not "OUT"  in test_info:
        return "NO OUT FILE"

    if not "COMPARE"  in test_info:
        return "NO COMPARE FILE"

    if not isfile(base_name+os.path.sep+test_info["IN"]):
        return "No file IN at " + base_name+os.path.sep+test_info["IN"]

    if not isfile(base_name+os.path.sep+test_info["OUT"]):
        return "No file OUT at " + base_name+os.path.sep+test_info["OUT"]

    if not isfile(base_name+os.path.sep+test_info["COMPARE"]):
        return "No file COMPARE at " + base_name+os.path.sep+test_info["COMPARE"]

    return "OK"

def run_test(test_info, base_name="./"):



    with open(base_name+os.path.sep+test_info["COMPARE"],"r") as f:
        expected = load(f, Loader=Loader)

    # TODO
    result = ""

    if expected == result:
        return "OK"
    else:
        return "FAIL"

def test_model(file_test_model):

    try:
        with open(file_test_model) as f:
            data = load(f, Loader=Loader)
    except Exception:
        print("YAML error")

    base_name = os.path.dirname(file_test_model)
    print("TEST")
    print "||"+"-"*10+"+"+"-"*10+"+"+"-"*40
    print "||%10s|%10s|%10s|%35s    " %("NAME","VERSION","VALID","STATUS")
    print "||"+"-"*10+"+"+"-"*10+"+"+"-"*40

    for one in data:
        check = check_test(one, base_name)

        if check == "OK":
            run_result = run_test(one, base_name)
        else:
            run_result = "UNVALID"

        print "||%10s|%10s|%s|  %s"%(one["NAME"],one["VERSION"], check, run_result)

    print "||"+"-"*10+"+"+"-"*10+"+"+"-"*40


test_model("../model/test.yaml")

