#!/bin/env python3

from swig_lib.Components import C1
from swig_lib.Components import C2
from swig_lib.Components import C3


def basic_test(c):
    c.configuration()
    c.connection()
    c.start()
    for i in range(0, 100):
        c.step()

    c.stop()

basic_test(C1.C1())
basic_test(C2.C2())
basic_test(C3.C3())


a = C3.C3()
b = a.get_p()
b.f1(1)
b.f2()
b.f3()

c2 = C2.C2()
assert (not c2.r.connected())

c2.r.set_i(b)
assert (c2.r.connected())

c2.r.set_i(None)
assert (not c2.r.connected())

c2.r.set_i(b)
assert (c2.r.connected())

c2.r.get().f1(1)
c2.r.get().f2()
c2.r.get().f3()

c2.ping()
assert (c2.get_a() == 0)
for i in range(1, 100):
    c2.set_a(i)
    assert (c2.get_a() == i)

print(c2)

c1 = C1.C1()
print(c1)
