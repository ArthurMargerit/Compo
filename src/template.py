# !/usr/bin/env python3


from jinja2 import Environment,  FileSystemLoader, select_autoescape



# def generate_type(jenv, configuration, type_information):
#     pass

def generate_structs(jenv, configuration, information):

    # HPP FILE ################################################################
    template_hpp = load_template(jenv, "structs.hpp")
    hpp_file_content = template_hpp.render(information)

    hpp_dir = configuration.get("include_path")
    hpp_file_name = "structs.hpp"
    hpp_file_abs_path = hpp_dir + "/" + hpp_file_name

    with open(hpp_file_abs_path, "w") as file:
        file.write(hpp_file_content)

    print(hpp_file_abs_path+" DONE")

    # CPP FILE ################################################################
    template_cpp = load_template(jenv, "structs.cpp")
    cpp_file_content = template_cpp.render(information)

    cpp_dir = configuration.get("src_path")
    cpp_file_name = "structs.cpp"
    cpp_file_abs_path = cpp_dir + "/" + cpp_file_name

    with open(cpp_file_abs_path, "w") as file:
        file.write(cpp_file_content)
    print(cpp_file_abs_path+" DONE")



def generate_types(jenv, configuration, information):

    # HPP FILE ################################################################
    template_hpp = load_template(jenv, "types.hpp")
    hpp_file_content = template_hpp.render(information)

    hpp_dir = configuration.get("include_path")
    hpp_file_name = "types.hpp"
    hpp_file_abs_path = hpp_dir + "/" + hpp_file_name

    with open(hpp_file_abs_path, "w") as file:
        file.write(hpp_file_content)

    print(hpp_file_abs_path+" DONE")

def generate_interfaces(jenv, configuration, information):

    for key, value in information["INTERFACES"].items():
        generate_interface(jenv, configuration, information, key, value)



def generate_interface(jenv, configuration, information, name, value):
    # HPP FILE ################################################################
    template_hpp = load_template(jenv, "Facette.hpp")
    hpp_file_content = template_hpp.render({**information,**value})

    hpp_dir = configuration.get("include_path")
    hpp_file_name = name+".hpp"
    hpp_file_abs_path = hpp_dir + "/" + hpp_file_name

    with open(hpp_file_abs_path, "w") as file:
        file.write(hpp_file_content)

    print(hpp_file_abs_path+" DONE")

    # CPP FILE ################################################################
    template_cpp = load_template(jenv, "Facette.cpp")
    cpp_file_content = template_cpp.render({**information,**value})

    cpp_dir = configuration.get("src_path")
    cpp_file_name = name+".cpp"
    cpp_file_abs_path = cpp_dir + "/" + cpp_file_name

    with open(cpp_file_abs_path, "w") as file:
        file.write(cpp_file_content)
    print(cpp_file_abs_path+" DONE")


def generate_abstract_interface(jenv, configuration, composant_information):
    pass

def generate_deploiment(jenv, configuration, deploiment_information):
    pass


def generate_composant(jenv, configuration, composant_information):

    # HPP FILE ################################################################
    template_hpp = load_template(jenv, "composant.hpp")
    hpp_file_content = template_hpp.render(composant_information)

    hpp_dir = configuration.get("include_path")
    hpp_file_name = composant_information["name"]+".hpp"
    hpp_file_abs_path = hpp_dir + "/" + hpp_file_name

    with open(hpp_file_abs_path, "w") as file:
        file.write(hpp_file_content)

    print(hpp_file_abs_path+" DONE")

    # CPP FILE ################################################################
    template_cpp = load_template(jenv, "composant.cpp")
    cpp_file_content = template_cpp.render(composant_information)

    cpp_dir = configuration.get("src_path")
    cpp_file_name = composant_information["name"]+".cpp"
    cpp_file_abs_path = cpp_dir + "/" + cpp_file_name

    with open(cpp_file_abs_path, "w") as file:
        file.write(cpp_file_content)
    print(cpp_file_abs_path+" DONE")


def load_jinja_env(conf):
    print(conf.get("jinja_template_path"))
    loader = FileSystemLoader(conf.get("jinja_template_path"))
    env = Environment(loader=loader)
    return env


def load_template(jinja_env, template_name):
    print(template_name)
    return jinja_env.get_template(template_name)
