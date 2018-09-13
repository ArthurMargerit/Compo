
class Uni:
    def __init__(self):
        self.Uni = {}

    def check(self, s):
        if s in self.Uni:
            return False
        else:
            self.Uni[s] = 1
            return True
