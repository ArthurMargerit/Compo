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

l_s3 = s3.s3()
l_s1 = s1.s1()
assert(l_s3.get_b() == l_s1)

# create a copy
l_s3.get_b().set_d3(1)
assert(0 == l_s3.get_b().get_d3())

# modify a value
l_s3.a_b().set_d3(1)
assert(1 == l_s3.get_b().get_d3())
assert(1 == l_s3.a_b().get_d3())

# get // modif // set
c = l_s3.get_b()
c.set_d3(2)
l_s3.set_b(c)
assert(2 == l_s3.get_b().get_d3())
assert(2 == l_s3.a_b().get_d3())
