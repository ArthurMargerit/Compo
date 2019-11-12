from termcolor import colored as co


class Verbose_option:
    level = 0

    def set_level(p_level):
        Verbose_option.level = p_level


COLORMAP = {
    "r": "red",
    "g": "green",
    "y": "yellow",
    "b": "blue",
    "e": "red",
    "w": "yellow",
    "i": "green",
    "d": "blue"}


def colorify(mess):
    ret = mess.find("!")
    if ret == -1:
        return mess
    else:
        color = COLORMAP[mess[ret+1]]
        left = mess[0:ret]
        center = mess[ret:mess.find(")")+1]
        right = mess[mess.find(")")+1:]

        k = center[center.find("(")+1:center.find(")")]

        return left + co(k, color) + colorify(right)


def ERR(*mess):
    # deactivate
    if Verbose_option.level == -1:
        return

    mess = [str(m) for m in mess]
    print(colorify("!e(Error): " + "".join(mess)))
    exit(-1)


def WARN(*mess):
    if Verbose_option.level < 1:
        return

    mess = [str(m) for m in mess]
    print(colorify("!w(Warning): " + "".join(mess)))


def INFO(*mess):
    if Verbose_option.level < 2:
        return

    mess = [str(m) for m in mess]
    print(colorify("!i(Info): " + "".join(mess)))


def DEBUG(*mess):
    if Verbose_option.level < 3:
        return

    mess = [str(m) for m in mess]
    print(colorify("!d(Debug): " + "".join(mess)))
