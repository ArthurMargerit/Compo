import os

if "COMPOME_PATH" not in os.environ:
    print("Error: You have to define COMPOME_PATH")
    exit(1)

if "COMPOME_MODEL_PATH" not in os.environ:
    print("Error: You have to define COMPOME_MODEL_PATH")
    exit(1)

if "COMPOME_GRAPH_PATH" not in os.environ:
    print("Error: You have to define COMPOME_GRAPH_PATH")
    exit(1)

COMPOME_PATH = os.environ["COMPOME_PATH"]
COMPOME_MODEL_PATH = os.environ["COMPOME_MODEL_PATH"].split(":")
COMPOME_GRAPH_PATH = os.environ["COMPOME_GRAPH_PATH"].split(":")
PROJECT = os.path.basename(os.environ["PWD"])

CONFIG = {
    "migration": "simple",
    "jinja_template_path": [os.environ["COMPOME_PATH"]+"/generate_model/graph/", "."] + COMPOME_GRAPH_PATH,
    "generation_model": os.environ["COMPOME_PATH"]+"/generate_model/graph/generation.yaml",
    "import_path": COMPOME_MODEL_PATH,
    "template_options": {"project": {"name": PROJECT}}
}
