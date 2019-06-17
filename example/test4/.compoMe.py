import os

if "COMPOME_PATH" not in os.environ:
    print("Error: You have to define COMPOME_PATH")
    exit(1)

COMPOME_PATH = os.environ["COMPOME_PATH"]


CONFIG = {
    "migration": "",

    "import_path": ["."],

    "generation_model": COMPOME_PATH + "/generate_model/cpp/generation.yaml",

    "jinja_template_path": [COMPOME_PATH+"/generate_model/cpp/"],

    "template_options":{"project":{"name":"Base"}}
}
