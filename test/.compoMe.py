import os

HOME = os.environ["HOME"]
COMPO_PATH = os.environ["COMPO_PATH"] if "COMPO_PATH" in os.environ else (HOME+"/p/compo")

CONFIG = {
    "template_options":{"project":{"name": "test"}},
    "migration": "",
    "target": ".*\..*",
    "target_file": None,
    "import_path": [".",
                    COMPO_PATH+"/lib_model/BASE",
                    COMPO_PATH+"/lib_model/BASE_LINK",
                    COMPO_PATH+"/lib_model/BASE_STRUCT"],
    "generation_model": COMPO_PATH+"/generate_model/CPP/out2.yaml",
    "jinja_template_path": [COMPO_PATH+"/generate_model/CPP/", os.environ["PWD"]]
}
