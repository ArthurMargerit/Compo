# !/usr/bin/env python3

from os import listdir
from os.path import isfile
from yaml import load, dump
from yaml import Loader, Dumper

def run_test(test_info):

    with open(test_info["OUT"],"r") as f:
        expected = load(f, Loader=Loader)

    if expected == result:
        print("OK")
    else:
        print("FAIL")

    
def test_model(file_test_model):

    with open(file_test_model,"r") as f:
        data = load(f, Loader=Loader)

    print("TEST")
    for one in data:
        print(one["NAME"],one["VERSION"])
        run_test()





