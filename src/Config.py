
import os.path
from tools.Log import ERR
import imp
from tools import Selector


class Configuration_manager:
    conf = None
    conf_file_possible = ["/etc/compoMe.py",
                          "~/.config/compoMe.py",
                          ".compoMe.py"]

    CONF_data = {}

    def get_conf():
        if Configuration_manager.conf is None:
            Configuration_manager.conf = Configuration_manager()
        return Configuration_manager.conf

    def __init__(self):
        "configugarion layer"
        self.CONF_data = {}
        for one_conf in self.conf_file_possible:
            one_conf = os.path.expanduser(one_conf)
            conf = self.load_config_file(one_conf)

            self.CONF_data = {**(self.CONF_data), **(conf)}

        if self.CONF_data == {}:
            print("NO CONFIGURATION FILE:", ", ".join(self.conf_file_possible))

    def get(self, name):

        if name in self.CONF_data:
            return self.CONF_data[name]

        # default values
        if name == "include_path":
            return self.get("project_path")+"/include"

        if name == "src_path":
            return self.get("project_path")+"/src"

        if name == "import_path":
            return []

        if name == "target":
            return ".*"

        if name == "ignore":
            return None

        if name == "merge":
            return "simple"

        if name == "target_file":
            return "target.list"

        if name == "ignore_file":
            return "ignore.list"

        if name == "project_path":
            return self.get("source_path")+"/test"

        if name == "source_path":
            return os.path.expanduser("~/compo")

        if name == "jinja_template_path":
            return self.get("source_path")+"/generate_model/graphviz"

        assert "Not in Config"

    def load_pars_conf(self, arg):
        pass

    def exist(self, key,):
        return key in self.CONF_data

    def set(self, key, value):
        ks = key.split(".")
        i_d = self.CONF_data
        for i_ks in ks:
            if i_ks not in i_d:
                ERR("wrong selector ", key)
                return

            if i_ks == ks[-1]:
                i_d[i_ks] = value
            else:
                i_d = i_d[i_ks]

    def load_config_file(self, path):
        if os.path.isfile(path):
            try:
                filepy = imp.load_source("a", path)
                if hasattr(filepy, "CONFIG"):
                    return filepy.CONFIG
                else:
                    return {}
            except Exception as a:
                ERR("configuration", path, a)

        else:
            return {}
