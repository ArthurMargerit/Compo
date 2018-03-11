import Config
#import template
import model_expand as model
import sys


def main():
    conf = Config.-Configuration_manager()
        jenv = template.load_jinja_env(conf)
    data = model.file_expand(None, sys.argv[1])

    template.generate_all(jenv, conf, data)

"command path"
if __name__ == '__main__':
    main()
