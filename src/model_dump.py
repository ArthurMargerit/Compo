from yaml import dump
from yaml import Dumper
import sys


import yaml
import collections

_mapping_tag = yaml.resolver.BaseResolver.DEFAULT_MAPPING_TAG

def dict_representer(dumper, data):
    return dumper.represent_dict(data.items())

def dict_constructor(loader, node):
    return collections.OrderedDict(loader.construct_pairs(node))

yaml.add_representer(collections.OrderedDict, dict_representer)
yaml.add_constructor(_mapping_tag, dict_constructor)


def model_dump(data,name_file):


    with open(name_file, "w") as f:
        f.write(yaml.dump(data, default_flow_style=False))
