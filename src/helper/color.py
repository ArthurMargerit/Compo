import hashlib


def color(p_str):
    l_h = hashlib.md5(p_str.encode("utf-8")).hexdigest()
    l_R = int(l_h[0:2], 16)
    l_G = int(l_h[2:4], 16)
    l_B = int(l_h[4:6], 16)
    return [l_R,l_G,l_B]


def mix(p_color1, p_color2, p_factor):
    l_R = p_color1[0] + (p_color2[0]- p_color1[0]) * p_factor
    l_G = p_color1[1] + (p_color2[1]- p_color1[1]) * p_factor
    l_B = p_color1[2] + (p_color2[2]- p_color1[2]) * p_factor

    return [int(l_R),int(l_G),int(l_B)]

def color_str(p_color):
    return "#%02x%02x%02x" % tuple(p_color)


def node_color_rec(p_name, p_color, p_parent):

    if p_color and p_color != "":
        return p_color

    par_color = None

    if p_parent and p_parent != "":
        l_col = p_parent["COLOR"] if "COLOR" in p_parent else None
        l_par = p_parent["PARENT"] if "PARENT" in p_parent else None

        par_col = node_color_rec(p_parent["NAME"], l_col, l_par)
    else:
        par_col = [0XFF,0XFF,0XFF]

    col = color(p_name)
    mix_col = mix(par_col, col, 0.3)

    return mix_col



def node_color(p_name, p_color, p_parent):
    return color_str(node_color_rec(p_name, p_color, p_parent))
