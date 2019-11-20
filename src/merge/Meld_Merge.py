#!/usr/bin/env python3

from merge.Simple_Merge import Simple_Merge
import os
from tools.Log import DEBUG, ERR, INFO


class Meld_Merge(Simple_Merge):

    def on_mod(self, p_post):
        Simple_Merge.on_mod(self, p_post)
        os.system("dbus-launch meld " + p_post + " " + p_post + ".old &")

    def on_new(self, p_post):
        Simple_Merge.on_new(self, p_post)

    def on_del(self, p_pre):
        Simple_Merge.on_del(self, p_pre)
