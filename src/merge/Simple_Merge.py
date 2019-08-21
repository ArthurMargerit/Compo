#!/usr/bin/env python3
from merge.Merge import Merge
import glob
import hashlib
import os
from termcolor import colored

def compute_hash(file_path):
    if os.path.isdir(file_path):
        return "OK"

    with open(file_path) as f:
        l_data = f.read()
        return hashlib.md5(l_data.encode('utf-8')).hexdigest()


def multi_glob(p_list):
    l = []
    for i_list in p_list:
        l = [*l, *glob.glob(i_list, recursive = True)]

    return l

class Simple_Merge(Merge):
    post_kv = {}
    pre_kv = {}

    def __init__(self, p_opt, p_conf):
        Merge.__init__(self, p_opt, p_conf)
        self.post_kv = {}
        self.pre_kv = {}

    def post(self):
        Merge.post(self)
        for g in multi_glob(["**.cpp","**.hpp","**.yaml","**.cmake"]):
            self.post_kv[g] = compute_hash(g)


    def pre(self):
        Merge.pre(self)
        for g in multi_glob(["**.cpp","**.hpp","**.yaml","**.cmake"]):
            self.pre_kv[g] = compute_hash(g)

    def report(self):
        Merge.report(self)
        for i_post in sorted(self.post_kv.keys()):
            if i_post not in self.pre_kv:
                print(">", i_post, "-", colored("NEW", "red"))
            else:
                if self.post_kv[i_post] == self.pre_kv[i_post]:
                    pass
                    #print(">", i_post, "-", colored("UNMODIFIED", "green"))
                else:
                    print(">", i_post, "-", colored("CHANGE", "red"))

                del self.pre_kv[i_post]

        for i_pre in self.pre_kv:
            print(">", i_pre, "-", colored("DELETE", "red"))
