import os

HOME = os.environ["HOME"]
COMPO_PATH = os.environ["COMPO_PATH"] if "COMPO_PATH" in os.environ else (HOME+"/p/compo")

MODEL="CPP"
if "COMPOME_MODEL" in os.environ and os.environ["COMPOME_MODEL"]:
    MODEL = os.environ["COMPOME_MODEL"]
else:
    MODEL = "CPP"

CONFIG = {
    "migration": "",
    "target": "*",
    "target_file": None,
    "generation_model": COMPO_PATH+"/generate_model/"+MODEL+"/out.yaml",
    "jinja_template_path": [COMPO_PATH+"/generate_model/"+MODEL+"/", os.environ["PWD"]]
}
