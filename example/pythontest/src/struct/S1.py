#!/usr/bin/env python


from src.struct.Struct import Struct








class S1(Struct):

    def __init__(self,
                 p_a = 0):

        "docstring"
        
        OrderedDict([('NAME', 'a'), ('TYPE', OrderedDict([('NAME', 'int'), ('DEFINITION', 'int'), ('NATIF', True), ('DEFAULT', 0)]))])
        self.a = p_a
        

    

    def __str__(self):
        strs = "{"
        

        strs+= "a"
        strs+= ":"
        strs+= str(self.a)
        strs+= "}"

        return strs