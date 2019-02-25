#!/usr/bin/env python3

import yaml
import os
from tools import If
from tools.Selector import range_inteligent_selector
from termcolor import colored
from jinja2 import Template
from model_utils import print_me
from template import load_template


import model_test
import model_get


def load_template_file(model_path):

    with open(model_path) as model_file:
        model_data = yaml.load(model_file)

    return model_data


def generate_model(jenv, conf, model_path, generation_data):

    model_data = load_template_file(conf.get("generation_model"))

    # print_me("lapin", generation_data)

    for one_model_entry in model_data:
        generate_one_entry(jenv,
                           conf,
                           one_model_entry,
                           generation_data,
                           True)


def get_gen_filter(path='./'):
    """test if gen.yaml are present """

    filepath = "gen.yaml"

    if true:
        pass
    else:
        pass

    # yaml load

    # check

    # return

def load_gen_filter():
    pass

def filter_match(gen_filter, element):
    pass

def have_one_match(tree_gen_filter, element):
    pass

def model_complete(model_data):
    pass


def generation_for(selector, a):
    pass


def get_Function_tool():
    data = {
        "model_get": model_get,
        "model_test": model_test
    }

    return { "Function": data}


def default_expand(default, data):

    if isinstance(default,str):
        if "MODEL:" in default:
            path = ":".join(default.split(":")[1:])

            print(path)
            if path == ".":
                return data
            else:
                print("TODO")

    return default

def defaults_expand(default, data):

    for kv in default.items():
        default[kv[0]] = default_expand(kv[1],data)

    return default

def generate_one_entry(jenv, conf, model_data, generation_data, log=False):
    if log:
        print(colored(model_data["NAME"],
                      'green'),
              "->")

    for target in range_inteligent_selector(model_data["FOR"],
                                            generation_data
                                            ):

        if "DEFAULT" not in model_data:
            model_data["DEFAULT"] = dict()
        else:
            model_data["DEFAULT"] = defaults_expand(model_data["DEFAULT"], generation_data)

        data = {**model_data["DEFAULT"], **target, **get_Function_tool()}

        if "IF" in model_data:
            if not If.if_solve(model_data["IF"], data):
                continue


        print("\t",
              "> ",
              Template(model_data["TARGET_NAME"]).render(data) if "TARGET_NAME" in model_data else model_data["FOR"])

        for file in model_data["FILES"]:

            in_file = Template(file["IN"]).render(data)
            out_file = Template(file["OUT"]).render(data)

            print("\t"*2,
                  in_file,
                  "->",
                  out_file)

            os.makedirs(os.path.dirname(out_file), exist_ok=True)
            with open(out_file, 'w') as f:
                f.write(load_template(jenv, in_file).render(data))

        for cmd in model_data["COMMANDS"]:
            cmd_t = Template(cmd).render(data)
            print(">",cmd_t)

            err = os.system(cmd_t)
            if err != 0 :
                print("ERROR", err)
                exit(err)



