#!/usr/bin/env python3

import Config
import template
import model_expand as model
import sys

import argparse

def main():
    conf = Config.Configuration_manager()
    jenv = template.load_jinja_env(conf)
    data = model.file_expand(None, sys.argv[1])

    template.generate_all(jenv, conf, data)



def parser():
    parser = argparse.ArgumentParser(description=
                                     """Cette commande rassemble les commandes suivantes
                                     un exemple d'utilisation simple
                                     $ compo generate -f model.yaml
                                     """)
    subparsers = parser.add_subparsers()

    # find ####################################################################
    find = subparsers.add_parser('find',
                                     help="find a element")
    find.add_argument('TYPE')
    find.add_argument('NAME')

    # test ####################################################################
    test = subparsers.add_parser('test',
                                 help="run test")
    test.add_argument('test',default=["all"])

    # graphical ###############################################################
    graphical = subparsers.add_parser('graphical',
                                      help="run graphical interface TODO")

    expand.add_argument("-f", "--file", nargs="*")
    expand.add_argument("-b", "--bdd", nargs="*")

    # shell ###################################################################
    shell = subparsers.add_parser('shell',
                                  help="run a shell interface TODO")

    expand.add_argument("-f", "--file", nargs="*")
    expand.add_argument("-b", "--bdd", nargs="*")

    # expand ##################################################################
    expand = subparsers.add_parser('expand',
                                   help="expand a file to BDD")

    expand.add_argument("file",nargs="*")

    # generate ################################################################
    generate = subparsers.add_parser('generate',
                                     help="generate the source code")
    expand.add_argument("-f", "--file", nargs="*")
    expand.add_argument("-b", "--bdd", nargs="*")
    expand.add_argument("-m", "--merge")
    expand.add_argument("--to")
    expand.add_argument("--what",nargs="*")

    # Standart option #########################################################
    parser.add_argument("-v",
                        "--verbose",
                        help="Increase output verbosity")

    parser.add_argument("-c", "--config",
                        type=int,
                        default=0,
                        help="Set the config file" )


    args = parser.parse_args()



"command path"
if __name__ == '__main__':
    parser()
    
    #main()
