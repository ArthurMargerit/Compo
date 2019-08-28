import os

CONFIG = {
    "jinja_template_path": os.environ["COMPOME_PATH"]+"/generate_model/cpp",
    "generation_model": os.environ["COMPOME_PATH"]+"/generate_model/cpp/generation.yaml"
}
