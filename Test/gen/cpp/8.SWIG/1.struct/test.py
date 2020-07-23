#!/bin/env python3
from swig_lib.Structs import s0
from swig_lib.Structs import s1
from swig_lib.Structs import s2
from swig_lib.Structs import s3

l_s0 = s0.s0()
l_s1 = s1.s1()
l_s2 = s2.s2()
l_s3 = s3.s3()

print(l_s0)
print(l_s1)
print(l_s2)
print(l_s3)

print(l_s0.this)
print(l_s1.this)
print(l_s2.this)
print(l_s3.this)

del l_s0
del l_s1
del l_s2
del l_s3

l_s0 = s0.s0()
l_s1 = s1.s1(1, 2, 3)
l_s2 = s2.s2(4)
l_s3 = s3.s3(l_s0.this, l_s1.this, l_s2.this)

l_s1.set_d1(1)
l_s1.set_d2(1)
l_s1.set_d3(1)

l_s1.get_d1()
l_s1.get_d1()
l_s1.get_d1()

l_s1.set_d1(1)
l_s1.set_d2(1)
l_s1.set_d3(1)

l_s1.get_d1()
l_s1.get_d1()
l_s1.get_d1()

print(l_s0)
print(l_s1)
print(l_s2)
print(l_s3)


del l_s0
del l_s1
del l_s2
del l_s3
