import os

CONFIG = {
    "migration": "",
    "jinja_template_path": [os.environ["COMPOME_PATH"] + "/generate_model/cpp", "."],
    "generation_model": os.environ["COMPOME_PATH"] + "/generate_model/cpp/generation.yaml",
    "import_path": ["."],
    "template_options": {"project": {"name": "test"}}
}
