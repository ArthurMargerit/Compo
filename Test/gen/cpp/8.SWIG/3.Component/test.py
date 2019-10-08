#!/bin/env python3



import C1
import C2
import C3

def basic_test(c):
    c.configuration()
    c.connection()
    c.start()

    for i in range(0,100):
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
