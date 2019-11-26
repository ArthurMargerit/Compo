from tools.Log import WARN

UPLETTER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LETTER = "abcdefghijklmnopqrstuvwxyz"
NUMBER = "1234567890"
INVALID_START_CHAR = NUMBER
VALID_CHAR = "_" + NUMBER + UPLETTER + LETTER


def is_valid_name(name):
    if name[0] in INVALID_START_CHAR:
        WARN(name[0],
             " is not valid for first letter of !y(",
             name, ")")

    for i_n in name:
        if i_n not in VALID_CHAR:
            WARN(i_n, " is not valid")
