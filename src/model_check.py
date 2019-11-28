from tools.Log import WARN, ERR

UPLETTER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LETTER = "abcdefghijklmnopqrstuvwxyz"
NUMBER = "1234567890"
INVALID_START_CHAR = NUMBER
VALID_CHAR = "_" + NUMBER + UPLETTER + LETTER

PROHIBITED_LIST = ["public", "private", "function"]
PROHIBITED_START = ["l_", "r_", "p_", "__"]


def is_valid_name(name):
    if name in PROHIBITED_LIST:
        ERR("!y(", name, ") is a prohibited name.")

    if name[0:2] in PROHIBITED_START:
        ERR("!y(", name, ") have a prohibited start !y(", name[0:2], ")")

    if name[0] in INVALID_START_CHAR:
        ERR("!y(", name[0], ") is not valid for first letter of !y(",
            name, ")")

    for i_n in name:
        if i_n not in VALID_CHAR:
            ERR(i_n, " is not valid")
