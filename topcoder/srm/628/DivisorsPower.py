def check(y, p):
    q, f = 0, 1
    while f ** 2 < y:
        if y % f == 0:
            q += 2
        f += 1
    return q + (f ** 2 == y) == p

class DivisorsPower(object):
    def findArgument(_, x):
        ans, p = -1, 2
        while True:
            y = int(round(x ** (1.0 / p)))
            if y < 2:
                break
            if y ** p == x and check(y, p):
                ans = y
            p += 1
        return ans
