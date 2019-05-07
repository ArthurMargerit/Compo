#!/usr/bin/env python


from src.struct.Struct import Struct














class Log_s(Struct):

    def __init__(self,
                 p_type_log = Log_e(),p_message = UNDEF,p_file = UNDEF,p_line = 0,p_module_type = UNDEF,p_module_name = UNDEF,p_function_name = UNDEF):

        "docstring"
        
        self.type_log = p_type_log
        self.message = p_message
        self.file = p_file
        self.line = p_line
        self.module_type = p_module_type
        self.module_name = p_module_name
        self.function_name = p_function_name
        

    def print(p):
        pass

    

    def __str__(self):
        strs = "{"
        

        strs+= "type_log"
        strs+= ":"
        strs+= str(self.type_log)

        strs+= ","

        strs+= "message"
        strs+= ":"
        strs+= str(self.message)

        strs+= ","

        strs+= "file"
        strs+= ":"
        strs+= str(self.file)

        strs+= ","

        strs+= "line"
        strs+= ":"
        strs+= str(self.line)

        strs+= ","

        strs+= "module_type"
        strs+= ":"
        strs+= str(self.module_type)

        strs+= ","

        strs+= "module_name"
        strs+= ":"
        strs+= str(self.module_name)

        strs+= ","

        strs+= "function_name"
        strs+= ":"
        strs+= str(self.function_name)
        strs+= "}"

        return strs