import model_expand as model
import helper.color as ColorMe
from model_parsing_context import *
from tools.Log import ERR, INFO, WARN, colorify

from model_utils import print_me
from merge import Merge_Builder

import Config
import template_gen

import os


def find_command_call(args):
    file = args.files
    # bdd = args.bdd

    data = model.file_expand(None, None, file[0])

    if args.TYPE not in data:
        ERR("TYPE disponible:", data.keys())
        return

    type_section = data[args.TYPE]
    if args.NAME not in type_section:
        ERR("NAME disponible:", type_section.keys())
        return

    element = type_section[args.NAME]

    print_me(args.NAME, element)


def shell_command_call(args):
    file = args.file
    ctx = context_create(".")
    data = model.file_expand(ctx, None, file[0])

    exit = False
    while exit is False:
        start = "- "
        lines = []
        while True:
            try:
                print(start, end="")
                line = input()
                if line:
                    lines.append(start + line)
                    start = "  "
                else:
                    break
            except EOFError:
                return None

        text = '\n'.join(lines).replace("\t", "  ")
        try:
            model.str_expand(ctx, data, text)
        except Exception as e:
            print("is not a valid insertion \n", colorify(str(e)))

def get_target(p_args, p_config):

    if p_args.target is not None:
        return p_args.target
    else:
        r_target = get_target_list(p_config)
        if r_target is None:
            return p_config.get("target")
        else:
            return "|".join(r_target)


def get_ignore(p_args, p_config, p_mode = "ALL"):

    if p_args.no_ignore is True:
        return None

    if p_args.ignore is not None:
        return p_args.ignore
    else:
        r_ignore = get_ignore_list(p_config)
        if r_ignore is None:
            return None

        p = [r_i for r_i in r_ignore if not("GEN:" in r_i or "LIB:" in r_i)]
        p_gen = [*p,*[r_i.split("GEN:")[1] for r_i in r_ignore if "GEN:" in r_i]]
        p_lib = [*p,*[r_i.split("LIB:")[1] for r_i in r_ignore if "LIB:" in r_i]]

        if p_mode == "ALL":
            return "|".join(p)
        if p_mode == "GEN":
            return None if len(p_gen) == 0 else "|".join(p_gen)

        if p_mode == "LIB":
            return None if len(p_lib) == 0 else "|".join(p_lib)


def get_merge(p_args, p_config):

    if p_args.merge is not None:
        return p_args.merge

    return p_config.get("merge")


def get_target_list(p_config):
    r_target_paths = p_config.get("target_file")

    # if isinstance(r_target_paths, list):
    #     r_targets = []
    #     for i_target_path in r_target_paths:
    #         if not os.path.exists(i_target_path):
    #             WARN(" No target file: !y(", i_target_path, ")")
    #             continue

    #         with open(i_target_path) as l_f:
    #             l_tar = l_f.read().split("\n")
    #             r_targets = [*r_targets, *l_tar]

    #     return r_targets

    if isinstance(r_target_paths, str):
        if not os.path.exists(r_target_paths):
            WARN(" No target file: !y(", r_target_paths, ")")
            return None

        with open(r_target_paths) as l_f:
            l_tar = l_f.read().split("\n")
            r_targets = l_tar

    return r_targets

def get_ignore_list(p_config):
    r_ignore_paths = p_config.get("ignore_file")
    if isinstance(r_ignore_paths, str):
        if not os.path.exists(r_ignore_paths):
            WARN(" No ignore file: !y(", r_ignore_paths, ")")
            return None

        with open(r_ignore_paths) as l_f:
            l_tar = l_f.read().split("\n")
            r_ignores = l_tar

        return r_ignores

    return None


def generate_command_call(args):
    file = args.file
    conf = Config.Configuration_manager.get_conf()

    target = get_target(args, conf)
    merge = get_merge(args, conf)

    INFO("target: ", target)
    INFO("merge: ", merge)

    jenv = template_gen.load_jinja_env(conf)
    data = model.file_expand(None, None, file[0])
    l_merge = Merge_Builder.get_merge_system(merge, None, None)

    l_merge.pre()
    template_gen.generate_model(jenv, args, conf, data, target=target, log=True)
    l_merge.post()
    l_merge.report()


def TODO_command_call(args):
    ERR("TODO: this function is not done, do you want to do it ?")


def expand_command_call(arg):
    files = arg.files
    data = model.file_expand(None, None, files[0])


COMMANDS_MAP = {
    "generate": generate_command_call,
    "expand": expand_command_call,
    "shell": shell_command_call
}
