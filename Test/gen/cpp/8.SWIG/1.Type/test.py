#!/bin/env python3
from swig_lib.Structs import S1
from swig_lib.Structs import S2

from swig_lib.Structs.S2 import String_d as s


a = S1.S1()
a.set_a(-1)
assert (a.get_a() == -1)

a.set_a(0)
assert(a.get_a() == 0)

a.set_a(1)
assert(a.get_a() == 1)

a1 = S1.S1()
a2 = S1.S1()
assert (a1 == a2)

a1.set_a(1)
assert (a1 != a2)
a1.set_a(a1.get_a()+1)


a = S2.S2()
v = a.f1()
st = s("lapin")
a.f2(1)
a.f3(1,2,3)
a.f4(1,2,3)
t = a.f5(st)
assert (t.str == "")
