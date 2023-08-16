#!/usr/bin/env python
import yaml
from Config import Configuration_manager
import os

import importlib
from tools import If
from Compo_cache import Cache
from tools.Selector import range_inteligent_selector
from termcolor import colored
from jinja2 import Template, Environment,  FileSystemLoader
from helper import include_helper, color

from tools.Log import ERR

import model_test
import model_get
import re
import hashlib
from jinja2 import nodes
from jinja2.ext import Extension


class CompoJinja_Env (Environment):

    def __init__(self, **args):
        "docstring"
        super().__init__(**args)

    def _parse(self, source, name, filename):
        """Internal parsing function used by `parse` and `compile`."""
        self.hash_parse_table[name] = hashlib.md5(source.encode('utf-8')).hexdigest()
        return super()._parse(source, name, filename)

    def reset_hash(self, **data):
        self.hash_parse_table = {}


def load_jinja_env(conf):
    loader = FileSystemLoader(conf.get("jinja_template_path"))
    env = CompoJinja_Env(loader=loader)
    return env


def load_template(jinja_env, template_name):
    jinja_env.reset_hash()
    return jinja_env.get_template(template_name)


def load_template_file_rec(model_path, ret):

    with open(model_path) as model_file:
        model_data = yaml.load(model_file, Loader=yaml.SafeLoader)

    for one_model_entry in model_data:
        if "NAME" in one_model_entry:
            ret.append(one_model_entry)
        elif "INCLUDE" in one_model_entry:
            f = os.path.dirname(model_path) + "/" + one_model_entry["INCLUDE"]
            load_template_file_rec(f, ret)


def load_template_file(model_path):
    ret = []
    load_template_file_rec(model_path, ret)
    return ret


def generate_match(match, elem):
    m = re.match(match, elem)
    return m is not None


def generate_all_entry(model_file, jenv, args, conf, model_path, generation_data,
                       target=".*", log=False, no_cache=False):

    from command import get_ignore
    cache = Cache(None) if no_cache else Cache(".Compo_Cache")

    model_data = load_template_file(model_path+"/"+model_file)
    ret = []
    for one_model_entry in model_data:
        get_all_file(one_model_entry,
                     generation_data,
                     ignore=get_ignore(args, conf, "LIB"),
                     ret=ret,
                     target=target)
    Configuration_manager.get_conf().set("generator_info.files", ret, True)

    for one_model_entry in model_data:
        generate_one_entry(jenv, args, conf, one_model_entry,
                           generation_data,
                           target=target,
                           ignore=get_ignore(args, conf, "GEN"),
                           log=log,
                           cache=cache)

    cache.export()


def generate_model(jenv, args, conf, generation_data,
                   target=".*", log=False, no_cache=False):

    path = os.path.dirname(conf.get("generation_model"))
    file_name = os.path.basename(conf.get("generation_model"))
    generate_all_entry(file_name, jenv, args, conf, path,
                       generation_data,
                       target=target,
                       log=log,
                       no_cache=no_cache)


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


def contain_f(str):
    return lambda x: str in x


def myfilter(f, d):
    return list(filter(f, d))


def get_Function_tool():
    data = {
        "t_import": importlib.import_module,
        "model_get": model_get,
        "model_test": model_test,
        "include_helper": include_helper,
        "os": os,
        "zip": zip,
        "filter": myfilter,
        "contain_f": contain_f,
        "color": color.node_color
    }

    return {"Function": data}


def get_config_option():
    data = {
        "options": Configuration_manager.get_conf().get("template_options"),
        "generator": Configuration_manager.get_conf().get("generator_info")
    }

    return data


def default_model_expand(path, data):

    selectors = path.split(".")

    d = data
    for selector in selectors:
        if selector in d:
            d = d[selector]
        else:
            ERR(selector, " n'est pas dispo.")
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


def generate_one_entry(jenv, args, conf, model_data, generation_data, target=".*", ignore=None,
                       log=False, cache=None):
    log_msg = colored(model_data["NAME"], 'green') + "->" + "\n"

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

        log_msg += "\t" + "> " + m + "\n"

        use_cache = 1
        for file in model_data["FILES"]:

            in_file = Template(file["IN"]).render(data)
            out_file = Template(file["OUT"]).render(data)

            log_msg += "\t"*2 + in_file + " -> " + out_file

            os.makedirs(os.path.dirname(out_file), exist_ok=True)

            data_hash = hashlib.md5(str(target_i).encode('utf-8')).hexdigest()

            # same result
            result = load_template(jenv, in_file).render(data)
            result_hash = hashlib.md5(result.encode('utf-8')).hexdigest()

            if cache.valid(out_file, {**jenv.hash_parse_table, "data": data_hash, "result": result_hash}):
                log_msg += " : Cache\n"
            else:
                log_msg += " : Generate\n"
                use_cache = 0
                with open(out_file, 'w') as f:
                    f.write(result)

                cache.insert(out_file, {**jenv.hash_parse_table, "data": data_hash, "result": result_hash})

        if "COMMANDS" in model_data and use_cache == 0:
            for cmd in model_data["COMMANDS"]:
                cmd_t = Template(cmd).render(data)
                log_msg += "\t"*2 + colored("$", 'red') + colored(cmd_t, 'yellow') + "\n"

                err = os.system(cmd_t)
                if err != 0:
                    ERR("Command ",
                        ">", cmd_t, "<",
                        "\n Exit:",
                        "!e(", err, ")")
        if use_cache == 0:
            print(log_msg)


def get_all_file(model_data, generation_data, ignore=None, ret=[], target=".*"):

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

        for file in model_data["FILES"]:
            out_file = Template(file["OUT"]).render(data)
            ret.append(out_file)
