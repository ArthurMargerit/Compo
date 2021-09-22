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

if "COMPOME_MODEL" not in os.environ:
    print("Error: You have to define COMPOME_MODEL")
    exit(1)

if os.environ["COMPOME_MODEL"] == "GRAPH":
    if "COMPOME_GRAPH_PATH" not in os.environ:
        print("Error: You have to define COMPOME_GRAPH_PATH")
        exit(1)
    COMPOME_GRAPH_PATH = os.environ["COMPOME_GRAPH_PATH"].split(":")

    CONFIG = {
        "migration": "simple",
        "jinja_template_path": [os.environ["COMPOME_PATH"]+"/generate_model/graph/", "."] + COMPOME_GRAPH_PATH,
        "generation_model": os.environ["COMPOME_PATH"]+"/generate_model/graph/generation.yaml",
        "import_path": COMPOME_MODEL_PATH,
        "template_options": {"project": {"name": PROJECT}}
    }

elif os.environ["COMPOME_MODEL"] == "CPP":

    CONFIG = {
        "migration": "",
        "import_path": [".", "model"]+COMPOME_MODEL_PATH,
        "generation_model": COMPOME_PATH+"/generate_model/cpp/generation.yaml",
        "jinja_template_path": [COMPOME_PATH+"/generate_model/cpp/"],
        "template_options": {"project": {"name": PROJECT}}
    }
