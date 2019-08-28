import os

CONFIG = {
    "jinja_template_path": os.environ["COMPOME_PATH"]+"/generate_model/uml",
    "generation_model": os.environ["COMPOME_PATH"]+"/generate_model/uml/generation.yaml"
}
