#!/bin/env python3

from swig_lib.Errors import s0
from swig_lib.Errors import s1
from swig_lib.Errors import s2


a = s0.s0()

b = s1.s1()
b.set_d1(1)
b.set_d2(2)
b.set_d3(3)

assert(b.get_d1() == 1)
assert(b.get_d2() == 2)
assert(b.get_d3() == 3)

c = s2.s2()
assert(c.get_d1() == 0)
c.set_d1(1)
assert(c.get_d1() == 1)

c.f1()
v1 = c.f2(1)
v2 = c.f3(1, 2)


try:
    a = s0.s0()
    raise a
except Exception:
    print(">>> " , a)
finally:
    print("ok")

try:
    main.get_a_error()
except Exception:
    print(">>> " , a)
finally:
    print("ok")

try:
    main.get_a_error2()
except Exception:
    print(">>> " , a)
finally:
    print("ok")
