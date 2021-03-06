from Config import Configuration_manager

def options_expand(kind, data):
    l_def_glb_opt = Configuration_manager.get_conf().get("OPTIONS.ALL")
    l_def_spe_opt = Configuration_manager.get_conf().get("OPTIONS."+kind)
    return {**l_def_spe_opt, **l_def_spe_opt, **data}
