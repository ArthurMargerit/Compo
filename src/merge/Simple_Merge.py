#!/usr/bin/env python3
from merge.Merge import Merge
import glob
import hashlib
import os
import shutil
import tempfile
from tools.Log import DEBUG, ERR, INFO
from termcolor import colored
FILE_TO_MERGE = ["src/**/*.cpp", "inc/**/*.hpp", "**.yaml", "**.cmake"]


def compute_hash(file_path):
    if os.path.isdir(file_path):
        return "OK"

    with open(file_path) as f:
        l_data = f.read()
        return hashlib.md5(l_data.encode('utf-8')).hexdigest()


def multi_glob(p_list):
    l_m = []
    for i_list in p_list:
        l_m = [*l_m, *glob.glob(i_list, recursive=True)]

    return l_m


class Simple_Merge(Merge):
    post_kv = {}
    pre_kv = {}

    def __init__(self, p_opt, p_conf):
        Merge.__init__(self, p_opt, p_conf)
        self.post_kv = {}
        self.pre_kv = {}

    def post(self):
        Merge.post(self)
        for g in multi_glob(FILE_TO_MERGE):
            self.post_kv[g] = compute_hash(g)

    def pre(self):
        Merge.pre(self)
        self.a_tmpdir = tempfile.mkdtemp()
        l_obj = multi_glob(FILE_TO_MERGE)

        for i_g in l_obj:
            DEBUG("copy of !y(", i_g, ")")
            l_d = os.path.dirname(i_g)

            if l_d != "" and not os.path.exists(self.a_tmpdir+"/"+l_d):
                os.makedirs(self.a_tmpdir+"/"+l_d)
            shutil.copy(i_g, self.a_tmpdir+"/"+i_g)

            self.pre_kv[i_g] = compute_hash(i_g)

    def on_mod(self, p_post):
        INFO("> ", p_post, " - !r(MOD)")
        shutil.copy(self.a_tmpdir+"/"+p_post, p_post+".old")

    def on_new(self, p_post):
        INFO("> ", p_post, "- !r(NEW)")

    def on_del(self, p_pre):
        INFO("> ", p_pre, " - !r(DELETE)")

    def report(self):
        Merge.report(self)
        for i_post in sorted(self.post_kv.keys()):
            if i_post not in self.pre_kv:
                self.on_new(i_post)
            else:
                if self.post_kv[i_post] == self.pre_kv[i_post]:
                    pass

                else:
                    self.on_mod(i_post)

                del self.pre_kv[i_post]

        for i_pre in self.pre_kv:
            self.on_del(i_pre)
