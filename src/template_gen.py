#!/usr/bin/env python

import yaml
from Config import Configuration_manager
import os

from tools import If
from tools.Selector import range_inteligent_selector
from termcolor import colored
from jinja2 import Template, Environment,  FileSystemLoader
from helper import include_helper, color

from tools.Log import ERR

import model_test
import model_get
import re


def load_jinja_env(conf):
    loader = FileSystemLoader(conf.get("jinja_template_path"))
    env = Environment(loader=loader)
    return env


def load_template(jinja_env, template_name):
    return jinja_env.get_template(template_name)


def load_template_file(model_path):

    with open(model_path) as model_file:
        model_data = yaml.load(model_file, Loader=yaml.SafeLoader)

    return model_data


def generate_match(match, elem):
    m = re.match(match, elem)
    return m is not None


def generate_model(jenv, conf, model_path, generation_data,
                   target=".*", ignore=None, log=False):

    model_data = load_template_file(conf.get("generation_model"))

    for one_model_entry in model_data:

        generate_one_entry(jenv,
                           conf,
                           one_model_entry,
                           generation_data,
                           target=target,
                           ignore=ignore,
                           log=log)


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
        "model_test": model_test,
        "include_helper": include_helper,
        "zip": zip,
        "color": color.node_color
    }

    return {"Function": data}


def get_config_option():
    data = {
        "options": Configuration_manager.get_conf().get("template_options")
    }

    return data


def default_model_expand(path, data):

    selectors = path.split(".")

    d = data
    for selector in selectors:
        if selector in d:
            d = d[selector]
        else:
            ERR(selector, "n'est pas dispo")
            exit(1)
    return d


def default_expand(default, data):

    if isinstance(default, str):
        if "MODEL:" in default:
            path = ":".join(default.split(":")[1:])

            if path == ".":
                return data
            else:
                return default_model_expand(path, data)

        if "FILE:" in default:
            path = ":".join(default.split(":")[1:])

            print("TODO FILE")

    return default


def defaults_expand(default, data):

    for kv in default.items():
        default[kv[0]] = default_expand(kv[1], data)

    return default


def generate_get_name(model_data, data):
    if "TARGET_NAME" in model_data:
        return Template(model_data["TARGET_NAME"]).render(data)
    else:
        return model_data["FOR"]


def generate_one_entry(jenv, conf, model_data, generation_data, target=".*", ignore=None,
                       log=False):
    if log:
        print(colored(model_data["NAME"],
                      'green'),
              "->")

    for target_i in range_inteligent_selector(model_data["FOR"],
                                              generation_data):

        if "DEFAULT" not in model_data:
            model_data["DEFAULT"] = dict()
        else:
            model_data["DEFAULT"] = defaults_expand(model_data["DEFAULT"],
                                                    generation_data)

        data = {**model_data["DEFAULT"],
                **target_i,
                "THIS": target_i,
                **get_Function_tool(),
                **get_config_option()}

        if "IF" in model_data:
            if not If.if_solve(model_data["IF"], data):
                continue

        m = generate_get_name(model_data, data)

        if not generate_match(target, m):
            continue

        if ignore is not None and generate_match(ignore, m):
            continue

        print("\t", "> ", m)

        for file in model_data["FILES"]:

            in_file = Template(file["IN"]).render(data)
            out_file = Template(file["OUT"]).render(data)

            print("\t"*2, in_file, "->", out_file)

            os.makedirs(os.path.dirname(out_file), exist_ok=True)
            with open(out_file, 'w') as f:
                f.write(load_template(jenv, in_file).render(data))

        if "COMMANDS" in model_data:
            for cmd in model_data["COMMANDS"]:
                cmd_t = Template(cmd).render(data)
                print("\t"*1, colored("$", 'red'), colored(cmd_t, 'yellow'))

                err = os.system(cmd_t)
                if err != 0:
                    ERR("Command ",
                        ">", cmd_t, "<",
                        "\n Exit:",
                        "!e(", err, ")")
