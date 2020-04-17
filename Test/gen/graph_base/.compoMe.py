import os

CONFIG = {
    "migration": "simple",
    "jinja_template_path": [os.environ["COMPOME_PATH"]+"/generate_model/graph/", "."],
    "generation_model": os.environ["COMPOME_PATH"]+"/generate_model/graph/generation.yaml",
    "import_path": ["."],
    "template_options": {"project": {"name": "test"}}
}
