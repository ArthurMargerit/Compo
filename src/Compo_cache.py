#!/usr/bin/env
import yaml
import os

DEFAULT_CACHE_ENTRY = {"outputs": {}}


class Cache:

    def __init__(self, file_cache):
        """
        Keyword Arguments:
        file_cache -- a yaml file that store cache
        """
        self.file_cache_ori = file_cache

        if file_cache is None or not os.path.exists(file_cache):
            print("...NO CACHE...")
            self.cache_story = DEFAULT_CACHE_ENTRY
            return

        with open(file_cache, "r") as f:
            self.cache_story = yaml.load(f, Loader=yaml.SafeLoader)

    def exist(self, output_name):
        return output_name in self.cache_story["outputs"]

    def valid(self, output_name, e_hash):
        return self.exist(output_name) and self.cache_story["outputs"][output_name] == e_hash

    def export(self, output_path=None):
        if self.file_cache_ori is None:
            return

        with open(self.file_cache_ori if output_path is None else output_path, "w") as f:
            f.write(yaml.dump(self.cache_story))

    def insert(self, output_name, e_hash):
        self.cache_story["outputs"][output_name] = e_hash
