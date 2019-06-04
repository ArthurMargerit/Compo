#!/usr/bin/env python3

import argparse
from command import COMMANDS_MAP


def parser():
    parser = argparse.ArgumentParser(description="""Cette commande rassemble les commandes suivantes
    un exemple d'utilisation simple
    $ compo generate -f model.yaml
    """)

    subparsers = parser.add_subparsers(dest="command")

    # find ####################################################################
    find = subparsers.add_parser('find', help="find a element")
    find.add_argument('TYPE')
    find.add_argument('NAME')
    find.add_argument("-f", "--files", nargs="*", type=str)
    find.add_argument("-b", "--bdd", nargs="*", type=str)

    # test ####################################################################
    test = subparsers.add_parser('test',
                                 help="run test")

    test_sub_parser = test.add_subparsers(dest="test_name")
    model_test = test_sub_parser.add_parser("model")
    model_test.add_argument("file")

    # graphical ###############################################################
    graphical = subparsers.add_parser('graphical',
                                      help="run graphical interface TODO")

    graphical.add_argument("-f", "--file", nargs="*", type=str, default=[])
    graphical.add_argument("-b", "--bdd", nargs="*", type=str, default=[])

    # shell ###################################################################
    shell = subparsers.add_parser('shell',
                                  help="run a shell interface TODO")

    shell.add_argument("-f", "--file", nargs="*")
    shell.add_argument("-b", "--bdd", nargs="*")

    # expand ##################################################################
    expand = subparsers.add_parser('expand',
                                   help="expand a file to BDD")

    expand.add_argument("files", nargs="*", type=str)
    expand.add_argument("BDD", type=str, default="compobdd.yaml")

    # generate ################################################################
    generate = subparsers.add_parser('generate',
                                     help="generate the source code")
    generate.add_argument("-f", "--file", nargs="*", type=str)
    generate.add_argument("-t","--target", default=".*", type=str)

    # Standart option #########################################################
    parser.add_argument("-v",
                        "--verbose",
                        default=0,
                        type=int,
                        help="Increase output verbosity")

    parser.add_argument("-c", "--config",
                        type=str,
                        default="~/.config/compo2",
                        help="Set the config file")

    return parser.parse_args()


def command_call(args):

    if hasattr(args, "command"):
        cmd = args.command
        if cmd in COMMANDS_MAP:
            function = COMMANDS_MAP[cmd]
            function(args)

        else:
            print("This command is not valid, use one of this one:",
                  COMMANDS_MAP.keys())

    else:
        print("No command set \n $compo COMMAND")


def main():
    args = parser()

    command_call(args)


if __name__ == '__main__':
    main()
