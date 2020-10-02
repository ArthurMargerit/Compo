#!/bin/env python3
from swig_lib.Components import C1
from swig_lib.Links import Server_simple as ss
from swig_lib.Links import Server_interface as si
from swig_lib.Links import Server_component as sc

c = C1.C1()

# simple server ###############################################################
i_inst = ss.Server_simple()
i_inst.set_in(c.i)

# get / set
i_inst.set_a1(i_inst.get_a1())
i_inst.a_a1().set_cmd(ss.String_d("hello"))
assert(i_inst.a_a1().get_cmd().str == "hello")

i_inst.connect()
for i in range(0, 100):
    i_inst.step()
i_inst.disconnect()

# interface server ############################################################
i_inst = si.Server_interface()
i_inst.set_in("i1", c.i)
i_inst.set_in("i2", c.i)
i_inst.connect()
for i in range(0, 100):
    i_inst.step()
i_inst.disconnect()

# component server ############################################################
c_inst = sc.Server_component()
c_inst.set_in("c1", "i1", c.i)
c_inst.set_in("c1", "i2", c.i)
c_inst.set_in("c2", "i1", c.i)
c_inst.set_in("c2", "i2", c.i)
c_inst.connect()
for i in range(0, 100):
    c_inst.step()
c_inst.disconnect()
