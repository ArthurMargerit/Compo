#!/usr/bin/env python3
from merge.Merge import Merge
import git
from tools.Log import ERR

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

    def post(self):
        Merge.post(self)
        self.repo.git.add(".")
        self.repo.index.commit("add ARCHI "+self.prev_branch)
        self.repo.git.checkout(self.prev_branch)
        self.repo.git.merge(self.prev_branch+"-ARCHI")

    def pre(self):
        Merge.pre(self)

        self.prev_branch = self.repo.head.ref.name
        if "ARCHI" in self.prev_branch:
            ERR("You need to switch to a non arch branch first")

        if "ARCHI" not in self.prev_branch:
            if not have_branch(self.repo, self.prev_branch+"-ARCHI"):
                self.repo.create_head(self.prev_branch+"-ARCHI")

        self.repo.git.checkout(self.prev_branch+"-ARCHI")

    def report(self):
        Merge.report(self)
