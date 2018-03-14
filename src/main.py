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
    parser = argparse.ArgumentParser()
    parser.add_argument("add", help="increase output verbosity",
                    action="store_true")
    parser.add_argument("-v", "--verbose", help="increase output verbosity",
                    action="store_true")
    args = parser.parse_args()



"command path"
if __name__ == '__main__':
    parser()
    
    #main()
