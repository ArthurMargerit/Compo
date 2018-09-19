#!/usr/bin/env python

import yaml
import os
from tools import If
from tools.Selector import range_inteligent_selector
from termcolor import colored
from jinja2 import Template

from template import load_template


def load_template_file(model_path):

    with open(model_path) as model_file:
        model_data = yaml.load(model_file)

    return model_data


def generate_model(jenv, conf, model_path, generation_data):

    model_data = load_template_file("../generate_model/CPP/out.yaml")

    for one_model_entry in model_data:
        generate_one_entry(jenv,
                           conf,
                           one_model_entry,
                           generation_data,
                           True)


def model_complete(model_data):

    pass


def generation_for(selector, a):
    pass


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

        data = {**model_data["DEFAULT"], **target}

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

        print("")
