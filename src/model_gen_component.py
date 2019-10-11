
def StoryTeller(main, component, args, log=False):

    pass

def StoryCatcher(main, component, args, log=False):
    
    pass

Gen_component_public = {
    "StoryTeller": None,
    "StoryCatcher": None
}


def component_gen(main, component, gen_func, log=False):

    position = gen_func.find("(")
    func_name = gen_func[0:position]
    func_args = gen_func[position+1:-1].split(",")

    if func_name not in Gen_component_public:
        print(colored("Error:", "red"), "function gen doesn't exist")
        return None

    return Gen_component_public[func_name](main,
                                           component,
                                           func_args,
                                           log)
