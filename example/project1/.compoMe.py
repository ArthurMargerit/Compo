HOME = "/home/g179923/p"
LIB_PATH = HOME+"/compo/lib_model/CPP"
CONFIG = {
#    "migration": "git",
    "import_path": [".",LIB_PATH+"/BASE",LIB_PATH+"/BASE_TYPES",LIB_PATH+"/BASE_LINK"],
    "generation_model": HOME+"/compo/generate_model/CPP/out2.yaml",
    "jinja_template_path": [HOME+"/compo/generate_model/CPP/"],
    "template_options":{"project":{"name":"temperature_sensors"}}
}
