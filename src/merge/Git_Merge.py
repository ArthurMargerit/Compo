#!/usr/bin/env python3
from merge.Merge import Merge
import git


def get_branch(p_c):
    return p_c.name_rev.split(" ")[1].split("~")[0]


def have_branch(repo, name):
    return name in [b.name for b in repo.branches]


class Git_Merge(Merge):

    def Create_arch_branch(i_branch):
        pass

    def __init__(self, p_opt, p_conf):
        Merge.__init__(self, p_opt, p_conf)
        self.repo = git.Repo(".")
        i_branch = self.repo.head.ref.name

        if "ARCHI" not in i_branch:
            if not have_branch(self.repo, i_branch+"-ARCHI"):
                self.repo.create_head("ARCHI")

    def post(self):
        Merge.post(self)
        self.repo.git.add(".")
        self.repo.index.commit("ARCHI-"+self.prev_branch)
        self.repo.git.checkout(self.prev_branch)
        self.repo.git.merge("ARCHI")

    def pre(self):
        Merge.pre(self)
        self.prev_branch = self.repo.head.ref.name
        self.repo.git.checkout("ARCHI")

    def report(self):
        Merge.report(self)
