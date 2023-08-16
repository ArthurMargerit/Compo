import os

if "COMPOME_PATH" not in os.environ:
    print("Error: You have to define COMPOME_PATH")
    exit(1)

if "COMPOME_MODEL_PATH" not in os.environ:
    print("Error: You have to define COMPOME_MODEL_PATH")
    exit(1)

COMPOME_PATH = os.environ["COMPOME_PATH"]
compome_model_path = os.environ["COMPOME_MODEL_PATH"].split(":")

COMPOME_MODEL_PATH = compome_model_path
PROJECT = os.path.basename(os.environ["PWD"])

CONFIG = {
    "migration": "",
    "import_path": [".", "model"]+COMPOME_MODEL_PATH,
    "generation_model": COMPOME_PATH+"/generate_model/cpp/generation.yaml",
    "jinja_template_path": [COMPOME_PATH+"/generate_model/cpp/"],
    "template_options": {"project": {"name": PROJECT}}
}

print(COMPOME_MODEL_PATH)
