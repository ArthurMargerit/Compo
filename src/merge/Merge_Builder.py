#!/usr/bin/env python3

from merge.Git_Merge import Git_Merge
from merge.Manual_Merge import Manual_Merge
from merge.Simple_Merge import Simple_Merge

from tools.Log import ERR

_list_merge_system = {
    "git": Git_Merge,
    "simple": Simple_Merge,
    "manual": Manual_Merge
}


def get_merge_system(p_type, p_opt, p_arg):
    if p_type not in _list_merge_system:
        ERR(p_type,
            " not in merge system: ",
            ["!y("+m+")" for m in _list_merge_system.keys()])
        return Simple_Merge(p_opt, p_arg)

    return _list_merge_system[p_type](p_opt, p_arg)
