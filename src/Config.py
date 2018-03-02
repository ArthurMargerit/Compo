
class Configuration_manager:

    conf_file_possible = "~/gen.conf"

    def __init__(self):
        "docstring"

    def get(self, name):
        if name == "include_path":
            return self.get("project_path")+"/include"

        if name == "src_path":
            return self.get("project_path")+"/src"

        if name == "project_path":
            return self.get("source_path")+"/test"

        if name == "source_path":
            return "/home/ruhtra/compo2"

        if name == "jinja_template_path":
            return self.get("source_path")+"/base"

        assert "error"
