#!/usr/bin/env python


from src.struct.Struct import Struct








class S2(Struct):

    def __init__(self,
                 p_b = 0):

        "docstring"
        
        OrderedDict([('NAME', 'b'), ('TYPE', OrderedDict([('NAME', 'int'), ('DEFINITION', 'int'), ('NATIF', True), ('DEFAULT', 0)]))])
        self.b = p_b
        

    

    def __str__(self):
        strs = "{"
        

        strs+= "b"
        strs+= ":"
        strs+= str(self.b)
        strs+= "}"

        return strs