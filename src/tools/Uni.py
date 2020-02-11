
class Uni:
    def __init__(self):
        self.Uni = {}

    def check(self, s):
        if s in self.Uni:
            return False
        else:
            self.Uni[s] = 1
            return True

    def checks(self, s):
        for i_s in s:
            if not self.check(i_s):
                return False, i_s

        return True, None
