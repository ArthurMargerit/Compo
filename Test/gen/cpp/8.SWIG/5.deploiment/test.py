#!/bin/env python3

from swig_lib.Deployments import D1

my_d = D1.D1()
my_d.init()
my_d.configuration()
my_d.link()
my_d.start()
my_d.step()
my_d.stop()
