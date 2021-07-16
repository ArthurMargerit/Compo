#!/bin/env python3
from swig_lib.Components import C1
from swig_lib.Links import Server_simple as ss
from swig_lib.Links import Server_interface as si
from swig_lib.Links import Server_component as sc

c = C1.C1()

# simple server ###############################################################
i_inst = ss.Server_simple()
i_inst.get_i1().connect_interface(c.i)

# get / set
i_inst.set_a1(i_inst.get_a1())
i_inst.a_a1().set_cmd(ss.String_d("hello"))
assert(i_inst.a_a1().get_cmd().str == "hello")

i_inst.main_connect()
for i in range(0, 100):
    i_inst.step()
i_inst.main_disconnect()

# interface server ############################################################
i_inst = si.Server_interface()
i_inst.get_i1().connect_interface(ss.String_d("i1"), c.i)
i_inst.get_i1().connect_interface(ss.String_d("i2"), c.i)
i_inst.main_connect()
for i in range(0, 100):
    i_inst.step()
i_inst.main_disconnect()

# component server ############################################################
c_inst = sc.Server_component()
c_inst.get_i1().connect_interface(ss.String_d("c1"), ss.String_d("i1"), c.i)
c_inst.get_i1().connect_interface(ss.String_d("c1"), ss.String_d("i2"), c.i)
c_inst.get_i1().connect_interface(ss.String_d("c2"), ss.String_d("i1"), c.i)
c_inst.get_i1().connect_interface(ss.String_d("c2"), ss.String_d("i2"), c.i)
c_inst.main_connect()
for i in range(0, 100):
    c_inst.step()
c_inst.main_disconnect()
