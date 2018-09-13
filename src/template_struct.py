from template import load_template, SEP
from termcolor import colored
# def generate_type(jenv, configuration, type_information):
#     pass
def generate_structs(jenv, configuration, information):

    # HPP FILE ################################################################
    template_hpp = load_template(jenv, "structs.hpp")
    hpp_file_content = template_hpp.render(information)

    hpp_dir = configuration.get("include_path") 
    hpp_file_name = "structs.hpp"
    hpp_file_abs_path = hpp_dir + SEP + hpp_file_name

    with open(hpp_file_abs_path, "w") as file:
        file.write(hpp_file_content)

    print(hpp_file_abs_path, "DONE")

    # CPP FILE ################################################################
    template_cpp = load_template(jenv, "structs.cpp")
    cpp_file_content = template_cpp.render(information)

    cpp_dir = configuration.get("src_path")
    cpp_file_name = "structs.cpp"
    cpp_file_abs_path = cpp_dir + SEP + cpp_file_name

    with open(cpp_file_abs_path, "w") as file:
        file.write(cpp_file_content)
    print(cpp_file_abs_path, "DONE")


def generate_struct(jenv, configuration, information):

    # HPP FILE ################################################################
    template_hpp = load_template(jenv, "Data/Struct_template.hpp")
    hpp_file_content = template_hpp.render(information)

    hpp_dir = configuration.get("include_path")
    hpp_file_name = information["NAME"]+".hpp"
    hpp_file_abs_path = hpp_dir + SEP + "Data" + SEP + hpp_file_name

    with open(hpp_file_abs_path, "w") as file:
        file.write(hpp_file_content)

    print(hpp_file_abs_path, colored("DONE", "green"))

    # CPP FILE ################################################################
    template_cpp = load_template(jenv, "Data/Struct_templates.cpp")
    cpp_file_content = template_cpp.render(information)

    cpp_dir = configuration.get("src_path")
    cpp_file_name = "structs.cpp"
    cpp_file_abs_path = cpp_dir + SEP + cpp_file_name

    with open(cpp_file_abs_path, "w") as file:
        file.write(cpp_file_content)
    print(cpp_file_abs_path, "DONE")

