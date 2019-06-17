import os

HOME = os.environ["HOME"]
COMPO_PATH = os.environ["COMPO_PATH"] if "COMPO_PATH" in os.environ else (HOME+"/p/compo")

CONFIG = {
    "template_options":{"project":{"name": "test2"}},
    "migration": "",
    "target": ".*\..*",
    "target_file": None,
    "import_path": [".",
                    COMPO_PATH+"/Compome_cpp/BASE",
                    COMPO_PATH+"/Compome_cpp/BASE_LINK",
                    COMPO_PATH+"/Compome_cpp/BASE_TYPES",
                    COMPO_PATH+"/Compome_cpp/BASE_STRUCT"],
    "generation_model": COMPO_PATH+"/generate_model/cpp/generation.yaml",
    "jinja_template_path": [COMPO_PATH+"/generate_model/cpp/", os.environ["PWD"]]
}
