f = lambda x: (x - x % 3) / 3 + (x % 3 == 2)

class PowerOfThree(object):
    def ableToGet(self, x, y):
        return 'Possible' if x == y == 0 else 'Impossible' if bool(x % 3) == bool(y % 3) else self.ableToGet(f(x), f(y))
