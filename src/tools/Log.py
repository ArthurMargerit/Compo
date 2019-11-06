from termcolor import colored as co

COLORMAP = {
    "r": "red",
    "g": "green",
    "y": "yellow",
    "b": "blue",
    "e": "red",
    "w": "yellow",
    "i": "green",
    "d": "debug"}


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
    mess = [str(m) for m in mess]
    print(colorify("!e(Error): " + "".join(mess)))


def WARN(mess):
    mess = [str(m) for m in mess]
    print(colorify("!w(Warning): " + "".join(mess)))


def INFO(mess):
    mess = [str(m) for m in mess]
    print(colorify("!i(Info): " + "".join(mess)))


def INFO(mess):
    mess = [str(m) for m in mess]
    print(colorify("!d(Debug): " + "".join(mess)))
