#!/usr/bin/env python3

from swig_lib.Interfaces import I1
import swig_lib.I1_i as myI
import swig_lib.CompoMe.Tools.Call as c
import swig_lib.Links.CompoMe.Posix.Udp_server_in as usi
import swig_lib.Links.CompoMe.Posix.Udp_client_out as uco
from multiprocessing import Pool

i1 = myI.I1_i()
i1_cs = i1.get_caller_stream()

r = c.call(i1_cs, "f1(0)")

for e in range(1, 100):
    r = c.call(i1_cs, "f1("+str(e)+")")
    assert(r[1] == str(e+1))

map_i = c.map_Caller_stream({"a": i1_cs,
                             "b": i1_cs})

r = c.call(map_i, "a.f1(1)")
r = c.call(map_i, "b.f1(2)")

map_map_i = c.map_map_Caller_stream({"c1": map_i,
                                     "c2": map_i})
r = c.call(map_map_i, "c1.a.f1(3)")
r = c.call(map_map_i, "c1.b.f1(4)")
r = c.call(map_map_i, "c2.a.f1(5)")
r = c.call(map_map_i, "c2.b.f1(6)")


def client_f():
    caller = I1.require_I1()
    client = uco.Udp_client_out()
    client.set_addr(uco.String_d("127.0.0.1"))
    client.set_port(8085)
    client.set_out(caller)
    client.connect()
    for i in range(0, 100):
        v1 = caller.get().f1(i)
    return v1


p = Pool(3)
t1 = p.apply_async(client_f)
t2 = p.apply_async(client_f)
t3 = p.apply_async(client_f)

server = usi.Udp_server_in()
server.set_addr(uco.String_d("127.0.0.1"))
server.set_port(8085)
server.set_in(i1)
server.connect()
while not t1.ready() and not t2.ready() and not t3.ready():
    server.step()
server.disconnect()

p.close()
p.join()
