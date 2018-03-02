import Config
#import template
import model_expand as model
import sys


def main():
    conf = Config.Configuration_manager()
#    jenv = template.load_jinja_env(conf)
    data = model.file_expand(main, sys.argv[1])
    print(data)
    # template.generate_types(jenv, conf, data)
    # template.generate_structs(jenv, conf, data)
    # template.generate_interfaces(jenv, conf, data)
    # template.generate_composants(jenv, conf, data)
    # template.generate_deploiments(jenv, conf, data)

#    generate_composant(jenv,conf,dico);

#    generate_type(jenv,conf,dico);


if __name__ == '__main__':
    main()
