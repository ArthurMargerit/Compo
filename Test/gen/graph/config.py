import os

CONFIG = {
    "jinja_template_path":[os.environ["COMPOME_PATH"]+"/generate_model/graph/","."],
    "generation_model": os.environ["COMPOME_PATH"]+"/generate_model/graph/generation.yaml"
}
