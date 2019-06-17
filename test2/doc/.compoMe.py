import os

HOME = os.environ["HOME"]
COMPO_PATH = os.environ["COMPO_PATH"] if "COMPO_PATH" in os.environ else (HOME+"/p/compo")

CONFIG = {
    "template_options":{"project":{"name": "test2"}},
    "migration": "",
    "target": ".*\..*",
    "target_file": None,
    "import_path": [".",
                    COMPO_PATH+"/lib_model/CPP/BASE",
                    COMPO_PATH+"/lib_model/CPP/BASE_LINK",
                    COMPO_PATH+"/lib_model/CPP/BASE_TYPES",
                    COMPO_PATH+"/lib_model/CPP/BASE_STRUCT"],
    "generation_model": COMPO_PATH+"/generate_model/graphviz/out.yaml",
    "jinja_template_path": [COMPO_PATH+"/generate_model/graphviz/", os.environ["PWD"]]
}
