#!/usr/bin/env python3
# Copyright (C) Arthur MARGERIT - All Rights Reserved
#
# Unauthorized copying of this file, via any medium is strictly prohibited

# This file is confidential and only available to authorized individuals with the
# permission of the copyright holders.  If you encounter this file and do not have
# permission, please contact the copyright holders and delete this file.
#
# Written by Arthur MARGERIT ruhtra.mar@gmail.com, 2018

import argparse
from command import COMMANDS_MAP
from tools.Log import ERR, Verbose_option


def parser():
    parser = argparse.ArgumentParser(description="""Cette commande rassemble les commandes suivantes
    un exemple d'utilisation simple
    $ compo generate -f model.yaml
    """)

    subparsers = parser.add_subparsers(dest="command")

    # find ####################################################################
    # find = subparsers.add_parser('find', help="find a element")
    # find.add_argument('TYPE')
    # find.add_argument('NAME')
    # find.add_argument("-f", "--files", nargs="*", type=str)
    # find.add_argument("-b", "--bdd", nargs="*", type=str)

    # test ####################################################################
    # test = subparsers.add_parser('test', help="run test")
    # test_sub_parser = test.add_subparsers(dest="test_name")
    # model_test = test_sub_parser.add_parser("model")
    # model_test.add_argument("file")

    # graphical ###############################################################
    # graphical = subparsers.add_parser('graphical',
    #                                   help="run graphical interface TODO")

    # graphical.add_argument("-f", "--file", nargs="*", type=str, default=[])
    # graphical.add_argument("-b", "--bdd", nargs="*", type=str, default=[])

    # shell ###################################################################
    shell = subparsers.add_parser('shell', help="run a shell interface TODO")
    shell.add_argument("-f", "--file", nargs="*")

    # expand ##################################################################
    expand = subparsers.add_parser('expand', help="expand a file to BDD")
    expand.add_argument("files", nargs="*", type=str)

    # generate ################################################################
    generate = subparsers.add_parser('generate', help="generate the code")
    generate.add_argument("-f", "--file", nargs="*", type=str)
    generate.add_argument("-m", "--merge", default=None, type=str)
    generate.add_argument("-t", "--target", default=None, type=str)
    generate.add_argument("-i", "--ignore", default=None, type=str)

    generate.add_argument('--no-ignore', dest='no_ignore',
                          action='store_const', const=True,
                          default=False,
                          help='ignore .ignore file and --ignore option')

    # Standart option #########################################################
    parser.add_argument("-v", "--verbose", default=0,
                        type=int,
                        help="Increase output verbosity")

    parser.add_argument("-c", "--config",
                        default="~/.config/compo2",
                        type=str,
                        help="Set the config file")

    return parser.parse_args()


def command_call(args):
    Verbose_option.set_level(args.verbose)

    if not hasattr(args, "command"):
        ERR("No command set \n $compo COMMAND")

    cmd = args.command
    if cmd not in COMMANDS_MAP:
        ERR("This command is not valid, use one of: ",
            ", ".join(["!y("+f+")" for f in COMMANDS_MAP.keys()]))

    function = COMMANDS_MAP[cmd]
    function(args)


def main():
    args = parser()
    command_call(args)


if __name__ == '__main__':
    main()
