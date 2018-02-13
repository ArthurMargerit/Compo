import re

from jinja2 import Environment,  FileSystemLoader, select_autoescape

class Configuration_manager:
    conf_file_possible="~/gen.conf"


    def get(self, name):
        if name == "include_path":
            return self.get("project_path")+"/include"

        if name == "src_path":
            return self.get("project_path")+"/src"

        if name == "project_path":
            return self.get("source_path")+"/test"

        if name == "source_path":
            return "/home/t0167641/compo"

        if name == "jinja_template_path":
            return self.get("source_path")+"/base"

        assert "error"

    def __init__(self):
        "docstring"




def main():
    conf = Configuration_manager()
    jenv = load_jinja_env(conf)

    dico={"name":"lapin"}
    generate_composant(jenv,conf,dico);


def generate_composant(jenv, configuration, composant_information):

# HPP FILE ####################################################################
    template_hpp = load_template(jenv, "composant.hpp")
    hpp_file_content = template_hpp.render(composant_information);

    hpp_dir = configuration.get("include_path")
    hpp_file_name = composant_information["name"]+".hpp"
    hpp_file_abs_path = hpp_dir +"/"+ hpp_file_name

    with open(hpp_file_abs_path,"w") as file:
        file.write(hpp_file_content)

    print(hpp_file_abs_path+" DONE")

# CPP FILE ####################################################################
    template_cpp = load_template(jenv, "composant.cpp")
    cpp_file_content = template_cpp.render(composant_information);

    cpp_dir = configuration.get("src_path")
    cpp_file_name = composant_information["name"]+".cpp"
    cpp_file_abs_path = cpp_dir +"/" + cpp_file_name

    with open(cpp_file_abs_path,"w") as file:
        file.write(cpp_file_content)
    print(cpp_file_abs_path+" DONE")

def parser():

    with open("../test.txt") as f:

        lines = f.read()
        type_find = re.findall("^TYPE:([\w|\*]+) *([\w|\*]+)\;$",lines, re.MULTILINE)
        print(type_find)

        print(re.DOTALL)
        interface_find = re.findall("^INTERFACE:(\w+) {([\w|\n|\:|\t| |\;|\<|\-|\(|\)|,]*)};$",lines ,re.MULTILINE)
        for inter in interface_find:
            print("="*10)
            print(inter[0])
            print(inter[1])

        composant_find = re.findall("^COMPOSANT:(\w+) {([\w|\n|:|\t| |\;|\<|\-|\(|\)|,]*)};",lines ,re.MULTILINE)

        for comp in composant_find:
            print("="*10)
            print(comp[0])
            print(comp[1])

        dep_find = re.findall("^DEPLOIMENT:(\w+) {([\w|\n|:|\t| |\;|\<|\-|\(|\)|,|\>|\.]*)};", lines, re.MULTILINE)

        for dep in dep_find:
            print("="*10)
            print(dep[0])
            print(dep[1])

def load_jinja_env(conf):
    print(conf.get("jinja_template_path"))
    loader = FileSystemLoader(conf.get("jinja_template_path"))
    env = Environment(loader=loader)
    return env

def load_template(jinja_env, template_name):
    print(template_name)
    return jinja_env.get_template(template_name)




main()
