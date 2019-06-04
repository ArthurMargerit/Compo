#!/usr/bin/env python


from  src.struct.S2 import S2



from src.struct.S1 import S1

from src.struct.S2 import S2





class S3(S2):

    def __init__(self,
                 p_s1 = S1(),p_s2 = S2()):

        "docstring"
        
        super(S3,self).__init__()
        
        OrderedDict([('NAME', 's1'), ('TYPE', OrderedDict([('NAME', 'S1'), ('DATA', [OrderedDict([('NAME', 'a'), ('TYPE', OrderedDict([('NAME', 'int'), ('DEFINITION', 'int'), ('NATIF', True), ('DEFAULT', 0)]))])])]))])
        self.s1 = p_s1
        OrderedDict([('NAME', 's2'), ('TYPE', OrderedDict([('NAME', 'S2'), ('DATA', [OrderedDict([('NAME', 'b'), ('TYPE', OrderedDict([('NAME', 'int'), ('DEFINITION', 'int'), ('NATIF', True), ('DEFAULT', 0)]))])])]))])
        self.s2 = p_s2
        

    def f1():
        return int()

    def f2(a):
        return int()

    def f3(a,b):
        pass

    def f4(a,b):
        return int()

    

    def __str__(self):
        strs = "{"
        
        strs+="PARENT:"+S2.__str__(self)
        
        strs+=","
        
        

        strs+= "s1"
        strs+= ":"
        strs+= str(self.s1)

        strs+= ","

        strs+= "s2"
        strs+= ":"
        strs+= str(self.s2)
        strs+= "}"

        return strs